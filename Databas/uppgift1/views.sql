-- 1, den gjorde vi redan klart korrekt
CREATE VIEW BasicInformation AS
SELECT
    s.idnr,
    s.name,
    s.login,
    s.program,
    sb.branch
FROM Students AS s
LEFT JOIN StudentBranches AS sb
    ON s.idnr = sb.student;


-- 2
CREATE VIEW FinishedCourses AS
SELECT
    t.student,
    t.course,
    c.name AS "courseName",
    t.grade,
    c.credits
FROM Taken AS t
JOIN Courses AS c
    ON t.course = c.code;


-- 3
CREATE VIEW Registrations AS

SELECT
    student,
    course,
    'registered' AS status
FROM Registered

UNION ALL

SELECT
    student,
    course,
    'waiting' AS status
FROM WaitingList;

--4
--CREATE VIEW PassedCourses AS
--SELECT t.student, t.course, c.credits
--FROM Taken AS t
--JOIN Courses AS c
 --   ON t.course = c.code
--WHERE t.grade <> 'U';
-- den funkar med men vi har redan skapat en view med alla finished courses så 'from' den är smidigare

--helper
CREATE VIEW PassedCourses AS
SELECT
    student,
    course,
    credits
FROM FinishedCourses
WHERE grade <> 'U';  -- <> är !=

--helper
CREATE VIEW UnreadMandatory AS
SELECT
    m.student,
    m.course
FROM (
    -- Mandatory courses for the student's program
    SELECT
        s.idnr AS student,
        mp.course
    FROM Students AS s
    JOIN MandatoryProgram AS mp
        ON s.program = mp.program
    
    UNION --
    -- Mandatory courses for the student's branch
    SELECT
        sb.student,
        mb.course
    FROM StudentBranches AS sb
    JOIN MandatoryBranch AS mb
        ON sb.branch = mb.branch
        AND sb.program = mb.program

) AS m
-- Remove mandatory courses already passed
WHERE NOT EXISTS (
    SELECT "placeholder" -- vill inte ha nåt härifrån, bara veta om det finns >0 rows där detta stämmer
    FROM PassedCourses AS pc
    WHERE pc.student = m.student
      AND pc.course = m.course
);

--helper
CREATE VIEW RecommendedCourses AS
SELECT
    sb.student,
    pc.course,
    pc.credits
FROM StudentBranches AS sb
JOIN RecommendedBranch AS rb
    ON sb.branch = rb.branch
    AND sb.program = rb.program
JOIN PassedCourses AS pc
    ON sb.student = pc.student
    AND rb.course = pc.course;

-- 4. PATH TO GRADUATION
CREATE VIEW PathToGraduation (
    student,
    "totalCredits",
    "mandatoryLeft",
    "mathCredits",
    "seminarCourses",
    qualified
) AS
SELECT
    s.idnr AS student,
    -- Total credits from passed courses
    COALESCE(tc.totalCredits, 0),
    -- Number of mandatory courses not passed
    COALESCE(ml.mandatoryLeft, 0),
    -- Credits from mathematical courses
    COALESCE(mc.mathCredits, 0),
    -- Number of passed seminar courses
    COALESCE(sc.seminarCourses, 0),
    -- Graduation requirements
    (
        sb.student IS NOT NULL
        AND COALESCE(ml.mandatoryLeft, 0) = 0
        AND COALESCE(rc.recommendedCredits, 0) >= 10
        AND COALESCE(mc.mathCredits, 0) >= 20
        AND COALESCE(sc.seminarCourses, 0) >= 1
    ) AS qualified
    
FROM Students AS
-- Total credits
LEFT JOIN (
    SELECT
        student,
        SUM(credits) AS totalCredits
    FROM PassedCourses
    GROUP BY student
) AS tc
    ON s.idnr = tc.student
-- Mandatory courses remaining
LEFT JOIN (
    SELECT
        student,
        COUNT(*) AS mandatoryLeft
    FROM UnreadMandatory
    GROUP BY student
) AS ml
    ON s.idnr = ml.student
-- Mathematical credits
LEFT JOIN (
    SELECT
        pc.student,
        SUM(pc.credits) AS mathCredits
    FROM PassedCourses AS pc
    JOIN Classified AS cl
        ON pc.course = cl.course
    WHERE LOWER(cl.classification) = 'math'
    GROUP BY pc.student
) AS mc
    ON s.idnr = mc.student
-- Passed seminar courses
LEFT JOIN (
    SELECT
        pc.student,
        COUNT(*) AS seminarCourses
    FROM PassedCourses AS pc
    JOIN Classified AS cl
        ON pc.course = cl.course
    WHERE LOWER(cl.classification) = 'seminar'
    GROUP BY pc.student
) AS sc
    ON s.idnr = sc.student
-- Recommended credits
LEFT JOIN (
    SELECT
        student,
        SUM(credits) AS recommendedCredits
    FROM RecommendedCourses
    GROUP BY student
) AS rc
    ON s.idnr = rc.student;

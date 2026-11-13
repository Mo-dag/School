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
CREATE VIEW PassedCourses AS
SELECT t.student, t.course, c.credits
FROM Taken AS t
JOIN Courses AS c
    ON t.course = c.code
WHERE t.grade <> 'U';


-- yeah den va fan big as fuck, den gör vi imon,
-- ba instruktionerna i sig va enorma o hade massa tips för steg o "hints" i sig

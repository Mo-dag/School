CREATE VIEW BasicInformation AS
SELECT s.idnr, s.name, s.login, s.program, SB.branch
FROM Students AS S
LEFT JOIN StudentBranches AS SB 
ON S.idnr = SB.student;

CREATE VIEW FinishedCourses AS
SELECT S.student, S.course, S.courseName, S.grade, S.credits
FROM Students AS S
LEFT JOIN 

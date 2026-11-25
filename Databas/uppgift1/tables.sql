-- Students
CREATE TABLE Students (
    idnr CHAR(10),//NOT NULL behövs inte för primary key. 
    name TEXT NOT NULL,
    login TEXT NOT NULL,
    program CHAR(7) NOT NULL,

    PRIMARY KEY (idnr),

    CHECK (btrim(idnr) ~ '^[0-9]{10}$')
    -- så som jag uppfattar det måste vi ha med denna checken för 
    -- Students.idnr och också för Courses.Code fast där då 
    -- med A-Za-z0-9 iställetför bara 0-9
);


-- Branches
CREATE TABLE Branches (
    name TEXT,
    program CHAR(7),

    PRIMARY KEY (name, program)
);


-- Courses
CREATE TABLE Courses (
    code CHAR(6),
    name TEXT NOT NULL,
    credits NUMERIC NOT NULL,
    department TEXT NOT NULL,

    PRIMARY KEY (code),

    CHECK (btrim(code) ~ '^[A-Za-z0-9]{6}$'),
    CHECK (credits > 0)
);


-- LimitedCourses
CREATE TABLE LimitedCourses (
    code CHAR(6),
    capacity INT NOT NULL,

    PRIMARY KEY (code),

    FOREIGN KEY (code) REFERENCES Courses(code),

    CHECK (capacity >= 0)
);


-- StudentBranches
CREATE TABLE StudentBranches (
    student CHAR(10),
    branch TEXT NOT NULL,
    program CHAR(7) NOT NULL,

    PRIMARY KEY (student),

    FOREIGN KEY (student) REFERENCES Students(idnr),
    FOREIGN KEY (branch, program)
        REFERENCES Branches(name, program)
);


-- Classifications
CREATE TABLE Classifications (
    name TEXT,

    PRIMARY KEY (name)
);


-- Classified
CREATE TABLE Classified (
    course CHAR(6),
    classification TEXT NOT NULL,

    PRIMARY KEY (course, classification),

    FOREIGN KEY (course) REFERENCES Courses(code),
    FOREIGN KEY (classification) REFERENCES Classifications(name)
);


-- MandatoryProgram
CREATE TABLE MandatoryProgram (
    course CHAR(6) ,
    program CHAR(7) ,

    PRIMARY KEY (course, program),

    FOREIGN KEY (course) REFERENCES Courses(code)
);


-- MandatoryBranch
CREATE TABLE MandatoryBranch (
    course CHAR(6) ,
    branch TEXT ,
    program CHAR(7) ,

    PRIMARY KEY (course, branch, program),

    FOREIGN KEY (course) REFERENCES Courses(code),
    FOREIGN KEY (branch, program)
        REFERENCES Branches(name, program)
);


-- RecommendedBranch
CREATE TABLE RecommendedBranch (
    course CHAR(6) ,
    branch TEXT ,
    program CHAR(7) ,

    PRIMARY KEY (course, branch, program),

    FOREIGN KEY (course) REFERENCES Courses(code),
    FOREIGN KEY (branch, program)
        REFERENCES Branches(name, program)
);


-- Registered
CREATE TABLE Registered (
    student CHAR(10),
    course CHAR(6),

    PRIMARY KEY (student, course),

    FOREIGN KEY (student) REFERENCES Students(idnr),
    FOREIGN KEY (course) REFERENCES Courses(code)
);


-- Taken
CREATE TABLE Taken (
    student CHAR(10) ,
    course CHAR(6),
    grade CHAR(1) NOT NULL,

    PRIMARY KEY (student, course),

    FOREIGN KEY (student) REFERENCES Students(idnr),
    FOREIGN KEY (course) REFERENCES Courses(code),

    CHECK (grade IN ('U', '3', '4', '5'))
);


-- WaitingList
CREATE TABLE WaitingList (
    student CHAR(10),
    course CHAR(6),
    position INT NOT NULL,

    PRIMARY KEY (student, course),

    FOREIGN KEY (student) REFERENCES Students(idnr),
    FOREIGN KEY (course) REFERENCES LimitedCourses(code),

    CHECK (position > 0)
);

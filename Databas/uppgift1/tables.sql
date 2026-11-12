CREATE TABLE Students(
    idnr CHAR(10), 
    name TEXT NOT NULL, 
    login TEXT NOT NULL, 
    program CHAR(7) NOT NULL,
    PRIMARY KEY (idnr)
);

CREATE TABLE Branches (
    name TEXT,
    program CHAR(7),
    PRIMARY KEY (name, program)
);

CREATE TABLE Courses (
    code CHAR(6), 
    name TEXT NOT NULL, 
    credits NUMERIC NOT NULL, 
    department TEXT NOT NULL,
    PRIMARY KEY (code)
);

CREATE TABLE LimitedCourses(
    code CHAR(6),
    capacity INT NOT NULL,
    PRIMARY KEY (code),
    FOREIGN KEY (code) REFERENCES Courses(code)
);

CREATE TABLE StudentBranches(
    student CHAR(10),
    branch TEXT NOT NULL,
    program CHAR(7) NOT NULL,
    PRIMARY KEY (student),
    FOREIGN KEY (student) REFERENCES Students(idnr),
    FOREIGN KEY (branch, program) REFERENCES Branches(name, program)

);

CREATE TABLE Classifications(
    name TEXT,
    PRIMARY KEY(name)
);

CREATE TABLE Classified(
    course CHAR(6), 
    classification TEXT,
    PRIMARY KEY (course, classification),
    FOREIGN KEY (course) REFERENCES Courses(code),
    FOREIGN KEY (classification) REFERENCES Classifications(name)
);
 
CREATE TABLE MandatoryProgram(
    course CHAR(6), 
    program CHAR(7),
    PRIMARY KEY (course, program),
    FOREIGN KEY (course) REFERENCES Courses(code)
);

CREATE TABLE MandatoryBranch(
    course CHAR(6), 
    branch TEXT,
    program CHAR(7),
    PRIMARY KEY (course, branch, program),
    FOREIGN KEY (course) REFERENCES Courses(code),
    FOREIGN KEY (branch, program) REFERENCES Branches(name, program)
);

CREATE TABLE RecommendedBranch(
    course CHAR(6), 
    branch TEXT,
    program CHAR(7),
    PRIMARY KEY (course, branch, program),
    FOREIGN KEY (course) REFERENCES Courses(code),
    FOREIGN KEY (branch, program) REFERENCES Branches(name, program)
);

CREATE TABLE Registered(
    student CHAR(10),
    course CHAR(6), 
    PRIMARY KEY (student, course),
    FOREIGN KEY (student) REFERENCES Students(idnr),
    FOREIGN KEY (course) REFERENCES Courses(code)
);

CREATE TABLE Taken(
    student CHAR(10),
    course CHAR(6), 
    grade CHAR(1) NOT NULL,
    PRIMARY KEY (student, course),
    FOREIGN KEY (student) REFERENCES Students(idnr),
    FOREIGN KEY (course) REFERENCES Courses(code)
);

-- position is the absolute position (an integer)
CREATE TABLE WaitingList(
    student CHAR(10),
    course CHAR(6), 
    position INT NOT NULL,
    PRIMARY KEY (student, course),
    FOREIGN KEY (student) REFERENCES Students(idnr),
    FOREIGN KEY (course) REFERENCES LimitedCourses(code)
);
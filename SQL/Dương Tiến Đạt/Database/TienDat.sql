-- Tạo cơ sở dữ liệu TienDat
CREATE DATABASE TienDat;
-- Sử dụng cơ sở dữ liệu TienDat
USE TienDat;
GO

-- Tạo bảng Students
CREATE TABLE Students (
    StudentID INT PRIMARY KEY, -- Khóa chính
    FirstName VARCHAR(255), -- Tên
    LastName VARCHAR(255), -- Họ
    BirthDate DATE, -- Ngày sinh
    Gender CHAR(1) -- Giới tính (M: Nam, F: Nữ)
);

-- Tạo bảng Classes
CREATE TABLE Classes (
    ClassID INT PRIMARY KEY, -- Khóa chính
    ClassName VARCHAR(255), -- Tên lớp học
    StartDate DATE, -- Ngày bắt đầu học
    EndDate DATE -- Ngày kết thúc học
);

-- Tạo bảng Enrollments
CREATE TABLE Enrollments (
    EnrollmentID INT PRIMARY KEY, -- Khóa chính
    StudentID INT FOREIGN KEY REFERENCES Students(StudentID), -- Khóa ngoại tham chiếu đến bảng Students
    ClassID INT FOREIGN KEY REFERENCES Classes(ClassID), -- Khóa ngoại tham chiếu đến bảng Classes
    EnrollmentDate DATE -- Ngày ghi danh vào lớp học
);
-- Tạo bảng Subjects
CREATE TABLE Subjects (
    SubjectID INT PRIMARY KEY, -- Khóa chính
    SubjectName VARCHAR(255) -- Tên môn học
);

-- Tạo bảng ClassSubjects
CREATE TABLE ClassSubjects (
    ClassSubjectID INT PRIMARY KEY, -- Khóa chính
    ClassID INT FOREIGN KEY REFERENCES Classes(ClassID), -- Khóa ngoại tham chiếu đến bảng Classes
    SubjectID INT FOREIGN KEY REFERENCES Subjects(SubjectID) -- Khóa ngoại tham chiếu đến bảng Subjects
);

-- Tạo bảng Grades
CREATE TABLE Grades (
    GradeID INT PRIMARY KEY, -- Khóa chính
    EnrollmentID INT FOREIGN KEY REFERENCES Enrollments(EnrollmentID), -- Khóa ngoại tham chiếu đến bảng Enrollments
    SubjectID INT FOREIGN KEY REFERENCES Subjects(SubjectID), -- Khóa ngoại tham chiếu đến bảng Subjects
    Grade FLOAT -- Điểm số
);

-- Chèn dữ liệu vào bảng Students
INSERT INTO Students (StudentID, FirstName, LastName, BirthDate, Gender)
VALUES (1, 'John', 'Doe', '2000-01-01', 'M'), -- Thêm sinh viên John Doe
       (2, 'Jane', 'Doe', '2000-02-02', 'F'), -- Thêm sinh viên Jane Doe
	   (3, 'Alice', 'Smith', '2000-03-03', 'F'), -- Thêm sinh viên Alice Smith
       (4, 'Bob', 'Johnson', '2000-04-04', 'M'); -- Thêm sinh viên Bob Johnson

-- Chèn dữ liệu vào bảng Classes
INSERT INTO Classes (ClassID, ClassName, StartDate, EndDate)
VALUES (1, 'Math 101', '2023-09-01', '2023-12-31'), -- Thêm lớp học Math 101
       (2, 'English 101', '2023-09-01', '2023-12-31'); -- Thêm lớp học English 101

-- Chèn dữ liệu vào bảng Enrollments
INSERT INTO Enrollments (EnrollmentID, StudentID, ClassID, EnrollmentDate)
VALUES (1, 1, 1, GETDATE()), -- Ghi danh sinh viên John Doe vào lớp học Math 101
       (2, 2, 2, GETDATE()), -- Ghi danh sinh viên Jane Doe vào lớp học English 101
	   (3, 3, 1, GETDATE()), -- Ghi danh sinh viên Alice Smith vào lớp học Math 101
       (4, 4, 2, GETDATE()); -- Ghi danh sinh viên Bob Johnson vào lớp học English 101

-- Chèn dữ liệu vào bảng Subjects
INSERT INTO Subjects (SubjectID, SubjectName)
VALUES (1, 'Calculus'), -- Thêm môn học Calculus
       (2, 'Algebra'), -- Thêm môn học Algebra
       (3, 'Literature'), -- Thêm môn học Literature
       (4, 'Grammar'); -- Thêm môn học Grammar

-- Chèn dữ liệu vào bảng ClassSubjects
INSERT INTO ClassSubjects (ClassSubjectID, ClassID, SubjectID)
VALUES (1, 1, 1), -- Thêm môn học Calculus vào lớp học Math 101
       (2, 1, 2), -- Thêm môn học Algebra vào lớp học Math 101
       (3, 2, 3), -- Thêm môn học Literature vào lớp học English 101
       (4, 2, 4); -- Thêm môn học Grammar vào lớp học English 101

-- Chèn dữ liệu vào bảng Grades
INSERT INTO Grades (GradeID, EnrollmentID, SubjectID, Grade)
VALUES (1, 1, 1, 9.5), -- Điểm số của John Doe cho môn Calculus là 9.5
       (2, 1, 2, 8.0), -- Điểm số của John Doe cho môn Algebra là 8.0
       (3, 2, 3, 8.5), -- Điểm số của Jane Doe cho môn Literature là 8.5
       (4, 2, 4, 9.0), -- Điểm số của Jane Doe cho môn Grammar là 9.0
	   (5, 3, 1, 8.5), -- Điểm số của Alice Smith cho môn Calculus là 8.5
       (6, 3, 2, 9.0), -- Điểm số của Alice Smith cho môn Algebra là 9.0
       (7, 4, 3, 7.5), -- Điểm số của Bob Johnson cho môn Literature là 7.5
       (8, 4, 4, 8.0); -- Điểm số của Bob Johnson cho môn Grammar là 8.0

-- Cập nhật thông tin của một sinh viên
UPDATE Students
SET FirstName = 'John', LastName = 'Smith'
WHERE StudentID = 1;

-- Xóa một sinh viên
DELETE FROM Students
WHERE StudentID = 2;

-- Chọn ra thông tin về các sinh viên và lớp học của họ
SELECT s.FirstName, s.LastName, c.ClassName
FROM Enrollments e
INNER JOIN Students s ON e.StudentID = s.StudentID
INNER JOIN Classes c ON e.ClassID = c.ClassID;

-- Chọn ra thông tin về điểm số của các sinh viên
SELECT s.FirstName, s.LastName, sb.SubjectName, g.Grade
FROM Grades g
INNER JOIN Enrollments e ON g.EnrollmentID = e.EnrollmentID
INNER JOIN Students s ON e.StudentID = s.StudentID
INNER JOIN Subjects sb ON g.SubjectID = sb.SubjectID;
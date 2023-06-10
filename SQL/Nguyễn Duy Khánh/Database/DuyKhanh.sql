-- Tạo cơ sở dữ liệu DuyKhanh
CREATE DATABASE DuyKhanh;
-- Sử dụng cơ sở dữ liệu DuyKhanh
USE DuyKhanh;
GO

-- Tạo bảng Authors
CREATE TABLE Authors (
    AuthorID INT PRIMARY KEY, -- Khóa chính
    FirstName VARCHAR(255), -- Tên
    LastName VARCHAR(255) -- Họ
);

-- Tạo bảng Books
CREATE TABLE Books (
    BookID INT PRIMARY KEY, -- Khóa chính
    Title VARCHAR(255), -- Tựa đề sách
    AuthorID INT FOREIGN KEY REFERENCES Authors(AuthorID), -- Khóa ngoại tham chiếu đến bảng Authors
    ISBN VARCHAR(13), -- Mã ISBN
    PublishedDate DATE -- Ngày xuất bản
);

-- Tạo bảng Members
CREATE TABLE Members (
    MemberID INT PRIMARY KEY, -- Khóa chính
    FirstName VARCHAR(255), -- Tên
    LastName VARCHAR(255), -- Họ
    Address VARCHAR(255), -- Địa chỉ
    PhoneNumber VARCHAR(20) -- Số điện thoại
);

-- Tạo bảng Loans
CREATE TABLE Loans (
    LoanID INT PRIMARY KEY, -- Khóa chính
    BookID INT FOREIGN KEY REFERENCES Books(BookID), -- Khóa ngoại tham chiếu đến bảng Books
    MemberID INT FOREIGN KEY REFERENCES Members(MemberID), -- Khóa ngoại tham chiếu đến bảng Members
    LoanDate DATE, -- Ngày mượn sách
    DueDate DATE -- Ngày hạn trả sách
);

-- Tạo bảng Returns
CREATE TABLE Returns (
    ReturnID INT PRIMARY KEY, -- Khóa chính
    LoanID INT FOREIGN KEY REFERENCES Loans(LoanID), -- Khóa ngoại tham chiếu đến bảng Loans
    ReturnDate DATE -- Ngày trả sách thực tế
);

-- Chèn dữ liệu vào bảng Authors
INSERT INTO Authors (AuthorID, FirstName, LastName)
VALUES (1, 'J.K.', 'Rowling'),
       (2, 'George', 'Orwell'),
       (3, 'Jane', 'Austen');

-- Chèn dữ liệu vào bảng Books
INSERT INTO Books (BookID, Title, AuthorID, ISBN, PublishedDate)
VALUES (1, 'Harry Potter and the Philosopher''s Stone', 1, '9780747532699', '1997-06-26'),
       (2, 'Harry Potter and the Chamber of Secrets', 1, '9780747538493', '1998-07-02'),
       (3, '1984', 2, '9780451524935', '1949-06-08'),
       (4, 'Animal Farm', 2, '9780451526342', '1945-08-17'),
       (5, 'Pride and Prejudice', 3, '9780679783268', '1813-01-28');

-- Chèn dữ liệu vào bảng Members
INSERT INTO Members (MemberID, FirstName, LastName, Address, PhoneNumber)
VALUES (1, 'John', 'Doe', '123 Main St.', '(123) 456-7890'),
       (2, 'Jane', 'Doe', '456 Elm St.', '(234) 567-8901');

-- Chèn dữ liệu vào bảng Loans
INSERT INTO Loans (LoanID, BookID, MemberID, LoanDate, DueDate)
VALUES (1, 1, 1, GETDATE(), DATEADD(day, 14, GETDATE())),
       (2, 3, 2, GETDATE(), DATEADD(day, 14, GETDATE()));

-- Chèn dữ liệu vào bảng Returns
INSERT INTO Returns (ReturnID, LoanID, ReturnDate)
VALUES (1, 1, DATEADD(day, 7, GETDATE()));


-- Cập nhật thông tin của một tác giả
UPDATE Authors
SET FirstName = 'Joanne', LastName = 'Rowling'
WHERE AuthorID = 1;

-- Xóa một cuốn sách
DELETE FROM Books
WHERE BookID = 1;

-- Chọn ra thông tin về các cuốn sách và tác giả của chúng
SELECT b.Title, a.FirstName, a.LastName
FROM Books b
INNER JOIN Authors a ON b.AuthorID = a.AuthorID;

-- Chọn ra thông tin về các cuốn sách đã được mượn và người mượn chúng
SELECT b.Title, m.FirstName, m.LastName, l.LoanDate, l.DueDate
FROM Loans l
INNER JOIN Books b ON l.BookID = b.BookID
INNER JOIN Members m ON l.MemberID = m.MemberID;
CREATE DATABASE SalesManagement
GO

USE SalesManagement
GO

-- TẠO TABLE 

CREATE TABLE Customers (
    CustomerID int PRIMARY KEY,
    CustomerName nvarchar(255),
    ContactName nvarchar(255),
    Address nvarchar(255),
    City nvarchar(255),
    PostalCode nvarchar(255),
    Country nvarchar(255)
);
GO
CREATE TABLE Categories (
    CategoryID int PRIMARY KEY,
    CategoryName nvarchar(255),
    Description ntext
);
GO
CREATE TABLE Suppliers (
    SupplierID int PRIMARY KEY,
    SupplierName nvarchar(255),
    ContactName nvarchar(255),
    Address nvarchar(255),
    City nvarchar(255),
    PostalCode nvarchar(255),
    Country nvarchar(255),
);
GO
CREATE TABLE Products (
    ProductID int PRIMARY KEY,
    ProductName nvarchar(255),
    SupplierID int FOREIGN KEY REFERENCES Suppliers(SupplierID),
    CategoryID int FOREIGN KEY REFERENCES Categories(CategoryID),
    Unit nvarchar(255),
    Price float
);
GO
CREATE TABLE Orders (
    OrderID int PRIMARY KEY,
    CustomerID int FOREIGN KEY REFERENCES Customers(CustomerID),
    EmployeeID int,
    OrderDate date,
    ShipperID int
);
GO
CREATE TABLE OrderDetails (
    OrderDetailID int PRIMARY KEY,
    OrderID int FOREIGN KEY REFERENCES Orders(OrderID),
    ProductID int FOREIGN KEY REFERENCES Products(ProductID),
    Quantity int
);


-- CHÈN DỮ LIỆU VÀO TABLE

INSERT INTO Customers (CustomerID, CustomerName, ContactName, Address, City, PostalCode, Country)
VALUES (1, 'Alfreds Futterkiste', 'Maria Anders', 'Obere Str. 57', 'Berlin', '12209', 'Germany'),
       (2, 'Ana Trujillo Emparedados y helados', 'Ana Trujillo', 'Avda. de la Constitución 2222', 'México D.F.', '05021', 'Mexico'),
       (3, 'Antonio Moreno Taquería', 'Antonio Moreno', 'Mataderos 2312', 'México D.F.', '05023', 'Mexico'),
       (4, 'Around the Horn', 'Thomas Hardy', '120 Hanover Sq.', 'London', 'WA1 1DP', 'UK'),
       (5, 'Berglunds snabbköp', 'Christina Berglund', 'Berguvsvägen 8', 'Luleå', 'S-958 22', 'Sweden'),
       (6, 'Blauer See Delikatessen', 'Hanna Moos', 'Forsterstr. 57', 'Mannheim', '68306', 'Germany'),
       (7, 'Blondel père et fils', 'Frédérique Citeaux', '24, place Kléber', 'Strasbourg', '67000', 'France'),
       (8, 'Bólido Comidas preparadas', 'Martín Sommer', 'C/ Araquil, 67', 'Madrid', '28023', 'Spain');
GO
INSERT INTO Categories (CategoryID, CategoryName, Description)
VALUES (1, 'Beverages', 'Soft drinks, coffees, teas, beers, and ales'),
       (2, 'Condiments', 'Sweet and savory sauces, relishes, spreads, and seasonings'),
       (3, 'Confections', 'Desserts, candies, and sweet breads'),
       (4, 'Dairy Products', 'Cheeses'),
       (5, 'Grains/Cereals', 'Breads, crackers, pasta, and cereal'),
       (6, 'Meat/Poultry', 'Prepared meats'),
       (7, 'Produce', 'Dried fruit and bean curd'),
       (8, 'Seafood', 'Seaweed and fish');
GO
INSERT INTO Suppliers (SupplierID, SupplierName, ContactName, Address, City, PostalCode, Country)
VALUES (1,'Exotic Liquids','Charlotte Cooper','49 Gilbert St.','Londona','EC1 4SD','UK'),
	   (2,'New Orleans Cajun Delights','Shelley Burke','P.O. Box 78934','New Orleans','70117','USA'),
	   (3,'Grandma Kellys Homestead','Regina Murphy','707 Oxford Rd.','Ann Arbor','48104','USA'),
	   (4,'Tokyo Traders','Yoshi Nagase','9-8 Sekimai Musashino-shi','Tokyo','','Japan'),
	   (5,'Cooperativa de Quesos Las Cabras','Antonio del Valle Saavedra','Calle del Rosal 4','Oviedo','33007','Spain'),
	   (6,'Mayumi s','Mayumi Ohno','92 Setsuko Chuo-ku','Osaka','','Japan'),
	   (7,'Pavlova Ltd.','Ian Devling','74 Rose St. Moonie Ponds','Melbourne','3058','Australia'),
	   (8,'Specialty Biscuits Ltd.','Peter Wilson','29 King s Way','Manchester','M14 GSD','UK');
GO
INSERT INTO Products (ProductID , ProductName , SupplierID , CategoryID , Unit , Price )
VALUES 
	   (1,'Chais' ,1 ,1 ,'10 boxes x 20 bags' ,18),
	   (2,'Chang' ,1 ,1 ,'24 - 12 oz bottles' ,19),
	   (3,'Aniseed Syrup' ,1 ,2 ,'12 - 550 ml bottles' ,10),
	   (4,'Chef Anton s Cajun Seasoning' ,2 ,2 ,'48 - 6 oz jars' ,22),
	   (5,'Chef Anton s Gumbo Mix' ,2 ,2 ,'36 boxes' ,21.35),
	   (6,'Grandma s Boysenberry Spread' ,3 ,2 ,'12 - 8 oz jars' ,25),
	   (7,'Uncle Bob s Organic Dried Pears' ,3 ,7 ,'12 - 1 lb pkgs.' ,30),
	   (8,'Northwoods Cranberry Sauce' ,3 ,2 ,'12 - 12 oz jars' ,40);
GO
INSERT INTO Orders(OrderID,CustomerID,EmployeeID,OrderDate,ShipperID)
VALUES
	   (10248,1,5,'1996-07-04',3), 
	   (10249,2,6,'1996-07-05',1), 
	   (10250,3,4,'1996-07-08',2),
	   (10251,4,3,'1996-07-08',1),
	   (10252,5,4,'1996-07-09',2),
	   (10253,6,3,'1996-07-10',2),
	   (10254,7,5,'1996-07-11',2),
	   (10255,8,9,'1996-07-12',3);
GO
INSERT INTO OrderDetails(OrderDetailID,OrderID,ProductID,Quantity)
VALUES
	   (1,10248,1,12),
	   (2,10248,2,10),
	   (3,10248,2,5),
	   (4,10249,4,9),
	   (5,10249,3,40),
	   (6,10250,6,10),
	   (7,10250,7,35),
	   (8,10250,5,15);
GO

-- Câu truy vấn SELECT cơ bản lấy tất cả các cột và hàng từ bảng Customers 
SELECT * FROM Customers;

-- Câu truy vấn SELECT nâng cao: lấy tên khách hàng và địa chỉ từ bảng Customers, sắp xếp theo tên khách hàng 
SELECT CustomerName, Address FROM Customers 
	ORDER BY CustomerName;

-- Câu truy vấn SELECT lồng: lấy tên khách hàng và tổng số đơn hàng từ bảng Customers và Orders 
SELECT Customers.CustomerName, COUNT(Orders.OrderID) AS TotalOrders FROM Customers 
INNER JOIN Orders ON Customers.CustomerID = Orders.CustomerID 
GROUP BY Customers.CustomerName;

-- Câu truy vấn DELETE cơ bản: xóa hàng từ bảng Customers có CustomerID = 1 
DELETE FROM Customers WHERE CustomerID = 1;

-- Câu truy vấn DELETE nâng cao: xóa hàng từ bảng Customers có số đơn hàng ít hơn 5 
DELETE FROM Customers WHERE CustomerID 
IN ( SELECT Customers.CustomerID FROM Customers 
	INNER JOIN Orders ON Customers.CustomerID = Orders.CustomerID 
	GROUP BY Customers.CustomerID 
	HAVING COUNT(Orders.OrderID) < 5 );

-- câu truy vấn UPDATE cơ bản: cập nhật địa chỉ cho khách hàng có CustomerID = 1 
UPDATE Customers SET Address = 'LonDon' WHERE CustomerID = 1;

-- Câu truy vấn UPDATE nâng cao: tăng giá sản phẩm lên 10% cho các sản phẩm thuộc loại có CategoryID = 1 
UPDATE Products SET Price = Price * 1.1 WHERE CategoryID = 1;

-- Sử dụng INNER JOIN: lấy tên khách hàng và tên sản phẩm từ bảng Customers, Orders, OrderDetails và Products
SELECT Customers.CustomerName, Products.ProductName 
FROM ((Customers INNER JOIN Orders ON Customers.CustomerID = Orders.CustomerID) 
	INNER JOIN OrderDetails ON Orders.OrderID = OrderDetails.OrderID) 
		INNER JOIN Products ON OrderDetails.ProductID = Products.ProductID;

-- Sử dụng OUTER JOIN: lấy tất cả các khách hàng và đơn hàng của họ từ bảng Customers và Orders, kể cả khi khách hàng không có đơn hàng nào 
SELECT Customers.CustomerName, Orders.OrderID FROM Customers 
LEFT JOIN Orders ON Customers.CustomerID = Orders.CustomerID;

SELECT * FROM Categories
SELECT * FROM Customers
SELECT * FROM OrderDetails
SELECT * FROM Orders
SELECT * FROM Products
SELECT * FROM Suppliers
USE Z_MyBase;

GO

--CREATE VIEW Teacher (Код, Фамилия, Телефон)
--	AS SELECT Код_преподавателя, Фамилия_преподавателя, Телефон 
--	FROM Преподаватели;

SELECT * FROM Teacher;


GO

--CREATE VIEW [Number_of_classes] (Код_преподавателя, количество_занятий)
--	AS SELECT T.Код_преподавателя, COUNT(C.Код_преподавателя)
--	FROM Преподаватели T INNER JOIN Занятия C
--	ON T.Код_преподавателя = C.Код_преподавателя
--	GROUP BY T.Код_преподавателя;

SELECT * FROM Number_of_classes;


GO

--CREATE VIEW [Expensive_classes] (Код_занятия, Оплата)
--	AS SELECT Код_занятия, Оплата FROM Занятия
--		WHERE Оплата > 300;

--INSERT Expensive_classes VALUES('015', 350);
--INSERT Expensive_classes VALUES('016', 450);

SELECT * FROM Expensive_classes;


GO

--CREATE VIEW [Expensive_classes_check] (Код_занятия, Оплата)
--	AS SELECT Код_занятия, Оплата FROM Занятия
--		WHERE Оплата > 300 WITH CHECK OPTION;

--INSERT Expensive_classes_check VALUES('017', 250);

SELECT * FROM Expensive_classes_check;


GO

--CREATE VIEW [Number_of_students] (Группа, Количество_студентов)
--	AS SELECT TOP 10 Номер_группы, Количество_студентов FROM Группы
--												ORDER BY Количество_студентов;

SELECT * FROM Number_of_students;


GO

--ALTER VIEW [Number_of_classes] (Код_преподавателя, количество_занятий)
--		WITH SCHEMABINDING
--	AS SELECT T.Код_преподавателя, COUNT(C.Код_преподавателя)
--	FROM dbo.Преподаватели T INNER JOIN dbo.Занятия C
--	ON T.Код_преподавателя = C.Код_преподавателя
--	GROUP BY T.Код_преподавателя;

SELECT * FROM Number_of_classes;
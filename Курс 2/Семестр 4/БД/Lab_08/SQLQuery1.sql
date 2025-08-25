USE UNIVER;

GO

--CREATE VIEW [Преподаватель]
--	AS SELECT TEACHER [Код],
--			  TEACHER_NAME [Имя преподавателя],
--			  GENDER [Пол],
--			  PULPIT [Код кафедры] FROM TEACHER;

SELECT * FROM [Преподаватель]


GO

--CREATE VIEW [Количество кафедр]
--	AS SELECT F.FACULTY [Факультет],
--			  COUNT(P.PULPIT) [Количество кафедр]
--				FROM FACULTY F INNER JOIN PULPIT P
--				ON F.FACULTY = P.FACULTY
--				GROUP BY F.FACULTY;

SELECT * FROM [Количество кафедр]


GO

--CREATE VIEW Аудитории (Код, [Наименование аудитории])
--	AS SELECT AUDITORIUM, AUDITORIUM_TYPE FROM AUDITORIUM
--		WHERE AUDITORIUM_TYPE IN ('LK');

--INSERT Аудитории VALUES('200-3a', 'LK')
--INSERT Аудитории VALUES('100-3a', 'LK')

SELECT* FROM Аудитории


GO

--CREATE VIEW [Лекционные_аудитории] (Код, [Наименование аудитории])
--	AS SELECT AUDITORIUM, AUDITORIUM_TYPE FROM AUDITORIUM
--		WHERE AUDITORIUM_TYPE IN ('LK') WITH CHECK OPTION;

SELECT* FROM [Лекционные_аудитории]


GO

--CREATE VIEW Дисциплины (Код, [Наименование дисциплины], [Код кафедры])
--	AS SELECT TOP 30 SUBJECT, SUBJECT_NAME, PULPIT FROM SUBJECT
--											ORDER BY SUBJECT;

SELECT * FROM Дисциплины


GO

--ALTER VIEW [Количество кафедр] WITH SCHEMABINDING
--	AS SELECT F.FACULTY [Факультет],
--			  COUNT(P.PULPIT) [Количество кафедр]
--				FROM dbo.FACULTY F INNER JOIN dbo.PULPIT P
--				ON F.FACULTY = P.FACULTY
--				GROUP BY F.FACULTY;

SELECT * FROM [Количество кафедр]
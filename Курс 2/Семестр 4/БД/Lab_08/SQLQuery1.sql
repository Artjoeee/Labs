USE UNIVER;

GO

--CREATE VIEW [�������������]
--	AS SELECT TEACHER [���],
--			  TEACHER_NAME [��� �������������],
--			  GENDER [���],
--			  PULPIT [��� �������] FROM TEACHER;

SELECT * FROM [�������������]


GO

--CREATE VIEW [���������� ������]
--	AS SELECT F.FACULTY [���������],
--			  COUNT(P.PULPIT) [���������� ������]
--				FROM FACULTY F INNER JOIN PULPIT P
--				ON F.FACULTY = P.FACULTY
--				GROUP BY F.FACULTY;

SELECT * FROM [���������� ������]


GO

--CREATE VIEW ��������� (���, [������������ ���������])
--	AS SELECT AUDITORIUM, AUDITORIUM_TYPE FROM AUDITORIUM
--		WHERE AUDITORIUM_TYPE IN ('LK');

--INSERT ��������� VALUES('200-3a', 'LK')
--INSERT ��������� VALUES('100-3a', 'LK')

SELECT* FROM ���������


GO

--CREATE VIEW [����������_���������] (���, [������������ ���������])
--	AS SELECT AUDITORIUM, AUDITORIUM_TYPE FROM AUDITORIUM
--		WHERE AUDITORIUM_TYPE IN ('LK') WITH CHECK OPTION;

SELECT* FROM [����������_���������]


GO

--CREATE VIEW ���������� (���, [������������ ����������], [��� �������])
--	AS SELECT TOP 30 SUBJECT, SUBJECT_NAME, PULPIT FROM SUBJECT
--											ORDER BY SUBJECT;

SELECT * FROM ����������


GO

--ALTER VIEW [���������� ������] WITH SCHEMABINDING
--	AS SELECT F.FACULTY [���������],
--			  COUNT(P.PULPIT) [���������� ������]
--				FROM dbo.FACULTY F INNER JOIN dbo.PULPIT P
--				ON F.FACULTY = P.FACULTY
--				GROUP BY F.FACULTY;

SELECT * FROM [���������� ������]
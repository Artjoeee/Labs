USE Z_MyBase;

GO

--CREATE VIEW Teacher (���, �������, �������)
--	AS SELECT ���_�������������, �������_�������������, ������� 
--	FROM �������������;

SELECT * FROM Teacher;


GO

--CREATE VIEW [Number_of_classes] (���_�������������, ����������_�������)
--	AS SELECT T.���_�������������, COUNT(C.���_�������������)
--	FROM ������������� T INNER JOIN ������� C
--	ON T.���_������������� = C.���_�������������
--	GROUP BY T.���_�������������;

SELECT * FROM Number_of_classes;


GO

--CREATE VIEW [Expensive_classes] (���_�������, ������)
--	AS SELECT ���_�������, ������ FROM �������
--		WHERE ������ > 300;

--INSERT Expensive_classes VALUES('015', 350);
--INSERT Expensive_classes VALUES('016', 450);

SELECT * FROM Expensive_classes;


GO

--CREATE VIEW [Expensive_classes_check] (���_�������, ������)
--	AS SELECT ���_�������, ������ FROM �������
--		WHERE ������ > 300 WITH CHECK OPTION;

--INSERT Expensive_classes_check VALUES('017', 250);

SELECT * FROM Expensive_classes_check;


GO

--CREATE VIEW [Number_of_students] (������, ����������_���������)
--	AS SELECT TOP 10 �����_������, ����������_��������� FROM ������
--												ORDER BY ����������_���������;

SELECT * FROM Number_of_students;


GO

--ALTER VIEW [Number_of_classes] (���_�������������, ����������_�������)
--		WITH SCHEMABINDING
--	AS SELECT T.���_�������������, COUNT(C.���_�������������)
--	FROM dbo.������������� T INNER JOIN dbo.������� C
--	ON T.���_������������� = C.���_�������������
--	GROUP BY T.���_�������������;

SELECT * FROM Number_of_classes;
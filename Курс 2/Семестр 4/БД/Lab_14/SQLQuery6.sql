
CREATE FUNCTION COUNT_PULPITS(@faculty varchar(50)) 
RETURNS int
AS
BEGIN
    DECLARE @count int;
    SELECT @count = COUNT(*) FROM PULPIT WHERE FACULTY = @faculty;
    RETURN @count;
END;
GO

CREATE FUNCTION COUNT_GROUPS(@faculty varchar(50)) 
RETURNS int
AS
BEGIN
    DECLARE @count int;
    SELECT @count = COUNT(*) FROM GROUPS WHERE FACULTY = @faculty;
    RETURN @count;
END;
GO

CREATE FUNCTION COUNT_PROFESSIONS(@faculty varchar(50)) 
RETURNS int
AS
BEGIN
    DECLARE @count int;
    SELECT @count = COUNT(*) FROM PROFESSION WHERE FACULTY = @faculty;
    RETURN @count;
END;
GO


create FUNCTION FACULTY_REPORT(@c int) 
RETURNS @fr table (
    [���������] varchar(50),
    [���������� ������] int,
    [���������� �����] int,
    [���������� ���������] int,
    [���������� ��������������] int
)
AS 
BEGIN 
    INSERT INTO @fr
    SELECT 
        f.FACULTY as [���������],
        dbo.COUNT_PULPITS(f.FACULTY) as [���������� ������],
        dbo.COUNT_GROUPS(f.FACULTY) as [���������� �����],
        dbo.COUNT_STUDENTS(f.FACULTY, default) as [���������� ���������],
        dbo.COUNT_PROFESSIONS(f.FACULTY) as [���������� ��������������]
    FROM FACULTY f
    WHERE dbo.COUNT_STUDENTS(f.FACULTY, default) > @c;
    
    RETURN;
END;
GO

-- �������� ����� ��� ����������� � ����� ��� 100 ����������
SELECT * FROM dbo.FACULTY_REPORT(5);


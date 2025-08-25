
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
    [Факультет] varchar(50),
    [Количество кафедр] int,
    [Количество групп] int,
    [Количество студентов] int,
    [Количество специальностей] int
)
AS 
BEGIN 
    INSERT INTO @fr
    SELECT 
        f.FACULTY as [Факультет],
        dbo.COUNT_PULPITS(f.FACULTY) as [Количество кафедр],
        dbo.COUNT_GROUPS(f.FACULTY) as [Количество групп],
        dbo.COUNT_STUDENTS(f.FACULTY, default) as [Количество студентов],
        dbo.COUNT_PROFESSIONS(f.FACULTY) as [Количество специальностей]
    FROM FACULTY f
    WHERE dbo.COUNT_STUDENTS(f.FACULTY, default) > @c;
    
    RETURN;
END;
GO

-- Получить отчет для факультетов с более чем 100 студентами
SELECT * FROM dbo.FACULTY_REPORT(5);


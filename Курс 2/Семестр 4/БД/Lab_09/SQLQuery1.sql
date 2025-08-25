USE UNIVER;

--1
DECLARE @a char = 'a',
		@b varchar = 'b',
		@c datetime,
		@d time(2),
		@e int,
		@f smallint,
		@g tinyint,
		@h numeric(12, 5)

SET @c = GETDATE();
SET @d = '23:00:00';
SET @e = 1;

SELECT @f = 2, @g = 3, @h = 4.5

PRINT 'a = ' + CAST(@a as varchar(10));
PRINT 'b = ' + @b;
PRINT 'c = ' + CAST(@c as varchar(10));
PRINT 'd = ' + CAST(@d as varchar(10));
PRINT 'e = ' + CAST(@e as varchar(10));

SELECT @f f, @g g, @h h


--2
DECLARE @total int =(select SUM(AUDITORIUM_CAPACITY) FROM AUDITORIUM),
	@count float, @average float, @lessThanAvg float, @percent float
IF @total > 200
begin
	SELECT @count = (SELECT COUNT(*) FROM AUDITORIUM),
			@average = (SELECT AVG(AUDITORIUM_CAPACITY) FROM AUDITORIUM)
	SET @lessThanAvg = (SELECT COUNT(*) FROM AUDITORIUM WHERE AUDITORIUM_CAPACITY < @average)
	SET @percent = (@lessThanAvg / @count) * 100
	SELECT @total 'Общая вместимость', @count 'Количество аудиторий', @average 'Средняя вместимость',
			@lessThanAvg 'Меньше средней', @percent 'Процент'
end
ELSE 
	PRINT 'Общая вместимость: '+ CAST(@total as varchar(10));


--3
PRINT 'Число обработанных строк: '+ CAST(@@ROWCOUNT as varchar(20));
PRINT 'Версия SQL Server: '+ CAST(@@VERSION as varchar(20));
PRINT 'Системный идентификатор процесса: '+ CAST(@@SPID as varchar(20));
PRINT 'Код последней ошибки: '+ CAST(@@ERROR as varchar(20));
PRINT 'Имя сервера: '+ CAST(@@SERVERNAME as varchar(20));
PRINT 'Уровень вложенности транзакции: '+ CAST(@@TRANCOUNT as varchar(20));
PRINT 'Результат считыв. строк результ. набора: '+ CAST(@@FETCH_STATUS as varchar(20));
PRINT 'Уровень вложенности текущей процедуры: '+ CAST(@@NESTLEVEL as varchar(20));


--4
DECLARE @t float = 4, @x float = 4, @z float;
	IF (@t > @x)
		SET @z = POWER(SIN(@t), 2);
	ELSE IF (@t < @x)
		SET @z = 4 * (@t + @x);
	ELSE
		SET @z = 1 - EXP(@x - 2)
	PRINT 'z = ' + CAST(@z as varchar(10));


SELECT 
    LEFT(NAME, CHARINDEX(' ', NAME) - 1) + ' ' +
    LEFT(PARSENAME(REPLACE(NAME, ' ', '.'), 2), 1) + '. ' +
    LEFT(PARSENAME(NAME, 1), 1) + '.'
    AS Сокращенное_имя
FROM STUDENT;


SELECT 
    NAME,
    BDAY,
    DATEDIFF(YEAR, BDAY, GETDATE()) - 
		CASE 
            WHEN MONTH(BDAY) > MONTH(GETDATE()) 
                 OR (MONTH(BDAY) = MONTH(GETDATE()) AND DAY(BDAY) > DAY(GETDATE())) 
            THEN 1 ELSE 0 
          END AS AGE
FROM STUDENT
WHERE MONTH(BDAY) = MONTH(DATEADD(MONTH, 1, GETDATE()));


SELECT 
    DISTINCT DATENAME(WEEKDAY, PROGRESS.PDATE) AS День_недели
FROM PROGRESS INNER JOIN STUDENT
ON PROGRESS.IDSTUDENT = STUDENT.IDSTUDENT
WHERE PROGRESS.SUBJECT = 'DB'
  AND STUDENT.IDGROUP = 5;


--5
DECLARE @totalX int =(select SUM(AUDITORIUM_CAPACITY) FROM AUDITORIUM),
	@countX float, @averageX float, @lessThanAvgX float, @percentX float
IF @totalX > 200
begin
	SELECT @countX = (SELECT COUNT(*) FROM AUDITORIUM),
			@averageX = (SELECT AVG(AUDITORIUM_CAPACITY) FROM AUDITORIUM)
	SET @lessThanAvgX = (SELECT COUNT(*) FROM AUDITORIUM WHERE AUDITORIUM_CAPACITY < @averageX)
	SET @percentX = (@lessThanAvgX / @countX) * 100
	SELECT @totalX 'Общая вместимость', @countX 'Количество аудиторий', @averageX 'Средняя вместимость',
			@lessThanAvgX 'Меньше средней', @percentX 'Процент'
end
ELSE 
	PRINT 'Общая вместимость: '+ CAST(@totalX as varchar(10));


--6
SELECT CASE
		WHEN NOTE between 4 and 5 THEN 'Могло быть лучше'
		WHEN NOTE between 6 and 8 THEN 'Хорошо'
		WHEN NOTE between 9 and 10 THEN 'Отлично'
		ELSE 'Пересдача'
		END Оценка, COUNT(*) [Количество]
FROM PROGRESS
GROUP BY CASE
		WHEN NOTE between 4 and 5 THEN 'Могло быть лучше'
		WHEN NOTE between 6 and 8 THEN 'Хорошо'
		WHEN NOTE between 9 and 10 THEN 'Отлично'
		ELSE 'Пересдача'
		END


--7
--CREATE table #EXPLRE
--(   
--	NUMBER int,
--	SQUARENUMBER int,
--	FIELD varchar(100)
--);

--SET nocount on;
--DECLARE @i int = 1;
--WHILE @i <= 10
--begin
--	INSERT #EXPLRE(NUMBER, SQUARENUMBER, FIELD)
--		VALUES(@i, POWER(@i, 2), 'строка №' + CAST(@i as varchar(10)))
--	SET @i = @i + 1;
--end;

--SELECT NUMBER, SQUARENUMBER, FIELD
--FROM #EXPLRE


--8
DECLARE @v int = 1
PRINT 'A' + CAST(@v as varchar(10))
PRINT 'B' + CAST(@v as varchar(10))
RETURN
PRINT 'C' + CAST(@v as varchar(10))


--9
BEGIN TRY
	UPDATE PROGRESS SET NOTE = 'a'
			WHERE IDSTUDENT = 1001
END TRY
BEGIN CATCH
	PRINT ERROR_NUMBER()
	PRINT ERROR_MESSAGE()
	PRINT ERROR_LINE()
	PRINT ERROR_PROCEDURE()
	PRINT ERROR_SEVERITY()
	PRINT ERROR_STATE()
END CATCH
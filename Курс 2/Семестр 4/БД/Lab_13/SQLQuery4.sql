USE UNIVER;

GO
CREATE PROCEDURE PAUDITORIUMINSERT @a char(20), @n varchar(50), @c int = 0, @t char(10)
AS
DECLARE @rc int = 1;
BEGIN TRY
	INSERT INTO AUDITORIUM (AUDITORIUM, AUDITORIUM_TYPE, AUDITORIUM_CAPACITY, AUDITORIUM_NAME)
		VALUES (@a, @n, @c, @t);
	RETURN @rc;
END TRY
BEGIN CATCH
	PRINT N'Номер ошибки: ' + cast(error_number() as varchar(6));
	PRINT N'Сообщение: ' + error_message();
	PRINT N'Уровень: ' + cast(error_severity() as varchar(6));
	PRINT N'Метка: ' + cast(error_state() as varchar(8));
	PRINT N'Номер строки: ' + cast(error_line() as varchar(8));
	if ERROR_PROCEDURE() is not null
	PRINT N'Имя процедуры: ' + error_procedure();
	return -1;
END CATCH;
GO

DECLARE @rc int;
EXEC @rc = PAUDITORIUMINSERT @a = '502-1', @n = 'LK', @c = 100, @t = '502-1';
PRINT N'Код ошибки: ' + cast(@rc as varchar(3));


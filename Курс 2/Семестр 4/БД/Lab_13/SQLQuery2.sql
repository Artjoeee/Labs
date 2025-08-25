USE [UNIVER]
GO

/****** Object:  StoredProcedure [dbo].[PSUBJECT]    Script Date: 31.05.2025 1:05:06 ******/
SET ANSI_NULLS ON
GO

SET QUOTED_IDENTIFIER ON
GO

ALTER PROCEDURE [dbo].[PSUBJECT] @p varchar(20), @c int output
AS
BEGIN 
	DECLARE @k int = (SELECT COUNT(*) FROM SUBJECT);
	PRINT N'Параметры: @p = ' + @p + ', @c = ' + cast(@c as  varchar(3));
	SELECT *  FROM SUBJECT WHERE PULPIT = @p;
	SET @c = @@ROWCOUNT;
	RETURN @k;
END;
GO

DECLARE @k int = 0, @r int = 0, @p varchar(20);
EXEC @k = PSUBJECT @p = 'ISIT', @c = @r output;
PRINT N'Количество всех строк: ' + cast(@k as  varchar(3));
PRINT N'Количество строк ISIT: ' + cast(@r as varchar(3));
GO



USE AdoSporticsDB;

SET IDENTITY_INSERT Users ON;
INSERT INTO Users (Id, Name, Email, PhoneNumber, PasswordHash, PasswordSalt, Role, Balance, Status) VALUES (0, N'Жамойдо Артём Игоревич', N'sportics@gmail.com', N'+375445730402', N'22WrU9d9KH6xpmqAfs5Ybk1zx73YziwEliMfONaY3+k=', N'A7O58krrWpAK1D8rKc5tLg==', N'Администратор', 1, N'Активен');
SET IDENTITY_INSERT Users OFF;

INSERT INTO MembershipOrders (MembershipId, MembershipName, ClientId, ClientName)
VALUES (12, N'Абонемент в тренажерный зал на месяц (24/7)', 1, N'Пинчук Александр Сергеевич');

GO
CREATE PROCEDURE GetAllCoachesWithSchedules
AS
BEGIN
    SELECT 
        c.Id AS CoachId, c.Name, c.Specialization, c.PhoneNumber, c.Email, c.Information, c.Photo,
        s.Id AS ScheduleId, s.Category AS ScheduleCategory, s.Date, s.Time, s.Status AS ScheduleStatus, s.CoachId AS ScheduleCoachId
    FROM Coaches c
    LEFT JOIN Schedules s ON c.Id = s.CoachId
END

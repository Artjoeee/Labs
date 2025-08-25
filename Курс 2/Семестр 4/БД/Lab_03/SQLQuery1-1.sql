USE master;
CREATE database ZH_MyBase on primary
(name = N'ZH_MyBase_mdf', filename = N'C:\Users\HomeUser\Desktop\Курс 2\БД\Lab_03\File group\ZH_MyBase_mdf.mdf',
 size = 10240Kb, maxsize = 1Gb, filegrowth = 1024Kb),
(name = N'ZH_MyBase_ndf', filename = N'C:\Users\HomeUser\Desktop\Курс 2\БД\Lab_03\File group\ZH_MyBase_ndf.ndf',
 size = 10240Kb, maxsize = 1Gb, filegrowth = 25%),
filegroup FG1
(name = N'ZH_MyBase_fg1_1', filename = N'C:\Users\HomeUser\Desktop\Курс 2\БД\Lab_03\File group\ZH_MyBase_fg1_1.ndf',
 size = 10240Kb, maxsize = 1Gb, filegrowth = 25%),
(name = N'ZH_MyBase_fg1_2', filename = N'C:\Users\HomeUser\Desktop\Курс 2\БД\Lab_03\File group\ZH_MyBase_fg1_2.ndf',
 size = 10240Kb, maxsize = 1Gb, filegrowth = 25%)
log on
(name = N'ZH_MyBase_log', filename = N'C:\Users\HomeUser\Desktop\Курс 2\БД\Lab_03\File group\ZH_MyBase_log.ldf',
 size = 10240Kb, maxsize = 1Gb, filegrowth = 10%);
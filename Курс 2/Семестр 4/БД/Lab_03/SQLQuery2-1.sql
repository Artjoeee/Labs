USE ZH_MyBase;
CREATE table Группы
(	Номер_группы nvarchar(10) primary key,
	Количество_студентов int not null,
	Специальность nvarchar(10),
	Отделение nvarchar(20)
) on FG1;
CREATE table Преподаватели
(	Код_преподавателя nvarchar(10) primary key,
	Фамилия_преподавателя nvarchar(20),
	Имя nvarchar(20),
	Отчество nvarchar(20),
	Телефон nvarchar(20),
	Стаж nvarchar(20)
) on FG1;
CREATE table Занятия
(	Код_занятия nvarchar(10) primary key,
	Предмет nvarchar(30),
	Код_преподавателя nvarchar(10) foreign key references 
										Преподаватели (Код_преподавателя),
	Тип_занятия nvarchar(20),
	Количество_часов int,
	Номер_группы nvarchar(10) foreign key references
										Группы (Номер_группы),
	Оплата float not null
) on FG1;
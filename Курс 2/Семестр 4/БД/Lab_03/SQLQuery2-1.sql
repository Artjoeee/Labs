USE ZH_MyBase;
CREATE table ������
(	�����_������ nvarchar(10) primary key,
	����������_��������� int not null,
	������������� nvarchar(10),
	��������� nvarchar(20)
) on FG1;
CREATE table �������������
(	���_������������� nvarchar(10) primary key,
	�������_������������� nvarchar(20),
	��� nvarchar(20),
	�������� nvarchar(20),
	������� nvarchar(20),
	���� nvarchar(20)
) on FG1;
CREATE table �������
(	���_������� nvarchar(10) primary key,
	������� nvarchar(30),
	���_������������� nvarchar(10) foreign key references 
										������������� (���_�������������),
	���_������� nvarchar(20),
	����������_����� int,
	�����_������ nvarchar(10) foreign key references
										������ (�����_������),
	������ float not null
) on FG1;
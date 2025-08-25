USE Z_MyBase;
SELECT * From Занятия;
SELECT Код_занятия, Предмет From Занятия;
SELECT COUNT(*) From Занятия;
UPDATE Занятия set Оплата = Оплата + 100 Where Предмет = 'БД';
SELECT Оплата From Занятия Where Предмет = 'БД';
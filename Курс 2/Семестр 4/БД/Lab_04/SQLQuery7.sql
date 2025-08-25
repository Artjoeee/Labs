USE UNIVER;

CREATE TABLE Group1 (
    ID INT PRIMARY KEY,
    Имя VARCHAR(30)
);

CREATE TABLE Group2 (
    ID INT PRIMARY KEY,
    Имя VARCHAR(30)
);

INSERT INTO Group1 (ID, Имя) VALUES (1, 'Жамойдо Артём'), (2, 'Мандрик Алексей'), (3, 'Ярохович Станислав');
INSERT INTO Group2 (ID, Имя) VALUES (2, 'Мандрик Алексей'), (3, 'Ярохович Станислав'), (4, 'Дубина Артём');

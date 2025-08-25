USE Z_MyBase;

SELECT Преподаватели.Фамилия_преподавателя,
		MAX(Занятия.Оплата) [MAX],
		MIN(Занятия.Оплата) [MIN],
		ROUND(AVG(CAST(Занятия.Оплата as float(4))),2) [AVG],
		SUM(Занятия.Оплата) [SUM],
		COUNT(*) [Количество занятий]
FROM Преподаватели INNER JOIN Занятия
ON Преподаватели.Код_преподавателя = Занятия.Код_преподавателя
GROUP BY Преподаватели.Фамилия_преподавателя


SELECT *
FROM (SELECT CASE When Оплата between 100 and 200 then '100-200'
					When Оплата between 201 and 300 then '201-300'
					When Оплата between 301 and 400 then '301-400'
					When Оплата between 401 and 700 then '401-700'
					else 'Оплата < 0 | Оплата > 700'
					end [Диапазон_оплаты], COUNT(*) [Количество занятий]
		FROM Занятия GROUP BY CASE
					When Оплата between 100 and 200 then '100-200'
					When Оплата between 201 and 300 then '201-300'
					When Оплата between 301 and 400 then '301-400'
					When Оплата between 401 and 700 then '401-700'
					else 'Оплата < 0 | Оплата > 700'
					end) as T
						ORDER BY CASE [Диапазон_оплаты]
							When '401-700' then 1
							When '301-400' then 2
							When '201-300' then 3
							When '100-200' then 4
							else 'Оплата < 0 | Оплата > 700'
							end


SELECT ROUND(AVG(CAST(Занятия.Оплата as float(4))),2) [AVG],
		Преподаватели.Фамилия_преподавателя
FROM Занятия INNER JOIN Преподаватели
ON Занятия.Код_преподавателя = Преподаватели.Код_преподавателя
GROUP BY Преподаватели.Фамилия_преподавателя
ORDER BY ROUND(AVG(CAST(Занятия.Оплата as float(4))),2) DESC


SELECT ROUND(AVG(CAST(Занятия.Оплата as float(4))),2) [AVG],
		Преподаватели.Фамилия_преподавателя
FROM Занятия INNER JOIN Преподаватели
ON Занятия.Код_преподавателя = Преподаватели.Код_преподавателя
WHERE Занятия.Тип_занятия = 'Лабораторная'
GROUP BY Преподаватели.Фамилия_преподавателя
ORDER BY ROUND(AVG(CAST(Занятия.Оплата as float(4))),2) DESC


SELECT ROUND(AVG(CAST(Занятия.Количество_часов as float(4))),2) [AVG],
		Группы.Специальность
FROM Группы INNER JOIN Занятия
ON Группы.Номер_группы = Занятия.Номер_группы
WHERE Группы.Специальность IN ('ПИ', 'ЦД')
GROUP BY Группы.Специальность
ORDER BY ROUND(AVG(CAST(Занятия.Количество_часов as float(4))),2) DESC


SELECT A1.Код_преподавателя, 
	(SELECT COUNT(*) FROM Занятия A2
		WHERE A2.Оплата = A1.Оплата AND
			A2.Код_преподавателя = A1.Код_преподавателя) [Количество занятий]
FROM Занятия A1
GROUP BY A1.Код_преподавателя, A1.Оплата
HAVING A1.Оплата = 200 OR A1.Оплата = 400
ORDER BY [Количество занятий] DESC
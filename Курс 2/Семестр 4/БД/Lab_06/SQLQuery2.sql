USE Z_MyBase;

SELECT �������������.�������_�������������,
		MAX(�������.������) [MAX],
		MIN(�������.������) [MIN],
		ROUND(AVG(CAST(�������.������ as float(4))),2) [AVG],
		SUM(�������.������) [SUM],
		COUNT(*) [���������� �������]
FROM ������������� INNER JOIN �������
ON �������������.���_������������� = �������.���_�������������
GROUP BY �������������.�������_�������������


SELECT *
FROM (SELECT CASE When ������ between 100 and 200 then '100-200'
					When ������ between 201 and 300 then '201-300'
					When ������ between 301 and 400 then '301-400'
					When ������ between 401 and 700 then '401-700'
					else '������ < 0 | ������ > 700'
					end [��������_������], COUNT(*) [���������� �������]
		FROM ������� GROUP BY CASE
					When ������ between 100 and 200 then '100-200'
					When ������ between 201 and 300 then '201-300'
					When ������ between 301 and 400 then '301-400'
					When ������ between 401 and 700 then '401-700'
					else '������ < 0 | ������ > 700'
					end) as T
						ORDER BY CASE [��������_������]
							When '401-700' then 1
							When '301-400' then 2
							When '201-300' then 3
							When '100-200' then 4
							else '������ < 0 | ������ > 700'
							end


SELECT ROUND(AVG(CAST(�������.������ as float(4))),2) [AVG],
		�������������.�������_�������������
FROM ������� INNER JOIN �������������
ON �������.���_������������� = �������������.���_�������������
GROUP BY �������������.�������_�������������
ORDER BY ROUND(AVG(CAST(�������.������ as float(4))),2) DESC


SELECT ROUND(AVG(CAST(�������.������ as float(4))),2) [AVG],
		�������������.�������_�������������
FROM ������� INNER JOIN �������������
ON �������.���_������������� = �������������.���_�������������
WHERE �������.���_������� = '������������'
GROUP BY �������������.�������_�������������
ORDER BY ROUND(AVG(CAST(�������.������ as float(4))),2) DESC


SELECT ROUND(AVG(CAST(�������.����������_����� as float(4))),2) [AVG],
		������.�������������
FROM ������ INNER JOIN �������
ON ������.�����_������ = �������.�����_������
WHERE ������.������������� IN ('��', '��')
GROUP BY ������.�������������
ORDER BY ROUND(AVG(CAST(�������.����������_����� as float(4))),2) DESC


SELECT A1.���_�������������, 
	(SELECT COUNT(*) FROM ������� A2
		WHERE A2.������ = A1.������ AND
			A2.���_������������� = A1.���_�������������) [���������� �������]
FROM ������� A1
GROUP BY A1.���_�������������, A1.������
HAVING A1.������ = 200 OR A1.������ = 400
ORDER BY [���������� �������] DESC
#include "heap.h"
#include <iostream>

using namespace std;
using namespace heap;

// Функция сравнения элементов AAA для кучи
CMP cmpAAA(void* a1, void* a2)
{
#define A1 ((AAA*)a1)
#define A2 ((AAA*)a2)

	CMP rc = EQUAL;  // Устанавливаем равенство по умолчанию

	if (A1->x > A2->x)
		rc = GREAT;
	else
		if (A2->x > A1->x)
			rc = LESS;

	return rc;

#undef A2
#undef A1 
}

int main()
{
	setlocale(LC_ALL, "rus");

	int k, choice;

	// Создание двух куч h1 и h2
	Heap h1 = create(30, cmpAAA);
	Heap h2 = create(30, cmpAAA);

	// Указатель на вторую кучу
	Heap* ph2 = &h2;

	for (;;)
	{
		cout << "1 - Вывод кучи на экран" << endl;
		cout << "2 - Добавить элемент" << endl;
		cout << "3 - Удалить максимальный элемент" << endl;
		cout << "4 - Удалить минимальный элемент" << endl;
		cout << "5 - Удалить i-ый элемент" << endl;
		cout << "6 - Объединение двух бинарных куч (конец - ввод отрицательного числа)" << endl;
		cout << "0 - Выход" << endl;
		cout << "Cделайте выбор:" << endl;  
		cin >> choice;

		switch (choice)
		{
		case 0:  exit(0);
		case 1:  h1.scan(0);
			break;
		case 2: 
		{
			AAA* a = new AAA;

			cout << "Введите ключ:" << endl; 	
			cin >> k;

			a->x = k;
			h1.insert(a);
		}
			  break;
		case 3:   h1.extractMax();
			break;
		case 4:   h1.extractMin();
			break;
		case 5:
			int i;

			cout << "Введите i:\n";
			cin >> i;

			h1.extractI(i);
			break;
		case 6:
			int j = 1;

			cout << "Введите вторую кучу:\n";

			while (j > 0)  // Цикл ввода данных для второй кучи
			{
				AAA* b = new AAA;


				cout << "Введите ключ:" << endl; 	
				cin >> j;

				if (j > 0)
				{
					b->x = j;
					h2.insert(b);
				}
			}

			// Вызов метода объединения двух куч
			h1.unionHeap(ph2);
			break;
		}
	} 
	
	return 0;
}
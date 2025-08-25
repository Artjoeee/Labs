#include "Hash.h"
#include <iostream>
#include <string>
#include <ctime>

// Объявление пользовательской структуры AAA
struct AAA
{
	int key;  // Целочисленное значение ключа
	const char* mas;  // Указатель на строку

	// Конструктор с параметрами
	AAA(int k, const char z[])
	{
		key = k;  mas = z;
	} AAA() {}  // Конструктор по умолчанию
};

// Функция вычисления ключа
int key(void* d)
{
	AAA* f = (AAA*)d;   
	
	return f->key;
}

// Функция печати элемента AAA
void AAA_print(void* d)
{
	cout << " Ключ " << ((AAA*)d)->key << " - " << ((AAA*)d)->mas << endl;
}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "rus");

	int siz, choice;
	int k;

	cout << "Введите размер хеш-таблицы: "; 	
	cin >> siz;

	Object H = create(siz, key); // Создание хеш - таблицы с указанным размером и функцией хеширования

	for (;;)
	{
		cout << "1 - Вывод хеш-таблицы" << endl;
		cout << "2 - Добавление элемента" << endl;
		cout << "3 - Удаление элемента" << endl;
		cout << "4 - Поиск элемента" << endl;
		cout << "0 - Выход" << endl;

		cout << "Сделайте выбор: ";   
		cin >> choice;

		switch (choice)
		{
		case 0: exit(0);  // Выход из программы
		case 1:
		{
			H.scan(AAA_print);  // Вывод содержимого хеш-таблицы

			
		} 
		break;
		case 2: 
		{
			AAA* a = new AAA;

			char* str = new char[20];

			cout << "Введите ключ: ";	
			cin >> k;;

			a->key = k;

			cout << "Введите строку: "; 
			cin >> str;

			a->mas = str;

			if (H.N == H.size)
			{
				cout << "Таблица заполнена" << endl;
			}
			else
			{
				H.insert(a);  // Добавление элемента в хеш-таблицу
			}
		} 
		break;
		case 3: 
		{
			cout << "Введите ключ для удаления: ";
			cin >> k;

			H.deleteByKey(k);  // Удаление элемента по ключу
		}  
		break;
		case 4: 
		{
			cout << "Введите ключ для поиска: ";
			cin >> k;

			if (H.search(k) == NULL)
			{
				cout << "Элемент не найден" << endl;
			}
			else
			{
				AAA_print(H.search(k));  // Поиск и печать элемента по ключу
			}
		}  
		break;
		}
	}

	return 0;
}
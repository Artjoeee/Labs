#include "Hash.h"
#include <iostream>

// Функция универсального хеширования
int HashFunction(int key, int size)
{
	// Генерация случайных коэффициентов a и b
	int a = rand() % size + 1;
	int b = rand() % size - 1;

	int p = 10000001;

	// Вычисление хеша с использованием универсальной хеш-функции
	return ((a * key + b) % p) % size;
}

//Функция модульного хеширования
//int HashFunction(int key, int size)    
//{
//	return key % 32;
//}

// Функция перехеширования
int Next_hash(int hash, int size)
{
	int p = 10000001;

	// Вычисление нового хеша с использованием метода перехеширования
	return (hash + 1) % size;
}

// Создание объекта хеш-таблицы
Object create(int size, int(*getkey)(void*))
{
	return *(new Object(size, getkey));
}

// Конструктор класса Object
Object::Object(int size, int(*getkey)(void*))
{
	N = 0;

	this->size = size;
	this->getKey = getkey;
	this->data = new void* [size];

	// Инициализация хеш-таблицы пустыми указателями
	for (int i = 0; i < size; ++i)
	{
		data[i] = NULL;
	}
}

// Вставка элемента в хеш-таблицу
bool Object::insert(void* d)
{
	bool b = false;
	

	if (N != size)
	{ 
		// Поиск свободного слота для вставки элемента
		for (int i = 0, t = getKey(d), j = HashFunction(t, size); i != size && !b; j = Next_hash(j, size))
		{
			if (data[j] == NULL || data[j] == DEL)
			{				
				data[j] = d;  // Вставка элемента
				N++;  // Увеличение счетчика элементов

				b = true;
			}
		}
	}

	return b;  // Возвращение результата вставки
}

// Поиск индекса элемента по ключу
int Object::searchInd(int key)
{
	bool find = false;

	int hash_index = HashFunction(key, size);

	// Цикл поиска элемента
	while (!find)
	{
		if (data[hash_index] != NULL && data[hash_index] != DEL && getKey(data[hash_index]) == key)
		{
			find = true;

			return hash_index;  // Возвращение найденного индекса
		}

		hash_index = Next_hash(hash_index, size);  // Переход к следующему хешу
	}
}

// Поиск элемента по ключу
void* Object::search(int key)
{
	int t = searchInd(key);

	return(t >= 0) ? (data[t]) : (NULL);  // Возвращение найденного элемента или NULL
}

// Удаление элемента по ключу
void* Object::deleteByKey(int key)
{
	int i = searchInd(key);

	void* t = data[i];  // Сохранение удаленного элемента

	if (t != NULL)
	{
		data[i] = DEL;  // Пометка элемента как удаленного
		N--;  // Уменьшение счетчика элементов
	}

	return t;  // Возвращение удаленного элемента
}

// Удаление элемента по значению
bool Object::deleteByValue(void* d)
{
	return(deleteByKey(getKey(d)) != NULL);  // Удаление элемента по ключу
}

// Просмотр всех элементов в хеш-таблице
void Object::scan(void(*f)(void*))
{
	for (int i = 0; i < this->size; i++)
	{
		cout << " Элемент " << i;

		if ((this->data)[i] == NULL)
		{
			cout << "  Пусто" << endl;  // Вывод информации о пустом слоте
		}
		else
		{
			if ((this->data)[i] == DEL)
			{
				cout << "  Удален" << endl;  // Вывод информации о удаленном элементе
			}
			else
			{	
				f((this->data)[i]);  // Вызов пользовательской функции для распечатки элемента
			}	
		}
	}
}
#pragma once

#define HASHDEL (void*) -1

using namespace std;

// Объявление структуры Object для работы с хеш-таблицей
struct Object
{
	void** data;  // Указатель на данные
	Object(int, int(*)(void*));  // Конструктор структуры
	int size;  
	int N;
	int(*getKey)(void*);  // Указатель на функцию получения ключа
	bool insert(void*);  // Метод вставки элемента
	int searchInd(int key);
	void* search(int key);
	void* deleteByKey(int key);
	bool deleteByValue(void*);
	void scan(void(*f)(void*));  // Метод сканирования хеш-таблицы
};

static void* DEL = (void*)HASHDEL;  // Статическая переменная для обозначения удаленного элемента

Object create(int size, int(*getkey)(void*));  // Функция создания объекта хеш-таблицы

#undef HASHDEL
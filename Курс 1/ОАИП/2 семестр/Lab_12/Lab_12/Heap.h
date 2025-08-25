#pragma once

// Структура AAA для хранения целочисленных данных и соответствующих методов
struct AAA
{
	int x;
	void print() const;
	int getPriority() const;
};

namespace heap
{
	// Перечисление CMP для определения типов сравнения
	enum CMP
	{
		LESS = -1, EQUAL = 0, GREAT = 1
	};

	// Структура Heap для реализации кучи
	struct Heap
	{
		int size;
		int maxSize;

		void** storage; 

		CMP(*compare)(void*, void*);

		// Конструктор класса Heap
		Heap(int maxsize, CMP(*f)(void*, void*))
		{
			size = 0;
			storage = new void* [maxSize = maxsize];
			compare = f;
		};

		// Методы для работы с индексами в куче
		int left(int ix) const;
		int right(int ix) const;
		int parent(int ix);

		// Проверка на полноту и пустоту кучи
		bool isFull() const
		{
			return (size >= maxSize);
		};

		bool isEmpty() const
		{
			return (size <= 0);
		};

		// Методы сравнения элементов в куче
		bool isLess(void* x1, void* x2) const
		{
			return compare(x1, x2) == LESS;
		};

		bool isGreat(void* x1, void* x2) const
		{
			return compare(x1, x2) == GREAT;
		};

		bool isEqual(void* x1, void* x2) const
		{
			return compare(x1, x2) == EQUAL;
		};


		void swap(int i, int j);
		void heapify(int ix);
		void insert(void* x);
		void* extractMax();
		void* extractMin();  // Метод извлечения минимального элемента
		void* extractI(int i);  // Метод извлечения элемента по индексу
		void scan(int i) const;
		void unionHeap(Heap* h2);  // Метод объединения двух куч
	};

	// Функция создания кучи с заданным размером и функцией сравнения
	Heap create(int maxsize, CMP(*f)(void*, void*));
};
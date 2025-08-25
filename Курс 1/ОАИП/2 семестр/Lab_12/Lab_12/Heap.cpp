#include "heap.h"
#include <iostream>
#include <iomanip>

using namespace std;

// Метод печати данных из объекта AAA
void AAA::print() const
{
	cout << x;
}

// Метод получения приоритета
int AAA::getPriority() const
{
	return x;
}

namespace heap
{
	// Функция создания объекта класса Heap
	Heap create(int maxsize, CMP(*f)(void*, void*))
	{
		return *(new Heap(maxsize, f));
	}

	// Метод определения левого потомка элемента по индексу ix
	int Heap::left(int ix) const
	{
		return (2 * ix + 1 >= size) ? -1 : (2 * ix + 1);
	}

	// Метод определения правого потомка элемента по индексу ix
	int Heap::right(int ix) const
	{
		return (2 * ix + 2 >= size) ? -1 : (2 * ix + 2);
	}

	// Метод определения родителя элемента по индексу ix
	int Heap::parent(int ix)
	{
		return (ix + 1) / 2 - 1;
	}

	// Метод обмена данных между двумя элементами
	void Heap::swap(int i, int j)
	{
		void* buf = storage[i];

		storage[i] = storage[j];
		storage[j] = buf;
	}

	// Метод просеивания элемента вниз по куче
	void Heap::heapify(int ix)
	{
		int l = left(ix), r = right(ix), irl = ix;

		if (l > 0)
		{
			if (isGreat(storage[l], storage[ix]))
				irl = l;

			if (r > 0 && isGreat(storage[r], storage[irl]))
				irl = r;

			if (irl != ix)
			{
				swap(ix, irl);
				heapify(irl);
			}
		}
	}

	// Метод добавления нового элемента в кучу
	void Heap::insert(void* x)
	{
		int i;

		if (!isFull())
		{
			storage[i = ++size - 1] = x;

			while (i > 0 && isLess(storage[parent(i)], storage[i]))
			{
				swap(parent(i), i);
				i = parent(i);
			}
		}
	}

	// Метод извлечения максимального элемента из кучи
	void* Heap::extractMax()
	{
		void* rc = nullptr;

		if (!isEmpty())
		{
			rc = storage[0];

			storage[0] = storage[size - 1];
			size--;

			heapify(0);
		} 

		return rc;
	}

	// Метод вывода данных кучи на экран
	void Heap::scan(int i) const
	{
		int probel = 20;

		cout << '\n';

		if (size == 0)
			cout << "Куча пуста";

		for (int u = 0, y = 0; u < size; u++)
		{
			cout << setw(probel + 10) << setfill(' ');

			((AAA*)storage[u])->print();

			if (u == y)
			{
				cout << '\n';

				if (y == 0)
					y = 2;
				else
					y += y * 2;
			}

			probel /= 2;
		}

		cout << '\n';
	}

	// Метод удаления минимального элемента
	void* Heap::extractMin()
	{
		void* rc = nullptr;

		// Проверка на пустоту
		if (!isEmpty())
		{
			// Смещаем данные в массиве и уменьшаем size 
			rc = storage[size];

			storage[size] = storage[0];
			size--;

			heapify(size);
		} 
		
		return rc;
	}

	// Метод удаления по индексу
	void* Heap::extractI(int i)
	{
		void* rc = nullptr;

		// Проверка на пустоту
		if (!isEmpty())
		{
			// Смещаем данные в массиве
			rc = storage[i];

			storage[i] = storage[size - 1];
			size--;

			heapify(i);
		}
		
		return rc;
	}

	// Метод объединения двух куч
	void Heap::unionHeap(Heap* h2)
	{
		void* rc = nullptr;

		// Записываем данные и добавляем элементы в главную кучу
		for (int i = 0; i < h2->size; i++)
		{
			rc = h2->storage[i];

			insert(rc);
		}

		heapify(0);
	}
}
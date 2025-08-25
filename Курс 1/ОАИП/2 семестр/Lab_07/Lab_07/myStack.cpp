#include <iostream>
#include <fstream>
#include "myStack.h"

using namespace std;

void push(char x, Stack*& myStk)  // Добавление элемента х в стек	
{
	Stack* e = new Stack;  // Выделение памяти для нового элемента

	e->data = x;  // Запись элемента x в поле data 
	e->next = myStk;  // Перенос вершины на следующий элемент

	myStk = e;  // Сдвиг вершины на позицию вперед
}

char pop(Stack*& myStk)  // Извлечение (удаление) элемента из стека
{
	if (myStk == NULL)
	{
		cout << "\nСтек пуст!\n\n" << endl;

		return -1;  // Если стек пуст - возврат (-1) 
	}
	else
	{
		Stack* e = myStk;  // е-переменная для хранения адреса элемента

		char x = myStk->data;  // Запись элемента из поля data в перем. x 

		if (myStk)
			myStk = myStk->next;  // Перенос вершины

		delete e;

		return x;
	}
}

// Функция записи в файл
void toFile(Stack*& myStk)  
{
	Stack* e = myStk;
	Stack buf;

	ofstream frm("text.txt");

	if (frm.fail())
	{
		cout << "\nОшибка открытия файла\n";
		exit(1);
	}

	while (e)
	{
		buf = *e;

		frm.write((char*)&buf, sizeof(Stack));

		e = e->next;
	}

	frm.close();

	cout << "\nСтек записан в файл text.txt\n\n";
}

// Функция считывания из файла
void fromFile(Stack*& myStk)  
{
	Stack buf{}, * p = nullptr, * e = nullptr;

	ifstream frm("text.txt");

	if (frm.fail())
	{
		cout << "\nОшибка открытия файла\n";
		exit(1);
	}

	frm.seekg(0);

	frm.read((char*)&buf, sizeof(Stack));

	while (!frm.eof())
	{
		push(buf.data, e);

		frm.read((char*)&buf, sizeof(Stack));
	}

	frm.close();

	while (e != NULL)
	{
		buf.data = pop(e);

		push(buf.data, p);

		myStk = p;
	}

	cout << "\nСтек считан из файла text.txt\n\n";
}

// Функция вывода
void show(Stack*& myStk)
{
	Stack* e = myStk;

	if (e == NULL)
	{
		cout << "\nСтек пуст!\n\n";

		return;
	}

	cout << "\nСодержимое стека: ";

	while (e != NULL)
	{
		cout << e->data << " ";

		e = e->next;
	}

	cout << endl << endl;
}

// Функция очистки
void clear(Stack*& myStk)
{
	while (myStk != NULL)
	{
		pop(myStk);
	}

	cout << "\nСтек очищен.\n" << endl;
}

// Функция, которая определяет, есть ли в стеке элемент, равный следующему за ним элементу.
bool hasEqualNextElement(Stack*& myStk)
{
	Stack* current = myStk;

	while (current != NULL && current->next != NULL)
	{
		if (current->data == current->next->data)
		{
			return true;
		}

		current = current->next;
	}

	return false;
}
#include <iostream>
#include <fstream>
#include "head.h"

using namespace std;

void push(int x, Stack*& myStk)
{
    Stack* e = new Stack;
    e->data = x;
    e->next = myStk;
    e->prev = NULL;

    // Обновление указателя на предыдущий элемент
    if (myStk)
    {
        myStk->prev = e;
    }

    // Обновление верхнего узла
    myStk = e;
}

int pop(Stack*& myStk)
{
    // Проверка на пустой стек
    if (myStk == NULL)
    {
        cout << "Стек пуст!" << endl;
        return -1;
    }
    else
    {
        // Извлечение верхнего элемента
        Stack* e = myStk;
        int x = myStk->data;

        myStk = myStk->next;

        // Обновление указателя на предыдущий элемент
        if (myStk)
        {
            myStk->prev = NULL;
        }

        delete e;

        return x;
    }
}

void toFile(Stack*& myStk)
{
    Stack* e = myStk;
    Stack buf;

    // Открытие файла для записи
    ofstream frm("File.txt");

    if (frm.fail())
    {
        cout << "\nОшибка открытия файла\n";
        exit(1);
    }

    // Запись стека в файл
    while (e)
    {
        buf = *e;
        frm.write((char*)&buf, sizeof(Stack));
        e = e->next;
    }

    // Закрытие файла
    frm.close();

    cout << "Стек записан в файл File.txt\n";
}

void fromFile(Stack*& myStk)
{
    Stack buf{}, * p = nullptr, * e = nullptr;

    // Открытие файла для чтения
    ifstream frm("File.txt");

    if (frm.fail())
    {
        cout << "\nОшибка открытия файла\n";
        exit(1);
    }

    // Чтение стека из файла
    frm.seekg(0);
    frm.read((char*)&buf, sizeof(Stack));

    while (!frm.eof())
    {
        push(buf.data, e);
        frm.read((char*)&buf, sizeof(Stack));
    }

    frm.close();

    // Перестройка стека
    while (e != NULL)
    {
        buf.data = pop(e);
        push(buf.data, p);
        myStk = p;
    }

    // Вывод сообщения об успешном чтении
    cout << "\nСтек считан из файла File.txt\n\n";
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

void removeFirstNegative(Stack*& myStk)
{
    Stack* current = myStk;

    // Поиск и удаление первого отрицательного элемента
    while (current != NULL)
    {
        if (current->data < 0)
        {
            if (current->prev)
            {
                current->prev->next = current->next;
            }
            if (current->next)
            {
                current->next->prev = current->prev;
            }

            if (current == myStk)
            {
                myStk = myStk->next;
            }

            delete current;

            cout << "\nПервый отрицательный элемент удален\n";
            return;
        }

        current = current->next;
    }

    cout << "\nОтрицательный элемент не найден\n";
}
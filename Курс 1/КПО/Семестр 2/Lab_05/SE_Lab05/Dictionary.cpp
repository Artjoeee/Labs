#include "stdafx.h"
#include <iostream>
#include <locale>
#include "Dictionary.h"

using namespace std;
using namespace Dictionary;

int main()
{
    setlocale(0, "ru");

    try
    {
        // Создание словаря для преподавателей
        Instance d1 = Create("Преподаватели", 5);

        // Элементы словаря для преподавателей
        Entry e1 = { 1, "Гладкий" }, e2 = { 2, "Веялкин" }, e3 = { 3, "Смелов" }, e4 = { 4, "Урбанович" }, e5 = { 5, "Пацей" };

        // Добавление элементов в словарь
        AddEntry(d1, e1);
        AddEntry(d1, e2);
        AddEntry(d1, e3);
        AddEntry(d1, e4);

        // Нахождение элемента в словаре по идентификатору
        Entry ex2 = GetEntry(d1, 4);

        // Удаление элемента из словаря по идентификатору
        DelEntry(d1, 2);

        // Новый элемент для замены
        Entry newentry1 = { 6, "Гурин" };

        // Замена элемента словаря по идентификатору
        UpdEntry(d1, 3, newentry1);

        // Вывод элементов словаря
        Print(d1);

        // Создание словаря для студентов
        Instance d2 = Create("Студенты", 5);

        // Элементы словаря для студентов
        Entry s1 = { 1, "Иванов" }, s2 = { 2, "Петров" }, s3 = { 3, "Сидоров" };

        // Добавление элементов в словарь
        AddEntry(d2, s1);
        AddEntry(d2, s2);
        AddEntry(d2, s3);

        // Новый элемент для замены
        Entry newentry3 = { 3, "Николаев" };

        // Замена элемента словаря по идентификатору
        UpdEntry(d2, 3, newentry3);

        // Вывод элементов словаря
        Print(d2);

        // Освобождение памяти, выделенной под словари
        Delete(d1);
        Delete(d2);
    }
    catch (char* e) // Обработка исключений словаря
    {
        cout << e << endl;
    };

    system("pause");

    return 0;
}

namespace Dictionary
{
    // Создание нового экземпляра словаря
    Instance Create(const char name[DICTNAMEMAXSIZE], int size)
    {
        if (strlen(name) > DICTNAMEMAXSIZE)
        {
            throw THROW01; // Превышен размер имени словаря
        }

        if (size > DICTMAXSIZE)
        {
            throw THROW02; // Превышен размер максимальной емкости словаря
        }

        Instance new_instance{};

        strcpy_s(new_instance.name, name);

        new_instance.maxsize = size;
        new_instance.size = 0;
        new_instance.dictionary = new Entry[DICTMAXSIZE];

        return new_instance;
    }

    // Добавление элемента в словарь
    void AddEntry(Instance& inst, Entry ed)
    {
        if (inst.size >= inst.maxsize)
        {
            throw THROW03; // Переполнение словаря
        }

        // Проверка на наличие дубликатов
        for (int i = 0; i < inst.size; ++i)
        {
            if (inst.dictionary[i].id == ed.id)
            {
                throw THROW04; // Дублирование идентификатора
            }
        }

        // Добавление нового элемента
        inst.dictionary[inst.size] = ed;
        inst.size++;
    }

    // Удаление элемента из словаря
    void DelEntry(Instance& inst, int id)
    {
        int pos = -1;

        // Поиск элемента по идентификатору
        for (int i = 0; i < inst.size; ++i)
        {
            if (inst.dictionary[i].id == id)
            {
                pos = i;
                break;
            }
        }

        // Если элемент не найден, генерируется исключение
        if (pos == -1)
        {
            throw THROW06; // Не найден элемент
        }

        // Сдвиг элементов для удаления элемента
        for (int i = pos; i < inst.size - 1; i++)
        {
            inst.dictionary[i] = inst.dictionary[i + 1];
        }

        // Уменьшение размера словаря
        inst.size--;
    }

    // Обновление элемента словаря
    void UpdEntry(Instance& inst, int id, Entry new_ed)
    {
        int pos = -1;

        // Поиск элемента по идентификатору
        for (int i = 0; i < inst.size; ++i)
        {
            if (inst.dictionary[i].id == id)
            {
                pos = i;
                break;
            }
        }

        // Если элемент не найден, генерируется исключение
        if (pos == -1)
        {
            throw THROW07; // Не найден элемент
        }

        // Проверка на наличие дубликатов
        for (int i = 0; i < inst.size; ++i)
        {
            if (i != pos && inst.dictionary[i].id == new_ed.id)
            {
                throw THROW08; // Дублирование идентификатора
            }
        }

        // Обновление элемента словаря
        inst.dictionary[pos] = new_ed;
    }

    // Получение элемента словаря по идентификатору
    Entry GetEntry(Instance inst, int id)
    {
        // Поиск элемента по идентификатору
        for (int i = 0; i < inst.size; ++i)
        {
            if (inst.dictionary[i].id == id)
            {
                return inst.dictionary[i];
            }
        }

        // Если элемент не найден, генерируется исключение
        throw THROW05; // Не найден элемент
    }

    // Вывод всех элементов словаря
    void Print(Instance d)
    {
        cout << "---------- " << d.name << " ----------" << endl;

        // Вывод всех элементов словаря
        for (int i = 0; i < d.size; ++i)
        {
            cout << d.dictionary[i].id << " " << d.dictionary[i].name << endl;
        }
    }

    // Освобождение памяти, выделенной под словарь
    void Delete(Instance& d)
    {
        delete[] d.dictionary;
    }
}
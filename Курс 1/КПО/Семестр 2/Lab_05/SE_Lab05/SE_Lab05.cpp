#include "stdafx.h"
#include "Dictionary.h"
#include <iostream>
#include <locale>

using namespace std;
using namespace Dictionary;

int tmain()
{
    setlocale(0, "ru");

#ifdef TEST_CREATE_01  // Тест функции Create: проверка генерации исключения THROW01
    try
    {
        Instance d = Create("Очень большое наименование словаря", 5);
    }
    catch (const char* e)
    {
        cout << e << endl;
    }
#endif

#ifdef TEST_CREATE_02  // Тест функции Create: проверка генерации исключения THROW02
    try
    {
        Instance d = Create("Преподаватели", 150);
    }
    catch (const char* e)
    {
        cout << e << endl;
    }
#endif

#ifdef TEST_ADDENTRY_03  // Тест функции AddEntry: проверка генерации исключения THROW03
    Instance d = Create("Студенты", 10);

    for (int i = 1; i <= 11; ++i)
    {
        Entry e = { i, "Студент" };

        try
        {
            AddEntry(d, e);
        }
        catch (const char* e)
        {
            cout << e << endl;
        }
    }
#endif

#ifdef TEST_ADDENTRY_04  // Тест функции AddEntry: проверка генерации исключения THROW04
    Instance d = Create("Преподаватели", 5);

    Entry e1 = { 1, "Преподаватель" };

    AddEntry(d, e1);

    Entry e2 = { 1, "Преподаватель" };

    try
    {
        AddEntry(d, e2);
    }
    catch (const char* e)
    {
        cout << e << endl;
    }
#endif

#ifdef TEST_GETENTRY_05  // Тест функции GetEntry: проверка генерации исключения THROW05
    Instance d = Create("Словарь", 5);

    Entry e1 = { 1, "Элемент" };

    AddEntry(d, e1);

    try
    {
        Entry entry = GetEntry(d, 2);
    }
    catch (const char* e)
    {
        cout << e << endl;
    }
#endif

#ifdef TEST_DELENTRY_06  // Тест функции DelEntry: проверка генерации исключения THROW06
    Instance d = Create("Словарь", 5);

    Entry e1 = { 1, "Элемент" };

    AddEntry(d, e1);

    try
    {
        DelEntry(d, 2);
    }
    catch (const char* e)
    {
        cout << e << endl;
    }
#endif

#ifdef TEST_UPDENTRY_07  // Тест функции UpdEntry: проверка генерации исключения THROW07
    Instance d = Create("Словарь", 5);

    Entry e1 = { 1, "Элемент" };

    AddEntry(d, e1);

    Entry newEntry = { 2, "Новый элемент" };

    try
    {
        UpdEntry(d, 2, newEntry);
    }
    catch (const char* e)
    {
        cout << e << endl;
    }
#endif

#ifdef TEST_UPDENTRY_08  // Тест функции UpdEntry: проверка генерации исключения THROW08
    Instance d = Create("Словарь", 5);

    Entry e1 = { 1, "Элемент 1" };

    Entry e2 = { 2, "Элемент 2" };

    AddEntry(d, e1);
    AddEntry(d, e2);

    Entry newEntry = { 2, "Элемент" };

    try
    {
        UpdEntry(d, 1, newEntry);
    }
    catch (const char* e)
    {
        cout << e << endl;
    }
#endif

#ifdef TEST_DICTIONARY  // Демонстрирует успешное выполнение всех функций
    try
    {   
        Instance students_dict = Create("Студенты", 7);
        Instance teachers_dict = Create("Преподаватели", 7);

        for (int i = 1; i <= 7; ++i)
        {
            Entry e = { i, "Студент" };

            AddEntry(students_dict, e);
        }

        for (int i = 1; i <= 7; ++i)
        {
            Entry e = { i, "Преподаватель" };

            AddEntry(teachers_dict, e);
        }

        Print(students_dict);

        Print(teachers_dict);
    }
    catch (const char* e)
    {
        cout << e << endl;
    }
#endif

#if defined(TEST_CREATE_01) + defined(TEST_CREATE_02) + defined(TEST_ADDENTRY_03) + defined(TEST_ADDENTRY_04) + defined(TEST_GETENTRY_05) + defined(TEST_DELENTRY_06) + defined(TEST_UPDENTRY_07) + defined(TEST_UPDENTRY_08) + defined(TEST_DICTIONARY) > 1
#error "Должен быть выбран только один тестовый пример"
#endif

#ifndef TEST_CREATE_01
#ifndef TEST_CREATE_02
#ifndef TEST_ADDENTRY_03
#ifndef TEST_ADDENTRY_04
#ifndef TEST_GETENTRY_05
#ifndef TEST_DELENTRY_06
#ifndef TEST_UPDENTRY_07
#ifndef TEST_UPDENTRY_08
#ifndef TEST_DICTIONARY
#error "Не выбран контрольный пример для компиляции"
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif

    system("pause");
    return 0;
}
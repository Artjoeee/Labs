#include <iostream>
#include <locale>
#include "Dictionary.h"

using namespace std;
using namespace Dictionary;

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
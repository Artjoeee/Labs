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
        // �������� ������� ��� ��������������
        Instance d1 = Create("�������������", 5);

        // �������� ������� ��� ��������������
        Entry e1 = { 1, "�������" }, e2 = { 2, "�������" }, e3 = { 3, "������" }, e4 = { 4, "���������" }, e5 = { 5, "�����" };

        // ���������� ��������� � �������
        AddEntry(d1, e1);
        AddEntry(d1, e2);
        AddEntry(d1, e3);
        AddEntry(d1, e4);

        // ���������� �������� � ������� �� ��������������
        Entry ex2 = GetEntry(d1, 4);

        // �������� �������� �� ������� �� ��������������
        DelEntry(d1, 2);

        // ����� ������� ��� ������
        Entry newentry1 = { 6, "�����" };

        // ������ �������� ������� �� ��������������
        UpdEntry(d1, 3, newentry1);

        // ����� ��������� �������
        Print(d1);

        // �������� ������� ��� ���������
        Instance d2 = Create("��������", 5);

        // �������� ������� ��� ���������
        Entry s1 = { 1, "������" }, s2 = { 2, "������" }, s3 = { 3, "�������" };

        // ���������� ��������� � �������
        AddEntry(d2, s1);
        AddEntry(d2, s2);
        AddEntry(d2, s3);

        // ����� ������� ��� ������
        Entry newentry3 = { 3, "��������" };

        // ������ �������� ������� �� ��������������
        UpdEntry(d2, 3, newentry3);

        // ����� ��������� �������
        Print(d2);

        // ������������ ������, ���������� ��� �������
        Delete(d1);
        Delete(d2);
    }
    catch (char* e) // ��������� ���������� �������
    {
        cout << e << endl;
    };

    system("pause");

    return 0;
}

namespace Dictionary
{
    // �������� ������ ���������� �������
    Instance Create(const char name[DICTNAMEMAXSIZE], int size)
    {
        if (strlen(name) > DICTNAMEMAXSIZE)
        {
            throw THROW01; // �������� ������ ����� �������
        }

        if (size > DICTMAXSIZE)
        {
            throw THROW02; // �������� ������ ������������ ������� �������
        }

        Instance new_instance{};

        strcpy_s(new_instance.name, name);

        new_instance.maxsize = size;
        new_instance.size = 0;
        new_instance.dictionary = new Entry[DICTMAXSIZE];

        return new_instance;
    }

    // ���������� �������� � �������
    void AddEntry(Instance& inst, Entry ed)
    {
        if (inst.size >= inst.maxsize)
        {
            throw THROW03; // ������������ �������
        }

        // �������� �� ������� ����������
        for (int i = 0; i < inst.size; ++i)
        {
            if (inst.dictionary[i].id == ed.id)
            {
                throw THROW04; // ������������ ��������������
            }
        }

        // ���������� ������ ��������
        inst.dictionary[inst.size] = ed;
        inst.size++;
    }

    // �������� �������� �� �������
    void DelEntry(Instance& inst, int id)
    {
        int pos = -1;

        // ����� �������� �� ��������������
        for (int i = 0; i < inst.size; ++i)
        {
            if (inst.dictionary[i].id == id)
            {
                pos = i;
                break;
            }
        }

        // ���� ������� �� ������, ������������ ����������
        if (pos == -1)
        {
            throw THROW06; // �� ������ �������
        }

        // ����� ��������� ��� �������� ��������
        for (int i = pos; i < inst.size - 1; i++)
        {
            inst.dictionary[i] = inst.dictionary[i + 1];
        }

        // ���������� ������� �������
        inst.size--;
    }

    // ���������� �������� �������
    void UpdEntry(Instance& inst, int id, Entry new_ed)
    {
        int pos = -1;

        // ����� �������� �� ��������������
        for (int i = 0; i < inst.size; ++i)
        {
            if (inst.dictionary[i].id == id)
            {
                pos = i;
                break;
            }
        }

        // ���� ������� �� ������, ������������ ����������
        if (pos == -1)
        {
            throw THROW07; // �� ������ �������
        }

        // �������� �� ������� ����������
        for (int i = 0; i < inst.size; ++i)
        {
            if (i != pos && inst.dictionary[i].id == new_ed.id)
            {
                throw THROW08; // ������������ ��������������
            }
        }

        // ���������� �������� �������
        inst.dictionary[pos] = new_ed;
    }

    // ��������� �������� ������� �� ��������������
    Entry GetEntry(Instance inst, int id)
    {
        // ����� �������� �� ��������������
        for (int i = 0; i < inst.size; ++i)
        {
            if (inst.dictionary[i].id == id)
            {
                return inst.dictionary[i];
            }
        }

        // ���� ������� �� ������, ������������ ����������
        throw THROW05; // �� ������ �������
    }

    // ����� ���� ��������� �������
    void Print(Instance d)
    {
        cout << "---------- " << d.name << " ----------" << endl;

        // ����� ���� ��������� �������
        for (int i = 0; i < d.size; ++i)
        {
            cout << d.dictionary[i].id << " " << d.dictionary[i].name << endl;
        }
    }

    // ������������ ������, ���������� ��� �������
    void Delete(Instance& d)
    {
        delete[] d.dictionary;
    }
}
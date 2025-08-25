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

    // ���������� ��������� �� ���������� �������
    if (myStk)
    {
        myStk->prev = e;
    }

    // ���������� �������� ����
    myStk = e;
}

int pop(Stack*& myStk)
{
    // �������� �� ������ ����
    if (myStk == NULL)
    {
        cout << "���� ����!" << endl;
        return -1;
    }
    else
    {
        // ���������� �������� ��������
        Stack* e = myStk;
        int x = myStk->data;

        myStk = myStk->next;

        // ���������� ��������� �� ���������� �������
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

    // �������� ����� ��� ������
    ofstream frm("File.txt");

    if (frm.fail())
    {
        cout << "\n������ �������� �����\n";
        exit(1);
    }

    // ������ ����� � ����
    while (e)
    {
        buf = *e;
        frm.write((char*)&buf, sizeof(Stack));
        e = e->next;
    }

    // �������� �����
    frm.close();

    cout << "���� ������� � ���� File.txt\n";
}

void fromFile(Stack*& myStk)
{
    Stack buf{}, * p = nullptr, * e = nullptr;

    // �������� ����� ��� ������
    ifstream frm("File.txt");

    if (frm.fail())
    {
        cout << "\n������ �������� �����\n";
        exit(1);
    }

    // ������ ����� �� �����
    frm.seekg(0);
    frm.read((char*)&buf, sizeof(Stack));

    while (!frm.eof())
    {
        push(buf.data, e);
        frm.read((char*)&buf, sizeof(Stack));
    }

    frm.close();

    // ����������� �����
    while (e != NULL)
    {
        buf.data = pop(e);
        push(buf.data, p);
        myStk = p;
    }

    // ����� ��������� �� �������� ������
    cout << "\n���� ������ �� ����� File.txt\n\n";
}

// ������� ������
void show(Stack*& myStk)
{
    Stack* e = myStk;

    if (e == NULL)
    {
        cout << "\n���� ����!\n\n";

        return;
    }

    cout << "\n���������� �����: ";

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

    // ����� � �������� ������� �������������� ��������
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

            cout << "\n������ ������������� ������� ������\n";
            return;
        }

        current = current->next;
    }

    cout << "\n������������� ������� �� ������\n";
}
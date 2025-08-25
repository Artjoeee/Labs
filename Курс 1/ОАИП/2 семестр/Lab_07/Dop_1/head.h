#pragma once

struct Stack
{
    int data;     // �������������� �������
    Stack* next;   // ��������� �� ��������� �������
    Stack* prev;   // ��������� �� ���������� �������
};

// ���������
void show(Stack*& myStk);
int pop(Stack*& myStk);
void push(int x, Stack*& myStk);
void toFile(Stack*& myStk);
void fromFile(Stack*& myStk);
void removeFirstNegative(Stack*& myStk);
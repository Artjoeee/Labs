#pragma once

struct Stack
{
    int data;     // Информационный элемент
    Stack* next;   // Указатель на следующий элемент
    Stack* prev;   // Указатель на предыдущий элемент
};

// Прототипы
void show(Stack*& myStk);
int pop(Stack*& myStk);
void push(int x, Stack*& myStk);
void toFile(Stack*& myStk);
void fromFile(Stack*& myStk);
void removeFirstNegative(Stack*& myStk);
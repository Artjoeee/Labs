#include <iostream>
#include <cstdio>
#include <conio.h>

int main()
{

    setlocale(LC_ALL, "RU");

    int b;
    

    printf("������� ����� 3 (������ ��������������): ");
    scanf_s("%d", &b);
    
    int a = 2 * b;
    int p = 2 * (a + b);
    int s = a * b;

    printf("������� ��������������: %d\n", s);
    printf("�������� ��������������: %d\n", p);
    printf("��������� ��������������: %d\n", a);

    return 0;

}
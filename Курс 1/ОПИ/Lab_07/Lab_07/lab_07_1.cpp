#include <iostream>
#include <Windows.h>
#include "case.h"

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int number;

    cout << "�������� ������� ������������� (1-4): ";

    cin >> number;

    switch (number)
    {
        case 1: getDifference1();
        
            break;

        case 2: getDifference2();
        
            break;

        case 3: getCode3();
        
            break;

        case 4: puts("����� ���������");

            break;

        default: puts("������� ������ ������� �������������");

            break;
    }

    return 0;
}
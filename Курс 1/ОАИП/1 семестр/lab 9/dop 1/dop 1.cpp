#include <iostream>
#include <Windows.h>
#include "case.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");

    int n, c = 0;

    cout << "�������� ������� ������������� (1-4): ";
    cin >> n;

    switch (n)
    {
    case 1: case1();
        c;
        break;

    case 2: case2();
        c;
        break;

    case 3: case3();
        c;
        break;

    case 4: puts("����� ���������");
        break;

    default: puts("������� ������ ������� �������������");
        break;
    }

    return 0;
}
#include "case.h"
#include <iostream>

using namespace std;

int getDifference2()
{
    char symbol;

    for (int i = 0; i < 4; i++)
    {
        puts("������� ������");

        cin >> symbol;

        if (symbol >= '�' && symbol <= '�')
        {
            int lower, upper, difference;

            lower = int(symbol);
            upper = int(symbol - 32);
            difference = upper - lower;

            cout << "������� �������� ����� � Windows-1251: " << difference << endl;
        }

        else if (symbol >= '�' && symbol <= '�')
        {
            int lower, upper, difference;

            lower = int(symbol + 32);
            upper = int(symbol);
            difference = upper - lower;

            cout << "������� �������� ����� � Windows-1251: " << difference << endl;
        }

        else
        {
            cout << "������ ������, �� ���������� ������� ������" << endl;
        }
    }

    return 0;
}
#include "case.h"
#include <iostream>

using namespace std;

int getCode3()
{
    char symbol;

    for (int i = 0; i < 4; i++)
    {
        puts("������� ������");

        cin >> symbol;

        if (symbol >= '0' && symbol <= '9')
        {
            int code;

            code = int(symbol);

            cout << "��� �������: " << code << endl;
        }

        else
        {
            cout << "������ ������, �� ���������� ������" << endl;
        }
    }

    return 0;
}
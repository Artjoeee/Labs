#include "case.h"
#include <iostream>

using namespace std;

int case2()
{
    char s;

    for (int i = 0; i < 4; i++)
    {
        puts("������� ������");

        cin >> s;

        if (s >= '�' && s <= '�')
        {
            int l, u, d;

            l = int(s);
            u = int(s - 32);
            d = u - l;

            cout << "������� �������� ����� � Windows-1251: " << d << endl;
        }

        else if (s >= '�' && s <= '�')
        {
            int l, u, d;

            l = int(s + 32);
            u = int(s);
            d = u - l;

            cout << "������� �������� ����� � Windows-1251: " << d << endl;
        }

        else
        {
            cout << "������ ������, �� ���������� ������� ������" << endl;
        }
    }

    return 0;
}
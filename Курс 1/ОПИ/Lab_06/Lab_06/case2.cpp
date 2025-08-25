#include "case.h"
#include <iostream>

using namespace std;

int case2()
{
    char s;

    for (int i = 0; i < 4; i++)
    {
        puts("Введите символ");

        cin >> s;

        if (s >= 'а' && s <= 'я')
        {
            int l, u, d;

            l = int(s);
            u = int(s - 32);
            d = u - l;

            cout << "Разница значений кодов в Windows-1251: " << d << endl;
        }

        else if (s >= 'А' && s <= 'Я')
        {
            int l, u, d;

            l = int(s + 32);
            u = int(s);
            d = u - l;

            cout << "Разница значений кодов в Windows-1251: " << d << endl;
        }

        else
        {
            cout << "Введен символ, не являющийся русской буквой" << endl;
        }
    }

    return 0;
}
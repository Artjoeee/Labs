#include "case.h"
#include <iostream>

using namespace std;

int case1()
{
    char s;

    for (int i = 0; i < 4; i++)
    {
        puts("Введите символ");

        cin >> s;

        if (s >= 'a' && s <= 'z')
        {
            int l, u, d;

            l = int(s);
            u = int(s - 32);
            d = u - l;

            cout << "Разница значений кодов в ASCII: " << d << endl;
        }

        else if (s >= 'A' && s <= 'Z')
        {
            int l, u, d;

            l = int(s + 32);
            u = int(s);
            d = u - l;

            cout << "Разница значений кодов в ASCII: " << d << endl;
        }

        else
        {
            cout << "Введен символ, не являющийся латинской буквой" << endl;
        }   
    }

    return 0;
}
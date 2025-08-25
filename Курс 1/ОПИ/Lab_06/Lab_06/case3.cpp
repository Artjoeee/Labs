#include "case.h"
#include <iostream>

using namespace std;

int case3()
{
    char s;

    for (int i = 0; i < 4; i++)
    {
        puts("Введите символ");

        cin >> s;

        if (s >= '0' && s <= '9')
        {
            int k;

            k = int(s);

            cout << "Код символа: " << k << endl;
        }

        else
        {
            cout << "Введен символ, не являющийся цифрой" << endl;
        }
    }

    return 0;
}
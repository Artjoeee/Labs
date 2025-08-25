#include "case.h"
#include <iostream>

using namespace std;

int getCode3()
{
    char symbol;

    for (int i = 0; i < 4; i++)
    {
        puts("Введите символ");

        cin >> symbol;

        if (symbol >= '0' && symbol <= '9')
        {
            int code;

            code = int(symbol);

            cout << "Код символа: " << code << endl;
        }

        else
        {
            cout << "Введен символ, не являющийся цифрой" << endl;
        }
    }

    return 0;
}
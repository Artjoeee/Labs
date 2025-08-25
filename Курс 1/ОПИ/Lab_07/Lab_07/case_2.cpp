#include "case.h"
#include <iostream>

using namespace std;

int getDifference2()
{
    char symbol;

    for (int i = 0; i < 4; i++)
    {
        puts("Введите символ");

        cin >> symbol;

        if (symbol >= 'а' && symbol <= 'я')
        {
            int lower, upper, difference;

            lower = int(symbol);
            upper = int(symbol - 32);
            difference = upper - lower;

            cout << "Разница значений кодов в Windows-1251: " << difference << endl;
        }

        else if (symbol >= 'А' && symbol <= 'Я')
        {
            int lower, upper, difference;

            lower = int(symbol + 32);
            upper = int(symbol);
            difference = upper - lower;

            cout << "Разница значений кодов в Windows-1251: " << difference << endl;
        }

        else
        {
            cout << "Введен символ, не являющийся русской буквой" << endl;
        }
    }

    return 0;
}
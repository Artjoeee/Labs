#include "case.h"
#include <iostream>

using namespace std;

int getDifference1()
{
    char symbol;

    for (int i = 0; i < 4; i++)
    {
        puts("Введите символ");

        cin >> symbol;

        if (symbol >= 'a' && symbol <= 'z')
        {
            int lower, upper, difference;

            lower = int(symbol);
            upper = int(symbol - 32);
            difference = upper - lower;

            cout << "Разница значений кодов в ASCII: " << difference << endl;
        }

        else if (symbol >= 'A' && symbol <= 'Z')
        {
            int lower, upper, difference;

            lower = int(symbol + 32);
            upper = int(symbol);
            difference = upper - lower;

            cout << "Разница значений кодов в ASCII: " << difference << endl;
        }

        else
        {
            cout << "Введен символ, не являющийся латинской буквой" << endl;
        }
    }

    return 0;
}
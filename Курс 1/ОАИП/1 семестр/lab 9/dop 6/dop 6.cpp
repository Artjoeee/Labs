#include <iostream>
#include <Windows.h>
#include "pack.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");

    int n, c = 0;

    cout << "Выберите вариант использования (1-4): ";
    cin >> n;

    switch (n)
    {
    case 1: pack1();
        c;
        break;

    case 2: pack2();
        c;
        break;

    case 3: pack3();
        c;
        break;

    case 4: puts("Конец программы");
        break;

    default: puts("Неверно выбран вариант использования");
        break;
    }

    return 0;
}
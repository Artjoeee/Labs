#include <iostream>
#include <Windows.h>
#include "case.h"

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int n;

    cout << "Выберите вариант использования (1-4): ";

    cin >> n;

    switch (n)
    {
        case 1: case1();
        
            break;
    
        case 2: case2();
        
            break;

        case 3: case3();
        
            break;

        case 4: puts("Конец программы"); 

            break;

        default: puts("Неверно выбран вариант использования");

            break;
    }

    return 0;
}
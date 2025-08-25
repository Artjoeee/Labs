#include <iostream>

using namespace std;

int main() 
{
    setlocale(LC_ALL, "RU");

    int a, b;

    cout << "Введите первое натуральное число: ";
    cin >> a;

    cout << "Введите второе натуральное число: ";
    cin >> b;

    while (a != b) 
    {
        if (a > b) 
        {
            a -= b;
        }

        else 
        {
            b -= a;
        }
    }

    cout << "НОД: " << a << endl;

    return 0;
}

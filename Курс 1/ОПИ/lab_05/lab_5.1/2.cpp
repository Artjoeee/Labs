#include <iostream>

using namespace std;

int main() 
{
    setlocale(LC_ALL, "RU");

    int d, b[32]{}, n = 0;

    cout << "¬ведите число в дес€тичной системе: ";
    cin >> d;

    while (d > 0) // принцип состоит в делении числа на 2 и записей остатков, получающихс€ при делении
    {
        b[n] = d % 2;
        d /= 2;
        n++;
    }

    cout << "„исло в двоичной системе: ";

    for (int i = n; i >= 0; i--)
    {
        cout << b[i];
    }

    return 0;
}
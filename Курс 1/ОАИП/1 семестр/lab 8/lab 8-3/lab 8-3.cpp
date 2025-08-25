#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");

    double v[5]{}; // 5 значений v
    double max, c;
    double w = 1, a = 0.5, b = 7;

    for (int i = 0; i < 5; i++)
    {
        cout << "Введите значение v" << i << ": ";
        cin >> v[i];
    }

    max = v[0];

    for (int i = 1; i < 5; i++) // Нахождение max
    {
        if (v[i] > max)
        {
            max = v[i];
        }
    }

    if (max > 0)
    {
        w = a + max;
    }

    else
    {
        w = b / max;
    }

    c = w;

    cout << "c = " << c << endl;

    return 0;
}
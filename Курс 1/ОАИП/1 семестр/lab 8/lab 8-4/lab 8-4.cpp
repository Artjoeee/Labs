#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");

    double y[5]{}; // 5 �������� y
    double min;
    double q, n = 1, p;

    for (int i = 0; i < 5; i++)
    {
        cout << "������� �������� y" << i << ": ";
        cin >> y[i];

        n *= (y[i] - 5);   // ���������� ������������    
    }

    min = y[0];

    for (int i = 1; i < 5; i++) // ���������� min
    {
        if (y[i] < min)
        {
            min = y[i];
        }
    }

    p = min;
    q = n + p;

    cout << "q = " << q << endl;
    
    return 0;
}

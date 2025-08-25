#include <iostream>
#include <cmath>

using namespace std;

int main() 
{
    setlocale(LC_ALL, "RU");

    double y[4]{}; // 4 �������� y
    double max;
    double q = 1;

    for (int i = 0; i < 4; i++) 
    {
        cout << "������� �������� y" << i + 1 << ": ";
        cin >> y[i];
    }

    max = y[0];

    for (int i = 1; i < 4; i++) // ���������� max
    {
        if (y[i] > max) 
        {
            max = y[i];
        }
    }

    for (int i = 0; i < 4; i++) // ���������� ������������
    {
        q *= (y[i] + 2 * max); 
    }

    cout << "q = " << q << endl;

    return 0;
}


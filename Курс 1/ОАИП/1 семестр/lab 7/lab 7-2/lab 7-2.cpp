#include <iostream>

using namespace std;

int main() 
{
    setlocale(LC_ALL, "RU");

    int a, b;

    cout << "������� ������ ����������� �����: ";
    cin >> a;

    cout << "������� ������ ����������� �����: ";
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

    cout << "���: " << a << endl;

    return 0;
}

#include <iostream>

using namespace std;

int main() 
{
    setlocale(LC_ALL, "RU");

    int d, b[32]{}, n = 0;

    cout << "������� ����� � ���������� �������: ";
    cin >> d;

    while (d > 0) // ������� ������� � ������� ����� �� 2 � ������� ��������, ������������ ��� �������
    {
        b[n] = d % 2;
        d /= 2;
        n++;
    }

    cout << "����� � �������� �������: ";

    for (int i = n; i >= 0; i--)
    {
        cout << b[i];
    }

    return 0;
}
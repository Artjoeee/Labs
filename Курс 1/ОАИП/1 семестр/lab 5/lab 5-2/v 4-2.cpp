#include <iostream>

using namespace std;

int main() 
{
    setlocale(LC_ALL, "RU");

    int month;

    cout << "������� ����� ������ (�� 1 �� 12): ";
    cin >> month;
    cout << "" << endl;

    if (month == 12 || month == 1 || month == 2) 
    {
        cout << "���� ����: ����" << endl;
    }

    else if (month >= 3 && month <= 5) 
    {
        cout << "���� ����: �����" << endl;
    }

    else if (month >= 6 && month <= 8) 
    {
        cout << "���� ����: ����" << endl;
    }

    else if (month >= 9 && month <= 11) 
    {
        cout << "���� ����: �����" << endl;
    }

    else 
    {
        cout << "������������ ����� ������" << endl;
    }

    return 0;
}
#include <iostream>

using namespace std;

int main() 
{
    setlocale(LC_ALL, "RU");

    int n;

    cout << "������� ���������� ���������: ";
    cin >> n;

    int num, sum = 0; // ����� � ����� ������ ����� ���������� 

    cout << "������� �������� ������������������: ";

    for (int i = 1; i <= n; i++) 
    {
        cin >> num;

        if (num % 2 == 0) 
        {
            sum += num;  // ���������� �����
        }
    }

    cout << "����� ������ ���������: " << sum << endl;

    return 0;
}


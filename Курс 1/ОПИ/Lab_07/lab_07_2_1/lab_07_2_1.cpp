#include <iostream>
#include <ctime>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");

    const int SIZE = 100;
    int  quantity, number, arr[SIZE]{};

    cout << "������� ���������� ��������� �������: ";

    cin >> quantity;

    srand((unsigned)time(NULL));

    for (int i = 1; i <= quantity; i++) // ���������� ��������� ������� ���������� ������� �� 0 �� 99
    {
        arr[i] = rand() % 100;

        cout << arr[i] << " ";
    }

    cout << endl;

    cout << "������� ����� ���������� ��������: ";

    cin >> number;

    for (int i = number; i < quantity - 1; i++) // �������� �������� k
    {
        arr[i] = arr[i + 1];
    }

    quantity--;

    for (int i = 1; i <= quantity; i++) // ����������� 0 ����� ������ ��������� �������
    {
        cout << arr[i] << " ";

        if (i % 2 == 0)
        {
            cout << "0 ";
        }
    }

    return 0;
}
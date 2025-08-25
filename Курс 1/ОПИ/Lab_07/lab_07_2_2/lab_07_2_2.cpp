#include <iostream>
#include <ctime>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");

    const int N = 100;
    int size;

    cout << "������� ������ �������: ";

    cin >> size;

    int mas[N]{}, digits[N]{}, others[N]{};
    int digitsCount = 0, othersCount = 0;

    srand((unsigned)time(NULL));

    for (int i = 0; i < size; i++) // ���������� ��������� ������� ���������� ������� �� 0 �� 99
    {
        mas[i] = rand() % 100;

        cout << mas[i] << " ";
    }

    cout << endl << endl;

    for (int i = 0; i < size; i++) // ���������� �� ��� ����� �������
    {
        if (mas[i] >= 0 && mas[i] <= 9)
        {
            digits[digitsCount] = mas[i];
            digitsCount++;
        }

        else
        {
            others[othersCount] = mas[i];
            othersCount++;
        }
    }

    cout << "�����: ";

    for (int i = 0; i < digitsCount; i++) // ����� ����� ��������
    {
        cout << digits[i] << " ";
    }

    cout << endl << endl;

    cout << "��������� �������: ";

    for (int i = 0; i < othersCount; i++)
    {
        cout << others[i] << " ";
    }

    cout << endl;

    return 0;
}
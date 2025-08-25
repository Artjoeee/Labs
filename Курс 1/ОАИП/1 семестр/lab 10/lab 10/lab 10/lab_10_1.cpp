#include <iostream>
#include <ctime>

using namespace std;

int main() 
{
    setlocale(LC_ALL, "RU");

    const int N = 100;
    int n, k, mas[N]{};

    cout << "������� ���������� ��������� �������: ";
    cin >> n;

    srand((unsigned)time(NULL));

    for (int i = 1; i <= n; i++) // ���������� ��������� ������� ���������� ������� �� 0 �� 99
    {
        mas[i] = rand() % 100;
        cout << mas[i] << " ";
    }
    cout << endl;

    cout << "������� ����� ���������� ��������: ";
    cin >> k;

    for (int i = k; i < n - 1; i++) // �������� �������� k
    {
        mas[i] = mas[i + 1];
    }
    n--;

    for (int i = 1; i <= n; i++) // ����������� 0 ����� ������ ��������� �������
    {
        cout << mas[i] << " ";
        if (i % 2 == 0) 
        {
            cout << "0 ";
        }
    }

    return 0;
}
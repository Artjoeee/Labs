#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");

    double c1, c2;
    int a = 0; // ����������� ���������� 

    cout << "����� ���� � ������ ������: ";
    cin >> c1;

    cout << "����� ���� �� ������ ������: ";
    cin >> c2;

    do
    {
        c1 /= 2;
        c2 += c1; // 1-�� �����������

        c2 /= 2;
        c1 += c2; // 2-�� �����������

        a++;

    } while (a != 6);

    cout << "����� ���� � ������ ������ ����� �����������: " << c1 << endl;
    cout << "����� ���� �� ������ ������ ����� �����������: " << c2 << endl;

    return 0;
}
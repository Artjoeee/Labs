#include<iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");

    double r, p, q;

    cout << "������� �������� ������� (r): ";
    cin >> r;

    cout << "������� �������� ��������� (p): ";
    cin >> p;

    cout << "������� �������� ��������� (q): ";
    cin >> q;

    if ((p * q) / (2 * sqrt(pow(p, 2) + pow(q, 2))) < r)
    {
        cout << "��� �� ������!" << endl;
    }

    else
    {
        cout << "��� ������!" << endl;
    }

    return 0;
}
#include <iostream> 

using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");

    float a, b, c, r, s, t;

    cout << "������� ����� �������: ";
    cin >> a;

    cout << "������� ������ �������: ";
    cin >> b;

    cout << "������� ������ �������: ";
    cin >> c;

    cout << "������� ����� �������: ";
    cin >> r;

    cout << "������� ������ �������: ";
    cin >> s;

    cout << "������� ������ �������: ";
    cin >> t;

    if (a <= r && b <= s && c <= t)
    {
        cout << "���� ������� ��������� � �������" << endl;
    }

    else
    {
        cout << "���� ������� �� ��������� � �������" << endl;
    }

    return 0;
}
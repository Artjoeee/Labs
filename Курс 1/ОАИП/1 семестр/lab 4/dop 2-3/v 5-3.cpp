#include <iostream>
using namespace std;


int main()
{
    setlocale(LC_ALL, "RU");

    double d;
    double n;

    cout << "������� ��������� ����: ";
    cin >> d;
    cout << "������� ���������� ���: ";
    cin >> n;

    double a = d + d * 0.15;
    double s = a - a * 0.15;
    double g = (s - d) * n;

    cout << "��������� ���� �� ��������� ���������� ���: " << g << endl;

    return 0;

}

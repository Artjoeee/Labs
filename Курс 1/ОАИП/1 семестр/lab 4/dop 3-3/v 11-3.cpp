#include <iostream>

using namespace std;

int main() 
{
    setlocale(LC_ALL, "RU");

    int b;
    cout << "������� ����� 3 (������ ��������������): ";
    cin >> b;

    int a = 2 * b;
    int p = 2 * (a + b);
    int s = a * b; 

    cout << "������� ��������������: " << s << endl;
    cout << "�������� ��������������: " << p << endl;
    cout << "��������� ��������������: " << a << endl;

    return 0;
}

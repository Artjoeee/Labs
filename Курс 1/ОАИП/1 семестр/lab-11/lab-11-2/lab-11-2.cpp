#include <iostream>

using namespace std;

int main() 
{
    setlocale(LC_ALL, "RU");

    unsigned int A, mask;
    int n, p;
    char buffer[33];

    cout << "������� A: ";

    cin >> A;

    cout << "������� n: ";

    cin >> n;

    cout << "������� p: ";

    cin >> p;

    cout << endl;

    _itoa_s(A, buffer, 2);

    cout << "����� �: " << buffer << endl;

    mask = (1 << n) - 1;   // ������� ����� ��� ��������� ����� � 1
    mask <<= p;
    A |= mask;  // ������������� ���� � 1

    cout << endl;

    _itoa_s(A, buffer, 2);

    cout << "Buffer = " << buffer << endl;

    return 0;
}

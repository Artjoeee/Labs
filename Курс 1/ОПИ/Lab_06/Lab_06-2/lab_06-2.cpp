#include <iostream>
#include "func.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");

    int d, b[32]{}, n = 0;

    cout << "������� ����� � ���������� �������: ";

    cin >> d;

    func1(d, b, n);

    cout << "����� � �������� �������: ";

    func2(b, n);

    return 0;
}
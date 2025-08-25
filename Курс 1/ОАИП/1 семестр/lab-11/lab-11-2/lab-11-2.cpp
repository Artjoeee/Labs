#include <iostream>

using namespace std;

int main() 
{
    setlocale(LC_ALL, "RU");

    unsigned int A, mask;
    int n, p;
    char buffer[33];

    cout << "Введите A: ";

    cin >> A;

    cout << "Введите n: ";

    cin >> n;

    cout << "Введите p: ";

    cin >> p;

    cout << endl;

    _itoa_s(A, buffer, 2);

    cout << "Число А: " << buffer << endl;

    mask = (1 << n) - 1;   // создаем маску для установки битов в 1
    mask <<= p;
    A |= mask;  // устанавливаем биты в 1

    cout << endl;

    _itoa_s(A, buffer, 2);

    cout << "Buffer = " << buffer << endl;

    return 0;
}

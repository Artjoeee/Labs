#include <iostream>

using namespace std;
int main() 
{
    setlocale(LC_CTYPE, "RU");
    double x, y, z;

    cout << "������� ����� X: ";
    cin >> x;

    cout << "������� ����� Y: ";
    cin >> y;

    cout << "������� ����� Z: ";
    cin >> z;

    double a = (abs(x) + abs(y) + abs(z)) / 3;
    double g = cbrt(abs(x) * abs(y) * abs(z));

    cout << "������� �������������� �������: " << a << endl;
    cout << "������� �������������� �������: " << g << endl;

    return 0;
}
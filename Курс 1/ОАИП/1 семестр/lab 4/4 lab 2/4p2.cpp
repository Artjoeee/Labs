#include <iostream>

using namespace std;
int main() 
{
    setlocale(LC_CTYPE, "RU");
    double x, y, z;

    cout << "¬ведите число X: ";
    cin >> x;

    cout << "¬ведите число Y: ";
    cin >> y;

    cout << "¬ведите число Z: ";
    cin >> z;

    double a = (abs(x) + abs(y) + abs(z)) / 3;
    double g = cbrt(abs(x) * abs(y) * abs(z));

    cout << "—реднее арифметическое модулей: " << a << endl;
    cout << "—реднее геометрическое модулей: " << g << endl;

    return 0;
}
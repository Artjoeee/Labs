#include <iostream>

using namespace std;

int main() 
{
    setlocale(LC_ALL, "RU");

    int b;
    cout << "Введите число 3 (высота прямоугольника): ";
    cin >> b;

    int a = 2 * b;
    int p = 2 * (a + b);
    int s = a * b; 

    cout << "Площадь прямоугольника: " << s << endl;
    cout << "Периметр прямоугольника: " << p << endl;
    cout << "Основание прямоугольника: " << a << endl;

    return 0;
}

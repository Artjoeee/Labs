#include <iostream>
#include <cmath>

using namespace std;

// Функция для нахождения количества квадратов при разбиении прямоугольника
int numsq(int a, int b)
{
    if (b == 0)
    {
        return 0;
    }
    else
    {
        return a / b + numsq(b, a % b);
    }
}

int main()
{
    setlocale(0, "ru");

    int a, b;

    cout << "Введите стороны прямоугольника (a и b через пробел): ";
    cin >> a >> b;

    // Проверка на натуральные числа
    if (a <= 0 || b <= 0)
    {
        cout << "Строны прямоугольника должны быть натуральными числами." << endl;
        return 1;
    }

    // Обмен значений, чтобы a всегда было больше b
    if (a < b)
        swap(a, b);

    int result = numsq(a, b);

    cout << "При разбиении прямоугольника со сторонами " << a << "x" << b
        << " на квадраты получится " << result << " квадратов." << endl;

    return 0;
}
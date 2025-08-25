#include <iostream>

using namespace std;

// Прототипы
double func1(double);
double func2(double);
double dychotomy(double (*)(double), double, double, double);

double func1(double x) // Определение функции уравнения x^3 + 2x - 1
{
    return pow(x,3) + 2 * x - 1;
}

double func2(double x) // Определение функции уравнения e^x - 2
{
    return exp(x) - 2;
}

double dychotomy(double (*func)(double), double a, double b, double e) // Определение функции нахождения корней методом дихотомии 
{
    if (func(a) * func(b) >= 0) // Неверный интервал
    {
        cout << "Неправильно выбраны начальные значения" << endl;

        return -1;  // Возвращаем -1, если интервал выбран неверно
    }

    double c{};

    while (abs(a - b) > 2 * e)  // Метод дихотомии для нахождения корня уравнения
    {
        c = (a + b) / 2;

        if (func(c) == 0) 
        {
            break;  // Найден точный корень
        }
        else if (func(c) * func(a) <= 0) 
        {
            b = c;
        }
        else 
        {
            a = c;
        }
    }

    return c;   // Возвращаем найденный корень
}

int main() 
{
    setlocale(0, "ru");

    double e = 0.001;
    double a1, b1, a2, b2;
    double r1, r2;

    cout << "Введите интервалы для уравнения x^3 + 2x - 1 (a, b): ";
    cin >> a1 >> b1;

    cout << "Введите интервалы для уравнения e^x - 2 (a, b): ";
    cin >> a2 >> b2;
   
    r1 = dychotomy(func1, a1, b1, e); // Находим корень для уравнения x^3 + 2x - 1

    cout << "Корень уравнения x^3 + 2x - 1: " << r1 << endl;

    r2 = dychotomy(func2, a2, b2, e);  // Находим корень для уравнения e^x - 2

    cout << "Корень уравнения e^x - 2: " << r2 << endl;

    return 0;
}
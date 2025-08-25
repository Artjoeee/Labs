#include <iostream>
#include <chrono>

using namespace std;
using namespace chrono;

int recursive(int n);
int linear(int n);

int linear(int n) // Линейный способ подсчета чисел Фибоначчи циклом
{
    int a = 0, b = 1, c;

    if (n == 1)
    {
        return a;
    }
    else if (n == 2) 
    {
        return b;
    }

    for (int i = 3; i <= n; i++) 
    {
        c = a + b;
        a = b;
        b = c;
    }

    return b;
}

int recursive(int n) // Рекурсивный подсчет чисел Фибоначчи
{
    if (n == 1) 
    {
        return 0;
    }
    else if (n == 2 || n == 3)
    {
        return 1;
    }
    else 
    {
        return recursive(n - 1) + recursive(n - 2);
    }
}

int main() 
{
    setlocale(0, "ru");

    int n;

    cout << "Введите число N: ";

    cin >> n;

    // Вычисление числа Фибоначчи циклом
    auto start_linear = high_resolution_clock::now();
    int result_linear = linear(n);
    auto end_linear = high_resolution_clock::now();
    duration<double> time_linear = end_linear - start_linear;

    // Вычисление числа Фибоначчи через рекурсию
    auto start_recursive = high_resolution_clock::now();
    int result_recursive = recursive(n);
    auto end_recursive = high_resolution_clock::now();
    duration<double> time_recursive = end_recursive - start_recursive;

    cout << "N-ое число ряда Фибоначчи (циклом): " << result_linear << endl;

    cout << "Расчетное время циклом: " << duration_cast<minutes>(time_linear).count() << " минут "
        << duration_cast<seconds>(time_linear).count() % 60 << " секунд" << endl;

    cout << "N-ое число ряда Фибоначчи (рекурсией): " << result_recursive << endl;

    cout << "Расчетное время рекурсией: " << duration_cast<minutes>(time_recursive).count() << " минут "
        << duration_cast<seconds>(time_recursive).count() % 60 << " секунд" << endl;

    return 0;
}
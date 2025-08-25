#include <iostream>

using namespace std;

// Рекурсивная функция для вычисления A(m, n)
int function(int m, int n)
{
    if (m == 0)
    {
        return n + 1;
    }
    else if (n == 0)
    {
        return function(m - 1, 1);
    }
    else
    {
        return function(m - 1, function(m, n - 1));
    }
}

int main()
{
    setlocale(0, "ru");

    int m, n;

    cout << "Введите целые неотрицательные числа m и n через пробел: ";
    cin >> m >> n;

    // Проверка на неотрицательные числа
    if (m < 0 || n < 0)
    {
        cout << "Числа должны быть неотрицательными." << endl;
        return 1;
    }

    int result = function(m, n);

    cout << "A(" << m << ", " << n << ") = " << result << endl;

    return 0;
}
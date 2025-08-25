#include <iostream>

using namespace std;

int main() 
{
    setlocale(LC_ALL, "RU");

    int n;

    cout << "Введите количество элементов: ";
    cin >> n;

    int num, sum = 0; // Число и сумма чётных чисел изначально 

    cout << "Введите элементы последовательности: ";

    for (int i = 1; i <= n; i++) 
    {
        cin >> num;

        if (num % 2 == 0) 
        {
            sum += num;  // Нахождение суммы
        }
    }

    cout << "Сумма четных элементов: " << sum << endl;

    return 0;
}


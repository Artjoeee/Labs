#include <iostream>

using namespace std;

int main() 
{
    setlocale(LC_ALL, "RU");

    for (int i = 1000; i <= 9999; i++)  // Четырехзначное число 
    {
        if (i % 2 == 0 && i % 7 == 0 && i % 11 == 0)    // Проверка на деление
        {
            int sum = 0;    // Сумма цифр изначально 
            int t = i;     // Число равно номеру

            while (t > 0) 
            {
                sum += t % 10;  // Прибавление остатка от деления на 10
                t /= 10;      // Деление числа на 10
            }

            if (sum == 30) 
            {
                cout << "Номер машины: " << i << endl;
                break;
            }
        }
    }

    return 0;
}

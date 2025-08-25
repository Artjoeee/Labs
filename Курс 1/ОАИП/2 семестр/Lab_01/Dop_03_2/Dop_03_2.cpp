#include <iostream>
#include <cstdarg>

using namespace std;

int fsum(int count, ...); // Прототип

int fsum(int count, ...) // Функция fsum с переменным числом параметров
{
    va_list arg;   // Создаем список аргументов

    va_start(arg, count);  // Инициализируем список аргументов

    int sum = 0;

    int current = va_arg(arg, int); // Получаем первый аргумент из списка

    for (int i = 1; i < count; i++) 
    {
        int next = va_arg(arg, int);    // Получаем следующий аргумент из списка

        sum += current * next;  // Умножаем текущий и следующий аргументы и добавляем результат к сумме

        current = next;
    }

    va_end(arg);    // Освобождаем список аргументов

    return sum; 
}

int main() 
{
    setlocale(0, "ru");

    cout << "Сумма (1): " << fsum(4, 1, 2, 3, 4) << endl; // Первый вызов с четырьмя параметрами

    cout << "Сумма (2): " << fsum(3, 5, 10, 15) << endl;  // Второй вызов с тремя параметрами 

    cout << "Сумма (3): " << fsum(2, 3, 7) << endl;   // Третий вызов с двумя параметрами  

    return 0;
}
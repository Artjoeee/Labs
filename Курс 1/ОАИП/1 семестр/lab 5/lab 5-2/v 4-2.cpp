#include <iostream>

using namespace std;

int main() 
{
    setlocale(LC_ALL, "RU");

    int month;

    cout << "Введите номер месяца (от 1 до 12): ";
    cin >> month;
    cout << "" << endl;

    if (month == 12 || month == 1 || month == 2) 
    {
        cout << "Пора года: зима" << endl;
    }

    else if (month >= 3 && month <= 5) 
    {
        cout << "Пора года: весна" << endl;
    }

    else if (month >= 6 && month <= 8) 
    {
        cout << "Пора года: лето" << endl;
    }

    else if (month >= 9 && month <= 11) 
    {
        cout << "Пора года: осень" << endl;
    }

    else 
    {
        cout << "Некорректный номер месяца" << endl;
    }

    return 0;
}
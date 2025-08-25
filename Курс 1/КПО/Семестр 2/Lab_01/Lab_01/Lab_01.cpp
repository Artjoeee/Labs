#include "stdafx.h"
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

int main()
{
    setlocale(0, "ru");

    string inputDate;
    int dayOfYear = -1;

    cout << "Введите дату в формате ДДММГГГГ: ";
    cin >> inputDate;

    cout << "Введите порядковый номер дня в году: ";
    cin >> dayOfYear;

    int day = stoi(inputDate.substr(0, 2));
    int month = stoi(inputDate.substr(2, 2));
    int year = stoi(inputDate.substr(4, 4));

    int dayYear = getDay(day, month, year);
    bool leapYear = getYear(year);
    int daysBirthday = daysUntilBirthday(dayYear, year);

    cout << day << "." << month << "." << year << endl;

    cout << "Введенный год " << (leapYear ? "является" : "не является") << " високосным.\n";

    cout << "Порядковый номер введенного дня в году: " << dayYear << "\n";

    if (dayYear != 0)
    {
        cout << "До ближайшего дня моего рождения осталось " << daysBirthday << " дней.\n";
    }

    if (dayOfYear == 255 || getYear(year) && dayOfYear == 256)
    {
        cout << "На " << dayOfYear << " день года приходится День программиста (" << dateOfYear(dayOfYear, year) << " февраля)" << endl;
    }
    else if (dayOfYear == 121 || getYear(year) && dayOfYear == 122)
    {
        cout << "На " << dayOfYear << " день года приходится День труда (" << dateOfYear(dayOfYear, year) << " мая)" << endl;
    }
    else if (dayOfYear == 74 || getYear(year) && dayOfYear == 75)
    {
        cout << "На " << dayOfYear << " день года приходится День конституции РБ (" << dateOfYear(dayOfYear, year) << " марта)" << endl;
    }
    else
    {
        cout << "На эту дату не подобран праздник" << endl;
    }

    return 0;
}
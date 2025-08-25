#include <iostream>

using namespace std;

typedef unsigned char day;  // День
typedef unsigned char month;  // Месяц
typedef unsigned short year;  // Год  

struct Date  // Дата
{
    day dd;
    month mm;
    year yyyy;

    // Перегрузка оператора <
    bool operator<(const Date& other) 
    {
        if (yyyy != other.yyyy)
        {
            return yyyy < other.yyyy;
        }

        if (mm != other.mm)
        {
            return mm < other.mm;
        }

        return dd < other.dd;
    }

    // Перегрузка оператора >
    bool operator>(const Date& other)
    {
        if (yyyy != other.yyyy)
        {
            return yyyy > other.yyyy;
        }

        if (mm != other.mm)
        {      
            return mm > other.mm;
        }

        return dd > other.dd;
    }

    // Перегрузка оператора ==
    bool operator==(const Date& other)
    {
        if (yyyy != other.yyyy)
        { 
            return yyyy == other.yyyy;
        }

        if (mm == other.mm)
        { 
            return mm == other.mm;
        }

        return dd == other.dd;
    }

    Date() = default;
};

int main()
{
    setlocale(LC_ALL, "ru");

    Date date1 = { 7, 1, 1980 };
    Date date2 = { 7, 2, 1993 };
    Date date3 = { 7, 1, 1980 };

    if (date1 < date2)
    {
        cout << "Истина" << endl;
    }
    else
    {
        cout << "Ложь" << endl;
    }

    if (date1 > date2)
    {
        cout << "Истина" << endl;
    }
    else
    {
        cout << "Ложь" << endl;
    }

    if (date1 == date2)
    {
        cout << "Истина" << endl;
    }
    else
    {
        cout << "Ложь" << endl;
    }

    if (date1 == date3)
    {
        cout << "Истина" << endl;
    }
    else
    {
        cout << "Ложь" << endl;
    }

    return 0;
}
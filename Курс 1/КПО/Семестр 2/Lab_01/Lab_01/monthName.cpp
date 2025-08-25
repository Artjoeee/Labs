#include "stdafx.h"
#include <string>

using namespace std;

string monthName(int month)
{
    const string monthNames[] = { "", "Января", "Февраля", "Марта", "Апреля", "Мая", "Июня", "Июля", "Августа", "Сентября", "Октября", "Ноября", "Декабря" };

    if (month < 1 || month > 12)
    {
        return "Неверный месяц";
    }

    return monthNames[month];
}


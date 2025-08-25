#include "stdafx.h"


int getDay(int day, int month, int year)
{
    int dayMonth[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int dayYear = day;

    if (getYear(year))
    {
        dayMonth[2] = 29;
    }

    for (int i = 1; i < month; i++)
    {
        dayYear += dayMonth[i];

        if (day > dayMonth[month])
        {
            return 0;
        }
    }

    return dayYear;
}
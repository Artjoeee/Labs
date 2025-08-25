#include "stdafx.h"

int dateOfYear(int dayOfYear, int year)
{
    int currentDay = 0;
    int month = 1;
    int dayMonth[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    if (getYear(year))
    {
        dayMonth[2] = 29;
    }

    while (currentDay + dayMonth[month] < dayOfYear)
    {
        currentDay += dayMonth[month];
        month++;
    }

    return dayOfYear - currentDay;
}
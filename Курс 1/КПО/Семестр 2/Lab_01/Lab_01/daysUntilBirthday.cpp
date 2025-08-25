#include "stdafx.h"


int daysUntilBirthday(int dayYear, int year)
{
    const int birthDay = 4;
    const int birthMonth = 2;
    int birthDayYear = getDay(birthDay, birthMonth, 2024);

    if (dayYear < birthDayYear)
    {
        return birthDayYear - dayYear;
    }
    else if (getYear(year))
    {
        int daysInYear = 366;

        return daysInYear - (dayYear - birthDayYear);
    }
    else
    {
        int daysInYear = 365;

        return daysInYear - (dayYear - birthDayYear);
    }
}
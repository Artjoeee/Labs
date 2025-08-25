#include "stdafx.h"
#include <string>

using namespace std;

string monthName(int month)
{
    const string monthNames[] = { "", "������", "�������", "�����", "������", "���", "����", "����", "�������", "��������", "�������", "������", "�������" };

    if (month < 1 || month > 12)
    {
        return "�������� �����";
    }

    return monthNames[month];
}


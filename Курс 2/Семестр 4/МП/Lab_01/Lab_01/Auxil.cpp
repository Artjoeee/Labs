#include "stdafx.h"
#include "Auxil.h" 
#include <ctime>

namespace auxil
{
    void start()                            // Старт  генератора сл. чисел
    {
        srand((unsigned)time(NULL));
    }

    double dget(double rmin, double rmax)   // Получить случайное число
    {
        return ((double)rand() / (double)RAND_MAX) * (rmax - rmin) + rmin;
    }

    int iget(int rmin, int rmax)            // Получить случайное число

    {
        return (int)dget((double)rmin, (double)rmax);
    }
}
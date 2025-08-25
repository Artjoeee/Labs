#include "Function.h"

int defaultparm(int a, int b, int c, int d, int e, int f, int g) 
{
    // Рассчитываем сумму всех параметров
    int sum = a + b + c + d + e + f + g;

    // Рассчитываем среднее арифметическое
    int average = sum / 7;

    return average;
}
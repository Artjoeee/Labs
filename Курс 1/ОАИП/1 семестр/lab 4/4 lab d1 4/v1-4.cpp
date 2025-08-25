#include <iostream>
#include <cstdio>
#include <conio.h>

int main() 
{

    setlocale(LC_ALL, "RU");

    double d;

    printf("¬ведите длину диагонали: ");
    scanf_s("%lf", &d);
    
    double a = d / sqrt(2);
    double s = a * a;

    printf("ѕлощадь квадрата равна: %.2lf\n", s);

    return 0;

}
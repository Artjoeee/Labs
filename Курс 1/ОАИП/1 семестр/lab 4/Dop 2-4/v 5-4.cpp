#include <iostream>
#include <cstdio>
#include <conio.h>

int main()
{

    setlocale(LC_ALL, "RU");

    double d;
    double n;

    printf("¬ведите начальную цену: ");
    scanf_s("%lf", &d);
    printf("¬ведите количество лет: ");
    scanf_s("%lf", &n);


    double a = d + d * 0.15;
    double s = a - a * 0.15;
    double g = (s - d) * n;

    printf("»зменение цены за указанное количество лет: %.2lf\n", g);

    return 0;

}
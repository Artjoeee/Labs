#include <iostream>
#include <cstdio>
#include <conio.h>

int main()
{

    setlocale(LC_ALL, "RU");

    int b;
    

    printf("Введите число 3 (высота прямоугольника): ");
    scanf_s("%d", &b);
    
    int a = 2 * b;
    int p = 2 * (a + b);
    int s = a * b;

    printf("Площадь прямоугольника: %d\n", s);
    printf("Периметр прямоугольника: %d\n", p);
    printf("Основание прямоугольника: %d\n", a);

    return 0;

}
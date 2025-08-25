#include <iostream>
#include <conio.h>

int main() 
{
    setlocale(LC_ALL, "RU");
    float X, Y, Z;
    double a, g;

    printf("¬ведите значение X: ");
    scanf_s("%f", &X);

    printf("¬ведите значение Y: ");
    scanf_s("%f", &Y);

    printf("¬ведите значение Z: ");
    scanf_s("%f", &Z);

    a = (abs(X) + abs(Y) + abs(Z)) / 3;
    g = cbrt(abs(X) * abs(Y) * abs(Z));

    printf("—реднее арифметическое модулей: %.2f\n", a);
    printf("—реднее геометрическое модулей: %.2f\n", g);

    
    return 0;
}

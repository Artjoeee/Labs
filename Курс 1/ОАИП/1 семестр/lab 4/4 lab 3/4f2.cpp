#include <iostream>
#include <conio.h>

int main() 
{
    setlocale(LC_ALL, "RU");
    float X, Y, Z;
    double a, g;

    printf("������� �������� X: ");
    scanf_s("%f", &X);

    printf("������� �������� Y: ");
    scanf_s("%f", &Y);

    printf("������� �������� Z: ");
    scanf_s("%f", &Z);

    a = (abs(X) + abs(Y) + abs(Z)) / 3;
    g = cbrt(abs(X) * abs(Y) * abs(Z));

    printf("������� �������������� �������: %.2f\n", a);
    printf("������� �������������� �������: %.2f\n", g);

    
    return 0;
}

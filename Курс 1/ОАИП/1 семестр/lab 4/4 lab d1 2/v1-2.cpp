#include <stdio.h>
#include <iostream>
#include <conio.h>
using namespace std;

int main()
{

    setlocale(0, "");
    const char t = ' ';
    char x;
    int k = 53, kk = 13, a = 56, aa = 7;
    float l;

    printf("¬ведите x= ");
    x = _getch();
    scanf_s("%f", &l);

    for (int i = 0; i < 10; i++)
    {
        printf("\n");
    }

    for (int n = 0; n < 1; n++)
    {

        for (int i = 0; i < a; i++)
        {
            printf("%c", t);
        }

        for (int i = 0; i < aa; i++)
        {
            printf("%c", x);
        }

        printf("\n");

    }

    for (int n = 0; n < 2; n++)
    {

        for (int i = 0; i < k; i++)
        {
            printf("%c", t);
        }

        for (int i = 0; i < kk; i++)
        {
            printf("%c", x);
        }

        k -= 1;
        kk += 2;

        printf("\n");

    }

    for (int n = 0; n < 1; n++)
    {

        for (int i = 0; i < k; i++)
        {
            printf("%c", t);
        }

        for (int i = 0; i < kk; i++)
        {
            printf("%c", x);
        }

        printf("\n");

    }

    return 0;

}
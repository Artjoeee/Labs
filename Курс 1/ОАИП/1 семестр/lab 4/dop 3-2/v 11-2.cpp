#include <stdio.h>
#include <iostream>
#include <conio.h>
using namespace std;

int main()
{

    setlocale(0, "");
    const char t = ' ';
    char x;
    int a = 52, aa = 19;
    float l;

    printf("¬ведите x= ");
    x = _getch();
    scanf_s("%f", &l);

    for (int i = 0; i < 10; i++)
    {
        printf("\n");
    }

    for (int n = 0; n < 8; n++)
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



    return 0;

}
#include "func.h"
#include <iostream>

using namespace std;

void func1(int d, int b[], int& n)
{
    while (d > 0)
    {
        b[n] = d % 2;
        d /= 2;
        n++;
    }
}
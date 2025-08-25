#include "func.h"
#include <iostream>

using namespace std;

void func2(int b[], int n)
{
    for (int i = n; i >= 0; i--)
    {
        cout << b[i];
    }
}
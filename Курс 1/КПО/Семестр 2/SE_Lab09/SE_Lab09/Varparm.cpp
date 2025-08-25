#include "Varparm.h"
#include <cstdarg>
#include <algorithm>

using namespace std;

namespace Varparm 
{
    // ivarparm функция
    int ivarparm(int count, ...) 
    {
        va_list args;

        va_start(args, count);

        int product = 1;

        for (int i = 0; i < count; ++i) 
        {
            product *= va_arg(args, int);
        }

        va_end(args);

        return product;
    }

    // svarparm функция
    int svarparm(short count, ...) 
    {
        va_list args;

        va_start(args, count);

        int maxVal = INT_MIN;

        for (short i = 0; i < count; ++i) 
        {
            int val = va_arg(args, int);

            maxVal = max(maxVal, val);
        }

        va_end(args);

        return maxVal;
    }

    // fvarparm функция
    double fvarparm(float maxFloat, ...) 
    {
        va_list args;

        va_start(args, maxFloat);

        double sum = 0.0;

        float val;

        while ((val = va_arg(args, double)) != maxFloat) 
        {
            sum += val;
        }

        va_end(args);

        return sum;
    }

    // dvarparm функция
    double dvarparm(double maxDouble, ...) 
    {
        va_list args;

        va_start(args, maxDouble);

        double sum = 0.0;

        double val;

        while ((val = va_arg(args, double)) != maxDouble) 
        {
            sum += val;
        }

        va_end(args);

        return sum;
    }
}

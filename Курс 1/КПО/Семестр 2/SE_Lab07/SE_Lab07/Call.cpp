#include "Call.h"

namespace Call 
{
    // cdecl функция
    int cdeсl(int a, int b, int c) 
    {
        return a + b + c;
    }

    // stdcall функция
    int __stdcall cstd(int& a, int b, int c) 
    {
        return a * b * c;
    }

    // fastcall функция
    int __fastcall cfst(int a, int b, int c, int d) 
    {
        return a + b + c + d;
    }
}

#pragma once

namespace Call 
{
    // cdecl функция
    int cdeсl(int a, int b, int c);

    // stdcall функция
    int __stdcall cstd(int& a, int b, int c);

    // fastcall функция
    int __fastcall cfst(int a, int b, int c, int d);
}
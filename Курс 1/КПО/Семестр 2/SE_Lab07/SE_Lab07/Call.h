#pragma once

namespace Call 
{
    // cdecl �������
    int cde�l(int a, int b, int c);

    // stdcall �������
    int __stdcall cstd(int& a, int b, int c);

    // fastcall �������
    int __fastcall cfst(int a, int b, int c, int d);
}
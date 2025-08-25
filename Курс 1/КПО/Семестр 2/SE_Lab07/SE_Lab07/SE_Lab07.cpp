#include <iostream>
#include "Call.h"

using namespace std;
using namespace Call;

int main() 
{
    // Параметры для всех функций
    int param1 = 3, param2 = 5, param3 = 7, param4 = 2;

    // Вызов cdecl функции
    int cdeclResult = cdeсl(param1, param2, param3);
    cout << "cdecl: " << cdeclResult << endl;

    // Вызов stdcall функции
    int stdcallResult = cstd(param1, param2, param3);
    cout << "stdcall: " << stdcallResult << endl;

    // Вызов fastcall функции
    int fastcallResult = cfst(param1, param2, param3, param4);
    cout << "fastcall: " << fastcallResult << endl;

    return 0;
}

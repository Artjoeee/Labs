#include <iostream>
#include "Call.h"

using namespace std;
using namespace Call;

int main() 
{
    // ��������� ��� ���� �������
    int param1 = 3, param2 = 5, param3 = 7, param4 = 2;

    // ����� cdecl �������
    int cdeclResult = cde�l(param1, param2, param3);
    cout << "cdecl: " << cdeclResult << endl;

    // ����� stdcall �������
    int stdcallResult = cstd(param1, param2, param3);
    cout << "stdcall: " << stdcallResult << endl;

    // ����� fastcall �������
    int fastcallResult = cfst(param1, param2, param3, param4);
    cout << "fastcall: " << fastcallResult << endl;

    return 0;
}

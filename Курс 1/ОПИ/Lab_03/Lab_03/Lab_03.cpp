#include <iostream>
// ZhamoidaArtiom2005
// 5A 68 61 6D 6F 69 64 61 41 72 74 69 6F 6D 32 30 30 35
// 005A 0068 0061 006D 006F 0069 0064 0061 0041 0074 0069 006F 006D 0032 0030 0030 0035
// 5A 68 61 6D 6F 69 64 61 41 72 74 69 6F 6D 32 30 30 35

// ЖамойдоАртём2005
// D0 96 D0 B0 D0 BC D0 BE D0 B9 D0 B4 D0 BE D0 90 D1 80 D1 82 D1 91 D0 BC 32 30 30 35
// 0416 0430 043C 043E 0439 0434 043E 0410 0440 0442 0451 043C 0032 0030 0030 0035
// 0416 0430 043C 043E 0439 0434 043E 0410 0440 0442 0451 043C 0032 0030 0030 0035
 
// Жамойдо2005Artiom
// D0 96 D0 B0 D0 BC D0 BE D0 B9 D0 B4 D0 BE 32 30 30 35 41 72 74 D0 B8 D0 BE D0 BC
// 0416 0430 043C 043E 0439 0434 043E 0032 0030 0030 0035 0041 0072 0074 0438 043E 043C
// 416 430 43C 43E 439 434 43E 032 030 030 035 41 72 74 438 43E 43C

using namespace std;

int main()
{
    setlocale (LC_ALL, "RU" );
    int number = 0x12345678;
    char hello[] = "Hello, ";
    char lfie[] = "ZhamoidaArtiom2005";
    char rfie[] = "ЖамойдоАртёмИгоревич2005";
    char lr[] = "Жамойдо2005Artiom";

    wchar_t Lfie[] = L"ZhamoidaArtiom2005";
    wchar_t Rfie[] = L"ЖамойдоАртёмИгоревич2005";
    wchar_t LR[] = L"Жамойдо2005Artiom";
     
    cout << hello << Lfie << ", " << Rfie << ", " << LR << endl << endl;

    return 0;
}


#include <iostream>
#include "Function.h"

using namespace std;

int main() 
{
    setlocale(0, "RU");

    int result1 = defaultparm(2, 4, 6, 8, 10);     // f = 1, g = 2
    int result2 = defaultparm(2, 4, 6, 8, 10, 12, 14);  // все параметры переданы явно  

    cout << "Среднее арифметическое (1): " << result1 << endl;
    cout << "Среднее арифметическое (2): " << result2 << endl;

    return 0;
}

#include <iostream>

using namespace std;

int main() 
{
    setlocale(LC_ALL, "RU");

    int c = 0; // Способов набора изначально

    for (int i = 0; i <= 2; i++)  // 50 коп
    {
        for (int j = 0; j <= 5; j++) // 20 коп
        {
            for (int k = 0; k <= 20; k++) // 5 коп
            {
                for (int l = 0; l <= 50; l++) // 2 коп
                {
                    if (i * 50 + j * 20 + k * 5 + l * 2 == 100) 
                    {
                        c++; // Прибавление способа набора
                    }
                }
            }
        }
    }

    cout << "Количество способов набора: " << c << endl;

    return 0;
}

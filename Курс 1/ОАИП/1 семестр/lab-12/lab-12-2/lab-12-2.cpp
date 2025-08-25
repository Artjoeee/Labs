#include <iostream>

using namespace std;

int main() 
{
    setlocale(LC_ALL, "RU");

    int Z[] = { 4, 4, 4, 4, 4 };
    int n = sizeof(Z) / sizeof(Z[0]);
    int count = 0;

    for (int i = 0; i < n; ++i) 
    {
        // Проверяем, является ли текущий элемент уникальным
        bool unique = true;

        for (int j = 0; j < i; ++j) 
        {
            if (*(Z + i) == *(Z + j)) 
            {
                unique = false;               
            }
        }

        if (unique) 
        {
            ++count;
        }
    }

    if (count == 1)
    {
        --count;
    }

    cout << "Количество различных чисел в массиве Z: " << count << endl;

    return 0;
}

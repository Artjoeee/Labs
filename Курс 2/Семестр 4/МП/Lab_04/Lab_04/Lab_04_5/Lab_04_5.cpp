#include <iostream>
#include "LCS.h"
#include <Windows.h>
#include <ctime>

char* GenerateRandomString(int size)
{
    char* str = (char*)malloc(sizeof(char) * size);

    for (int i = 0; i < size; i++)
    {
        str[i] = rand() % 26 + 'a'; // 26 букв в алфавите
    }

    return str;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    clock_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;
    char z[100] = "";

    t1 = clock();
    char X[] = "ABCDGFI";
    char Y[] = "EATUFI";

    std::cout << std::endl << "-- вычисление длины LCS для X и Y(рекурсия)";
    std::cout << std::endl << "-- последовательность X: " << X;
    std::cout << std::endl << "-- последовательность Y: " << Y;

    int s = lcs(sizeof(X) - 1, X, sizeof(Y) - 1, Y);

    std::cout << std::endl << "-- длина LCS: " << s << std::endl;
    t2 = clock();
  
    t3 = clock();
    char x[] = "ABCDGFI";
    char y[] = "EATUFI";

    int l = lcsd(x, y, z);
    t4 = clock();

    std::cout << std::endl
        << "-- наибольшая общая подпоследовательость - LCS(динамическое"
        << " программирование)" << std::endl;
    std::cout << std::endl << "последовательость X: " << x;
    std::cout << std::endl << "последовательость Y: " << y;
    std::cout << std::endl << "                LCS: " << z;
    std::cout << std::endl << "          длина LCS: " << l;
    std::cout << std::endl;

    std::cout << std::endl << "Время вычисления LCS";
    std::cout << std::endl << "Рекурсия: " << (t2 - t1);
    std::cout << std::endl << "Динамическое программирование: " << (t4 - t3) << std::endl;

    return 0;
}
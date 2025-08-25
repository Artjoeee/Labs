// Отключаем предупреждения о безопасности для старых функций fopen и fscanf
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>

int main() 
{
    setlocale(0, "ru");

    FILE* fileA, * fileB;

    int number;

    int exist[100] = {0}; // Массив для хранения уже встреченных чисел
    int count[100] = {0}; // Массив для хранения количества встреч каждого числа
    int unique = 0; // Счетчик уникальных чисел

    // Открываем файлы для чтения и записи
    fileA = fopen("fileA.txt", "r");

    fileB = fopen("fileB.txt", "w");

    if (fileA == NULL || fileB == NULL) 
    {
        printf("Ошибка открытия файлов.");

        return EXIT_FAILURE;
    }

    // Читаем числа из fileA, копируем уникальные числа в fileB
    while (fscanf(fileA, "%d", &number) == 1) 
    {
        int newIndex = -1;

        for (int i = 0; i < unique; i++) // Проверяем, было ли уже такое число
        {
            if (exist[i] == number) 
            {
                count[i]++; // Увеличиваем счетчик встреч данного числа

                newIndex = i;   // Запоминаем индекс числа

                break;
            }
        }

        if (newIndex == -1) 
        {
            exist[unique] = number; // Записываем уникальное число

            count[unique] = 1;  // Устанавливаем количество встреч этого числа

            unique++;
        }
    }

    // Записываем в fileB числа, которые встречаются один раз
    for (int i = 0; i < unique; i++) 
    {
        if (count[i] == 1) 
        {
            fprintf(fileB, "%d\n", exist[i]);
        }
    }

    // Закрываем файлы
    fclose(fileA);
    fclose(fileB);

    printf("Уникальные числа перенесены в fileB\n");

    return 0;
}
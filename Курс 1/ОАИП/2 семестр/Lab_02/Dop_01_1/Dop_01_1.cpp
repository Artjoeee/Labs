// Отключаем предупреждения о безопасности для старых функций fopen и fscanf
#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <iostream>

int main() 
{
    setlocale(0, "ru");

    FILE* fileA, * fileB;

    int number;

    int repeat[100] = {0}; // Массив для хранения уже встреченных чисел
    int count = 0; // Счетчик уникальных чисел

    // Открываем файлы для чтения и записи
    fileA = fopen("fileA.txt", "r");

    fileB = fopen("fileB.txt", "w");


    if (fileA == NULL || fileB == NULL) // Проверяем, удалось ли открыть файлы
    {
        printf("Ошибка открытия файлов.");

        return EXIT_FAILURE;
    }
 
    while (fscanf(fileA, "%d", &number) == 1) // Читаем числа из fileA, копируем уникальные числа в fileB
    {
        int duplicate = 0;
        
        for (int i = 0; i < count; i++) // Проверяем, встречалось ли уже это число
        {
            if (repeat[i] == number) 
            {
                duplicate = 1;

                break;
            }
        }
        if (!duplicate) 
        {
            fprintf(fileB, "%d\n", number);

            repeat[count++] = number; // Добавляем число в список встреченных
        }
    }

    // Закрываем файлы
    fclose(fileA);
    fclose(fileB);

    printf("Числа перенесены в fileB\n");

    return 0;
}
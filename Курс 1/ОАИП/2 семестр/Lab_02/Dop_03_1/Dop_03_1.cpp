// Отключаем предупреждения о безопасности для старых функций fopen и fscanf
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

int main() 
{
    setlocale(0, "ru");

    FILE* fileA, * fileB;

    int current;

    int number[100]{};
    int quantity[100] = {0};
    int written[100] = {0}; // Массив для отслеживания чисел, которые уже были записаны в fileB

    // Открытие файлов для чтения и записи
    fileA = fopen("fileA.txt", "r");

    fileB = fopen("fileB.txt", "w");

    
    if (fileA == NULL || fileB == NULL) // Проверка успешного открытия файлов
    {
        printf("Ошибка при открытии файлов.\n");

        return EXIT_FAILURE;
    }

    int count = 0;

    // Считываем все числа из fileA и считаем их частоту
    while (fscanf(fileA, "%d", &current) != EOF) 
    {
        number[count] = current;

        quantity[current]++;

        count++;
    }

    // Записываем в fileB только числа, которые встречаются более 2 раз
    for (int i = 0; i < count; i++) 
    {
        if (quantity[number[i]] > 2 && !written[number[i]])
        {
            fprintf(fileB, "%d\n", number[i]);

            written[number[i]] = 1;  // Помечаем число как уже записанное
        }
    }

    // Закрытие файлов
    fclose(fileA);
    fclose(fileB);

    printf("Числа перенесены в fileB\n");

    return 0;
}
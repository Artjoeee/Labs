// Отключаем предупреждения о безопасности для старых функций fopen и fscanf
#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <iostream>

int main() 
{   
    setlocale(0, "ru");

    FILE* fileA, * fileB;

    int number;

    // Открываем файлы для чтения и записи
    fileA = fopen("fileA.txt", "r");

    fileB = fopen("fileB.txt", "w");
    
    if (fileA == NULL || fileB == NULL) // Проверяем, удалось ли открыть файлы
    {
        printf("Ошибка открытия файлов.");

        return EXIT_FAILURE;
    }

    while (fscanf(fileA, "%d", &number) == 1) // Копируем положительные числа в fileB
    {
        if (number > 0) 
        {
            fprintf(fileB, "%d\n", number);
        }
    }

    // Закрываем файлы
    fclose(fileA);
    fclose(fileB);

    printf("Числа пересены в fileB\n");

    return 0;
}
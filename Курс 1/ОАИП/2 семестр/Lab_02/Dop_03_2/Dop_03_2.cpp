// Отключаем предупреждения о безопасности для старых функций fopen и fscanf
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <iostream>

int main() 
{
    setlocale(0, "ru");

    FILE* F1, * F2;

    char line[100];

    // Открытие файлов для чтения и записи
    F1 = fopen("F1.txt", "r");

    F2 = fopen("F2.txt", "w");
    
    if (F1 == NULL || F2 == NULL) // Проверка успешного открытия файлов
    {
        printf("Ошибка при открытии файлов.\n");

        return EXIT_FAILURE;
    }

    while (fgets(line, sizeof(line), F1)) // Считываем строки из F1
    {      
        if (isdigit(line[0])) // Проверяем первый символ строки на цифру
        {
            fprintf(F2, "%s", line); // Копируем строку в F2
        }
    }

    // Закрытие файлов
    fclose(F1);
    fclose(F2);

    printf("Строки, начинающиеся с цифры, перенесены в F2.\n");

    return 0;
}
// Отключаем предупреждения о безопасности для старых функций fopen и fscanf
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

int main() 
{
    setlocale(0, "ru");

    FILE* F1, * F2;

    // Открываем файлы для чтения и записи
    F1 = fopen("F1.txt", "r");

    F2 = fopen("F2.txt", "w");

    if (F1 == NULL || F2 == NULL) // Проверяем, удалось ли открыть файлы
    {
        printf("Ошибка при открытии файлов.\n");

        return EXIT_FAILURE;
    }

    char line[100];

    // Копируем только те строки из F1, которые заканчиваются символом 'a'
    while (fgets(line, sizeof(line), F1)) 
    {
        if (line[strlen(line) - 2] == 'a') // Проверяем символ перед символом конца строки ('\n')
        { 
            fprintf(F2, "%s", line);    // Записываем строку в файл F2
        }
    }

    // Закрываем файлы
    fclose(F1);
    fclose(F2);

    printf("Строки, заканчивающиеся на 'а', перенесены в F2\n");

    return 0;
}
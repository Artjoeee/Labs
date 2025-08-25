// Отключаем предупреждения о безопасности для старых функций fopen и fscanf
#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <iostream>

int main() 
{
    setlocale(0, "ru");

    FILE* F1, * F2;

    char line[100];
    int symbol;

    // Открываем файлы для чтения и записи
    F1 = fopen("F1.txt", "r");

    F2 = fopen("F2.txt", "w");

    if (F1 == NULL || F2 == NULL) // Проверяем, удалось ли открыть файлы
    {
        printf("Ошибка открытия файлов.");

        return EXIT_FAILURE;
    }
    
    printf("Введите количество символов: ");

    scanf_s("%d", &symbol);    // Получаем количество символов для фильтрации

    // Читаем строки из F1, копируем строки больше заданного количества символов в F2
    while (fgets(line, sizeof(line), F1) != NULL) 
    {      
        line[strcspn(line, "\n")] = '\0'; // Убираем символ новой строки

        if (strlen(line) > symbol) 
        {
            fputs(line, F2);    // Записываем строку в файл F2

            fprintf(F2, "\n");
        }
    }

    // Закрываем файлы
    fclose(F1);
    fclose(F2);

    printf("Строки перенесены в F2\n");

    return 0;
}
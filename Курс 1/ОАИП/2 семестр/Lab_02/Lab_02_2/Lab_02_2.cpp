// Отключаем предупреждения о безопасности для старых функций fopen и fscanf
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>

int main() 
{
    setlocale(0, "ru");

    FILE* f, * g;

    int num, point;

    // Открываем файлы для чтения и записи
    f = fopen("f.txt", "r");
    g = fopen("g.txt", "w");
 
    if (f == NULL || g == NULL) // Проверяем, удалось ли открыть файлы
    {
        printf("Ошибка открытия файлов.");

        return EXIT_FAILURE;
    }

    printf("Введите пороговое число: ");

    scanf_s("%d", &point);

    // Читаем числа из f, фильтруем числа больше порогового значения и записываем их в g
    while (fscanf(f, "%d", &num) == 1) 
    {
        if (num > point && num >= 10 && num < 100) 
        {
            fprintf(g, "%d\n", num);
        }
    }

    // Закрываем файлы
    fclose(f);
    fclose(g);

    printf("Числа перенесены в файл g\n");

    return 0;
}
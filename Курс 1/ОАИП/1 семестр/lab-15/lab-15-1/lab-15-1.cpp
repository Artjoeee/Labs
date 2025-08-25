#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int findMinIndex(double *array, int size) 
{
    int minIndex = 0;

    for (int i = 0; i < size; ++i) 
    {
        if (array[i] < array[minIndex]) 
        {
            minIndex = i;
        }
    }

    return minIndex + 1 ;
}

double sumBetweenNegatives(double *array, int size) 
{
    int firstNegativeIndex = -1;
    int secondNegativeIndex = -1;
    double sum = 0.0;

    for (int i = 0; i < size; ++i) 
    {
        if (array[i] < 0) 
        {
            if (firstNegativeIndex == -1) 
            {
                firstNegativeIndex = i;
            }
            else if (secondNegativeIndex == -1) 
            {
                secondNegativeIndex = i;

                break;  // Нашли оба отрицательных элемента, выходим из цикла
            }
        }
    }

    if (firstNegativeIndex != -1 && secondNegativeIndex != -1) 
    {
        int start = firstNegativeIndex + 1;
        int end = secondNegativeIndex;

        for (int i = start; i < end; ++i) 
        {
            sum += array[i];
        }
    }

    return sum;
}

int main() 
{
    setlocale(LC_ALL, "RU");

    int size;

    printf("Введите размерность массива: ");
    scanf_s("%d", &size);

    double *array = (double*)malloc(size * sizeof(double));

    printf("Введите элементы массива:\n");

    for (int i = 0; i < size; ++i) 
    {
        scanf_s("%lf", &array[i]);
    }

    int minIndex = findMinIndex(array, size);
    double sum = sumBetweenNegatives(array, size);

    printf("Номер минимального элемента: %d\n", minIndex);

    printf("Сумма элементов между первым и вторым отрицательными элементами: %.2lf\n", sum);

    free(array);

    return 0;
}
// ��������� �������������� � ������������ ��� ������ ������� fopen � fscanf
#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <iostream>

int main() 
{   
    setlocale(0, "ru");

    FILE* fileA, * fileB;

    int number;

    // ��������� ����� ��� ������ � ������
    fileA = fopen("fileA.txt", "r");

    fileB = fopen("fileB.txt", "w");
    
    if (fileA == NULL || fileB == NULL) // ���������, ������� �� ������� �����
    {
        printf("������ �������� ������.");

        return EXIT_FAILURE;
    }

    while (fscanf(fileA, "%d", &number) == 1) // �������� ������������� ����� � fileB
    {
        if (number > 0) 
        {
            fprintf(fileB, "%d\n", number);
        }
    }

    // ��������� �����
    fclose(fileA);
    fclose(fileB);

    printf("����� �������� � fileB\n");

    return 0;
}
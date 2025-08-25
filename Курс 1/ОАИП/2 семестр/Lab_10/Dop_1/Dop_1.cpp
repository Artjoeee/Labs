#include <iostream>
#include <fstream>

using namespace std;

// Рекурсивная функция для генерации всех перестановок чисел
void num(int n, int a[], int index, ofstream& outFile) 
{
    if (index == n) 
    {
        // Записываем перестановку в файл и переходим к следующей перестановке
        for (int i = 0; i < n; i++) 
        {
            outFile << a[i] << " ";
        }

        outFile << endl;

        return;
    }

    // Генерируем все возможные перестановки чисел
    for (int i = 1; i <= n; i++) 
    {
        bool found = false;

        // Проверяем, было ли число i уже использовано в текущей перестановке
        for (int j = 0; j < index; j++) 
        {
            if (a[j] == i) 
            {
                found = true;

                break;
            }
        }

        // Если число i не было использовано, добавляем его к перестановке
        if (!found) 
        {
            a[index] = i;
            num(n, a, index + 1, outFile);
        }
    }
}

int main() 
{
    setlocale(0, "ru");

    int n = 5;
    int* a = new int[n];  // Создаем массив для хранения перестановок

    ofstream outFile("num.txt");  // Открываем файл для записи перестановок

    num(n, a, 0, outFile);

    outFile.close();  // Закрываем файл

    cout << "Перестановки чисел записаны в файл num.txt" << endl;

    return 0;
}
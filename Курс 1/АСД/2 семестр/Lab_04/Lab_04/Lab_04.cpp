#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void maxTotal(int N, vector<int>& prices);
void prizeWinners(int N, vector<int>& results);

// Задача 1: Определение максимальной суммы чека
void maxTotal(int N, vector<int>& prices) 
{
    sort(prices.rbegin(), prices.rend());

    int maxTotal = 0;

    for (int i = 0; i < N; i++) 
    {
        if ((i + 1) % 2 == 0) 
        {
            continue;
        }

        maxTotal += prices[i];
    }

    cout << "Максимальная сумма чека: " << maxTotal << endl;
}

// Задача 2: Определение числа призеров
void prizeWinners(int N, vector<int>& results) 
{
    sort(results.rbegin(), results.rend());

    int winners = 0;
    int prevScore = -1;

    for (int i = 0; i < N; i++) 
    {
        if (results[i] != prevScore) 
        {
            winners++;
            prevScore = results[i];
        }
    }

    cout << "Количество призеров: " << winners << endl;
}

int main() 
{
    setlocale(0, "ru");

    int N;

    cout << "Введите количество товаров (N < 10000): ";
    cin >> N;

    vector<int> prices(N);

    for (int i = 0; i < N; i++) 
    {
        prices[i] = rand() % 100 + 1; // генерация цен товаров от 1 до 100
    }

    maxTotal(N, prices);

    cout << "\nВведите количество участников (N < 10000): ";
    cin >> N;

    vector<int> results(N);

    for (int i = 0; i < N; i++) 
    {
        results[i] = rand() % 100 + 1; // генерация результатов от 1 до 100
    }

    prizeWinners(N, results);

    return 0;
}
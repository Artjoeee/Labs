#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>

using namespace std;

// Функция для случайного перемешивания номеров коробок
vector<int> shuffle_boxes(int n) 
{
    vector<int> boxes(n);

    for (int i = 0; i < n; ++i) 
    {
        boxes[i] = i + 1;
    }

    shuffle(boxes.begin(), boxes.end(), mt19937(random_device()()));

    return boxes;
}

// Алгоритм случайного выбора коробок заключённым
bool random_strategy(const vector<int>& boxes, int prisoner_number) 
{
    vector<int> checked;

    for (int i = 0; i < boxes.size() / 2; ++i) 
    {
        int random_box = rand() % boxes.size() + 1;

        if (boxes[random_box - 1] == prisoner_number) 
        {
            return true;
        }

        checked.push_back(random_box);
    }

    return false;
}

// Алгоритм следования по цепочке номеров
bool looping_strategy(const vector<int>& boxes, int prisoner_number) 
{
    int current_box = prisoner_number;

    for (int i = 0; i < boxes.size() / 2; ++i) 
    { 
        if (boxes[current_box - 1] == prisoner_number) 
        { 
            return true;
        }

        current_box = boxes[current_box - 1];
    }

    return false;
}

// Функция для проведения одного эксперимента
pair<bool, bool> run_experiment(int n) 
{
    vector<int> boxes = shuffle_boxes(n);

    bool random_success = true;
    bool looping_success = true;

    for (int prisoner = 1; prisoner <= n; ++prisoner) 
    {
        if (!random_strategy(boxes, prisoner)) 
        {
            random_success = false;
        }

        if (!looping_strategy(boxes, prisoner)) 
        {
            looping_success = false;
        }
    }

    return { random_success, looping_success };
}

int main() 
{
    setlocale(0, "RU");

    srand(time(nullptr));

    int num_prisoners = 100;
    int num_experiments;

    cout << "Введите количество раундов сравнений: ";
    cin >> num_experiments;

    int random_success_count = 0;
    int looping_success_count = 0;

    for (int i = 0; i < num_experiments; ++i) 
    {
        pair<bool, bool> results = run_experiment(num_prisoners);

        bool random_success = results.first;
        bool looping_success = results.second;

        if (random_success) 
            ++random_success_count;

        if (looping_success) 
            ++looping_success_count;
    }

    cout << "Результаты:\n";
    cout << "Случайный способ: " << random_success_count << " успешных исходов из " << num_experiments << "\n";
    cout << "Следование по цепочке: " << looping_success_count << " успешных исходов из " << num_experiments << "\n";

    return 0;
}

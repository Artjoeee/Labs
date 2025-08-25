#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <random>

using namespace std;

// Функция для заполнения массива случайными числами
void fillArrayWithRandomNumbers(vector<int>& arr, int size, int min, int max) 
{
    random_device rd;
    mt19937 rng(rd());
    uniform_int_distribution<int> uni(min, max);

    arr.clear();

    for (int i = 0; i < size; i++) 
    {
        int num = uni(rng);

        arr.push_back(num);
    }
}

// Функция для вывода массива
void printArray(const vector<int>& arr)
{
    for (int num : arr) 
    {
        cout << num << " ";
    }

    cout << endl;
}

// Функция для сортировки массива пирамидальной сортировкой
void heapSort(vector<int>& arr) 
{
    make_heap(arr.begin(), arr.end());
    sort_heap(arr.begin(), arr.end());
}

// Функция для сортировки массива слиянием
void mergeSort(vector<int>& arr) 
{
    if (arr.size() <= 1)
    {
        return;
    }

    int middle = arr.size() / 2;

    vector<int> left(arr.begin(), arr.begin() + middle);
    vector<int> right(arr.begin() + middle, arr.end());

    mergeSort(left);
    mergeSort(right);

    merge(left.begin(), left.end(), right.begin(), right.end(), arr.begin());
}

int main()
{
    setlocale(0, "ru");

    int size;

    cout << "Введите размер массивов: ";
    cin >> size;

    // Заполнение массивов случайными числами
    vector<int> arrA;
    fillArrayWithRandomNumbers(arrA, size, 1, 100);

    vector<int> arrB;
    fillArrayWithRandomNumbers(arrB, size, 1, 100);

    // Вывод исходных массивов
    cout << "Массив A:" << endl;
    printArray(arrA);

    cout << "Массив B:" << endl;
    printArray(arrB);

    // Формирование массива C
    int minB = *min_element(arrB.begin(), arrB.end());

    vector<int> arrC;

    for (int num : arrA)
    {
        if (num > minB) 
        {
            arrC.push_back(num);
        }
    }

    // Сортировка массива C пирамидальной сортировкой
    clock_t startTime = clock();
    heapSort(arrC);
    clock_t endTime = clock();

    // Вывод отсортированного массива C
    cout << "Массив C (пирамидальная сортировка):" << endl;
    printArray(arrC);

    // Вывод времени выполнения пирамидальной сортировки
    double heapSortTime = double(endTime - startTime) / CLOCKS_PER_SEC;

    cout << "Время выполнения пирамидальной сортировки: " << heapSortTime << " секунд" << endl;

    // Сортировка массива C сортировкой слиянием
    startTime = clock();
    mergeSort(arrC);
    endTime = clock();

    // Вывод отсортированного массива C
    cout << "Массив C (сортировка слиянием):" << endl;
    printArray(arrC);

    // Вывод времени выполнения сортировки слиянием
    double mergeSortTime = double(endTime - startTime) / CLOCKS_PER_SEC;

    cout << "Время выполнения сортировки слиянием: " << mergeSortTime << " секунд" << endl;

    return 0;
}
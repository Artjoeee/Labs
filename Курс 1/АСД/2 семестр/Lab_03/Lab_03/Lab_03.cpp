#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

// Прототипы
void printArray(const vector<int>& arr);
void bubbleSort(vector<int>& arr);
void insertionSort(vector<int>& arr);
void selectionSort(vector<int>& arr);
int partition(vector<int>& arr, int low, int high);
void quickSort(vector<int>& arr, int low, int high);

void printArray(const vector<int>& arr) 
{
    for (const auto& num : arr) 
    {
        cout << num << " ";
    }

    cout << endl;
}

void bubbleSort(vector<int>& arr) 
{
    int n = arr.size();
    bool swapped;

    for (int i = 0; i < n - 1; i++) 
    {
        swapped = false;

        for (int j = 0; j < n - i - 1; j++) 
        {
            if (arr[j] > arr[j + 1]) 
            {
                swap(arr[j], arr[j + 1]);

                swapped = true;
            }
        }

        if (!swapped) 
        {
            break;
        }
    }
}

void insertionSort(vector<int>& arr) 
{
    int n = arr.size();

    for (int i = 1; i < n; i++) 
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) 
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

void selectionSort(vector<int>& arr) 
{
    int n = arr.size();

    for (int i = 0; i < n - 1; i++) 
    {
        int minIndex = i;

        for (int j = i + 1; j < n; j++) 
        {
            if (arr[j] < arr[minIndex]) 
            {
                minIndex = j;
            }
        }

        swap(arr[i], arr[minIndex]);
    }
}

int partition(vector<int>& arr, int low, int high) 
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) 
    {
        if (arr[j] < pivot) 
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) 
{
    if (low < high) 
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() 
{
    setlocale(0, "ru");

    srand(time(NULL));

    int n;

    cout << "Введите число N: ";
    cin >> n;

    vector<int> A(n);

    for (int i = 0; i < n; i++) 
    {
        A[i] = rand() % 1000; // Генерация случайных чисел до 1000
    }

    cout << "Исходный массив A:" << endl;
    printArray(A);

    vector<int> B = A;
    vector<int> C = A;
    vector<int> D = A;
    vector<int> E = A;

    clock_t start, end;

    // Пузырьковая сортировка
    start = clock();
    bubbleSort(B);
    end = clock();

    cout << "\nОтсортированный массив B после пузырьковой сортировки:" << endl;
    printArray(B);
    cout << "Время выполнения пузырьковой сортировки: " << (double)(end - start) / CLOCKS_PER_SEC << " секунд" << endl;

    // Сортировка вставкой 
    start = clock();
    insertionSort(C);
    end = clock();

    cout << "\nОтсортированный массив C после сортировки вставкой:" << endl;
    printArray(C);
    cout << "Время выполнения сортировки вставкой: " << (double)(end - start) / CLOCKS_PER_SEC << " секунд" << endl;

    // Сортировка выбором
    start = clock();
    selectionSort(D);
    end = clock();

    cout << "\nОтсортированный массив D после сортировки выбором:" << endl;
    printArray(D);
    cout << "Время выполнения сортировки выбором: " << (double)(end - start) / CLOCKS_PER_SEC << " секунд" << endl;

    // Быстрая сортировка
    start = clock();
    quickSort(E, 0, E.size() - 1);
    end = clock();

    cout << "\nОтсортированный массив E после быстрой сортировки:" << endl;
    printArray(E);
    cout << "Время выполнения быстрой сортировки: " << (double)(end - start) / CLOCKS_PER_SEC << " секунд" << endl;

    return 0;
}
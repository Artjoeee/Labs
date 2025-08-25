#include <iostream>
#include <cstring>

using namespace std;

void sortNumbers(int* nums, int size) 
{
    for (int i = 0; i < size - 1; ++i) 
    {
        for (int j = 0; j < size - i - 1; ++j) 
        {
            if (nums[j] > nums[j + 1]) 
            {
                int temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }
        }
    }
}

int main() 
{
    setlocale(LC_ALL, "RU");

    const int MAX_NUMBERS = 100;
    char input[MAX_NUMBERS * 2]; // Максимальная длина строки

    cout << "Введите строку с числами, разделенными пробелами: ";

    cin.getline(input, sizeof(input));

    int numbers[MAX_NUMBERS]{};
    int size = 0;

    char *nextToken = nullptr;
    char *token = strtok_s(input, " ", &nextToken);

    while (token != nullptr) 
    {
        numbers[size] = std::atoi(token);
        ++size;
        token = strtok_s(nullptr, " ", &nextToken);
    }

    sortNumbers(numbers, size);

    cout << "Числа в порядке возрастания: ";

    for (int i = 0; i < size; ++i) 
    {
        cout << numbers[i] << " ";
    }

    cout << endl;

    return 0;
}
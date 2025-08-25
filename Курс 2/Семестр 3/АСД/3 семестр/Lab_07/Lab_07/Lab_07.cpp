#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Функция для нахождения всех максимальных возрастающих подпоследовательностей
void findAllLIS(const vector<int>& sequence, vector<vector<int>>& allLIS, vector<vector<int>>& previous, vector<int>& currentLIS, int index) 
{
    currentLIS.push_back(sequence[index]);

    // Если предыдущих элементов нет, то добавляем текущую последовательность в список всех 
    if (previous[index].empty()) 
    {
        allLIS.push_back(vector<int>(currentLIS.rbegin(), currentLIS.rend()));
    }
    else 
    {
        for (int prevIndex : previous[index]) 
        {
            findAllLIS(sequence, allLIS, previous, currentLIS, prevIndex);
        }
    }

    // Убираем текущий элемент после обхода
    currentLIS.pop_back();
}

// Функция для нахождения всех максимальных возрастающих подпоследовательностей
vector<vector<int>> findAllLIS(const vector<int>& sequence) 
{
    int n = sequence.size();

    if (n == 0)
        return {};

    vector<int> lisLength(n, 1);
    vector<vector<int>> previous(n); // Вектор для отслеживания предыдущих индексов

    for (int i = 1; i < n; ++i) 
    {
        for (int j = 0; j < i; ++j) 
        {
            if (sequence[i] > sequence[j]) 
            {
                if (lisLength[i] < lisLength[j] + 1) 
                {
                    lisLength[i] = lisLength[j] + 1;
                    previous[i].clear();
                    previous[i].push_back(j);
                }
                else if (lisLength[i] == lisLength[j] + 1) 
                {
                    previous[i].push_back(j);
                }
            }
        }
    }

    int maxLength = *max_element(lisLength.begin(), lisLength.end());

    vector<vector<int>> allLIS;
    vector<int> currentLIS; // Текущая последовательность

    for (int i = 0; i < n; ++i) 
    {
        if (lisLength[i] == maxLength) 
        {
            findAllLIS(sequence, allLIS, previous, currentLIS, i);
        }
    }

    return allLIS;
}

int main() 
{
    setlocale(0, "RU");

    int n;

    cout << "Введите количество элементов последовательности: ";
    cin >> n;

    if (n <= 0) 
    {
        cout << "Последовательность должна содержать хотя бы один элемент." << endl;
        return 1;
    }

    vector<int> sequence(n); // Вектор для хранения последовательности

    cout << "Введите элементы последовательности: ";

    for (int i = 0; i < n; ++i) 
    {
        cin >> sequence[i];
    }

    // Нахождение всех подпоследовательностей
    vector<vector<int>> allLIS = findAllLIS(sequence);

    cout << "\nДлина максимальной возрастающей подпоследовательности: " << allLIS[0].size() << endl;

    cout << "Все такие подпоследовательности: " << endl;
    for (const auto& lis : allLIS) 
    {
        for (int num : lis) 
        {
            cout << num << " ";
        }

        cout << endl;
    }

    cout << "\nСложнось алгоритма O(n^2): O(" << n * n << ")\n";

    return 0;
}

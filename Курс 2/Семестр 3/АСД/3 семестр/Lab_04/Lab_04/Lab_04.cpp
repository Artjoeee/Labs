#include <iostream>
#include <vector>
#include <string>
#include <utility>

using namespace std;

const int INF = 1e9;

// Функция для вывода матрицы расстояний
void printDistanceMatrix(const vector<vector<int>>& matrix)
{
    // Проходим по каждой строке матрицы
    for (const auto& row : matrix)
    {
        // Проходим по каждому элементу в строке
        for (int val : row)
        {
            if (val == INF)
                cout << "INF ";
            else
                cout << val << " ";
        }

        cout << endl;
    }
}

// Функция для вывода матрицы последовательностей вершин
void printSequenceMatrix(const vector<vector<int>>& matrix, int V)
{
    // Проходим по каждой строке матрицы
    for (int i = 0; i < V; ++i)
    {
        // Проходим по каждому элементу в строке
        for (int j = 0; j < V; ++j)
        {
            if (matrix[i][j] == -1)
                cout << "0 ";
            else
                cout << (matrix[i][j] + 1) << " ";
        }

        cout << endl;
    }
}

// Функция для реализации алгоритма Флойда-Уоршелла
void floydWarshall(vector<vector<int>>& dist, vector<vector<int>>& next, int V)
{
    // Внешний цикл: проходим по каждой вершине как промежуточной вершине k
    for (int k = 0; k < V; ++k)
    {
        // Цикл по всем вершинам i
        for (int i = 0; i < V; ++i)
        {
            // Цикл по всем вершинам j
            for (int j = 0; j < V; ++j)
            {
                // Проверяем, можно ли улучшить кратчайший путь через вершину k
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][j] > dist[i][k] + dist[k][j])
                {
                    // Обновляем значение кратчайшего пути
                    dist[i][j] = dist[i][k] + dist[k][j];

                    // Обновляем матрицу последовательностей, указывая, что кратчайший путь проходит через k
                    next[i][j] = next[i][k];
                }
            }
        }
    }
}

// Функция для восстановления пути и подсчёта суммы рёбер
pair<vector<int>, int> getPathAndWeight(int u, int v, const vector<vector<int>>& next, const vector<vector<int>>& dist) 
{
    if (next[u][v] == u) 
        return { {}, 0 }; // Путь не существует

    vector<int> path = { u };
    int totalWeight = 0;

    // Проходим по пути
    while (u != v) 
    {
        totalWeight += dist[u][next[u][v]]; // Суммируем вес ребра
        u = next[u][v];

        path.push_back(u);
    }

    return { path, totalWeight }; // Возвращаем путь и его вес
}

int main()
{
    setlocale(0, "RU");

    int V = 6;

    // Инициализируем матрицу расстояний (граф)
    vector<vector<int>> dist = {
        {0, 28, 21, 59, 12, 27},
        {7, 0, 24, INF, 21, 9},
        {9, 32, 0, 13, 11, INF},
        {8, INF, 5, 0, 16, INF},
        {14, 13, 15, 10, 0, 22},
        {15, 18, INF, INF, 6, 0}
    };

    // Инициализируем матрицу последовательностей вершин для кратчайших путей
    vector<vector<int>> next_matrix = {
        {0, 2, 3, 4, 5, 6},
        {1, 0, 3, 4, 5, 6},
        {1, 2, 0, 4, 5, 6},
        {1, 2, 3, 0, 5, 6},
        {1, 2, 3, 4, 0, 6},
        {1, 2, 3, 4, 5, 0}
    };

    vector<vector<int>> next(V, vector<int>(V, -1));  // Создаем матрицу, где изначально все пути неопределены

    // Преобразование матрицы последовательностей с индексацией с 0
    for (int i = 0; i < V; ++i)
    {
        for (int j = 0; j < V; ++j)
        {
            if (next_matrix[i][j] == 0)
            {
                next[i][j] = -1;
            }
            else
            {
                next[i][j] = next_matrix[i][j] - 1;  // Иначе уменьшаем значение, чтобы индексация начиналась с 0
            }
        }
    }

    cout << "Исходная матрица расстояний (D0):\n";
    printDistanceMatrix(dist);

    cout << "\nИсходная матрица последовательностей вершин (S0):\n";
    printSequenceMatrix(next, V);

    // Применяем алгоритм Флойда-Уоршелла для поиска кратчайших путей
    floydWarshall(dist, next, V);

    cout << "\nМатрица кратчайших путей (D):\n";
    printDistanceMatrix(dist);

    cout << "\nМатрица последовательностей (S):\n";
    printSequenceMatrix(next, V);

    // Восстановление пути между двумя вершинами
    int start, end;

    cout << "\nВведите начальную и конечную вершины (1 - " << V << "): ";
    cin >> start >> end;

    // Проверка на корректность ввода
    if (start < 1 || start > V || end < 1 || end > V) 
    {
        cout << "Введен некорректный путь\n";

        return 1;
    }

    start--; end--; // Преобразуем в индексацию с 0

    pair<vector<int>, int> result = getPathAndWeight(start, end, next, dist);

    vector<int> path = result.first;
    int totalWeight = result.second;

    if (path.empty()) 
    {
        cout << "Путь не существует.\n";
    }
    else 
    {
        cout << "Кратчайший путь: ";

        for (int v : path) 
        {
            cout << v + 1 << " ";
        }

        cout << "\nСумма рёбер на пути: " << totalWeight << endl;
    }

    cout << "\nСложность алгоритма O(V^3): O(216)\n";

    return 0;
}

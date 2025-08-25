#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <unordered_map>

using namespace std;

// Структура для представления ребра графа
struct Edge
{
    int to;
    int weight;
};

// Функция для реализации алгоритма Дейкстры
vector<int> dijkstra(int start, const vector<vector<Edge>>& graph)
{
    int n = graph.size();  // Количество вершин графа

    // Вектор для хранения минимальных расстояний от стартовой вершины
    vector<int> distances(n, numeric_limits<int>::max());

    distances[start] = 0;

    // Очередь с приоритетом для хранения вершин по их минимальным расстояниям
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({ 0, start });

    while (!pq.empty())
    {
        int current_distance = pq.top().first;   // Извлекаем минимальное расстояние
        int current_vertex = pq.top().second;    // Извлекаем соответствующую вершину
        pq.pop();                                // Удаляем элемент из очереди

        // Если текущее расстояние больше уже известного минимального
        if (current_distance > distances[current_vertex])
            continue;

        // Обходим все соседние вершины текущей вершины
        for (const Edge& edge : graph[current_vertex])
        {
            int neighbor = edge.to;             // Получаем номер соседней вершины
            int new_distance = current_distance + edge.weight;

            // Если новое расстояние меньше текущего известного
            if (new_distance < distances[neighbor])
            {
                distances[neighbor] = new_distance;
                pq.push({ new_distance, neighbor }); // Добавляем вершину в очередь с обновленным расстоянием
            }
        }
    }

    return distances;  // Возвращаем вектор минимальных расстояний
}

int main()
{
    setlocale(0, "RU");

    // Хеш-таблица для сопоставления буквенных имен вершин с их индексами
    unordered_map<char, int> vertexIndex;

    vector<char> indexVertex; // Массив для преобразования индексов обратно в буквенные вершины

    // Задаем вершины графа
    string vertices = "ABCDEFGHI";

    int numVertices = vertices.size();  // Количество вершин

    // Заполняем хеш-таблицу и массив соответствиями вершин и индексов
    for (int i = 0; i < numVertices; i++)
    {
        vertexIndex[vertices[i]] = i;  // Присваиваем каждой вершине индекс
        indexVertex.push_back(vertices[i]);  // Добавляем вершину в массив для обратного преобразования
    }

    int n = numVertices;  // Количество вершин графа

    vector<vector<Edge>> graph(n);  // Создаем список смежности для хранения графа

    // Добавляем ребра в граф
    graph[vertexIndex['A']].push_back({ vertexIndex['B'], 7 });
    graph[vertexIndex['B']].push_back({ vertexIndex['A'], 7 });

    graph[vertexIndex['A']].push_back({ vertexIndex['C'], 10 });
    graph[vertexIndex['C']].push_back({ vertexIndex['A'], 10 });

    graph[vertexIndex['B']].push_back({ vertexIndex['G'], 27 });
    graph[vertexIndex['G']].push_back({ vertexIndex['B'], 27 });

    graph[vertexIndex['B']].push_back({ vertexIndex['F'], 9 });
    graph[vertexIndex['F']].push_back({ vertexIndex['B'], 9 });

    graph[vertexIndex['G']].push_back({ vertexIndex['I'], 15 });
    graph[vertexIndex['I']].push_back({ vertexIndex['G'], 15 });

    graph[vertexIndex['F']].push_back({ vertexIndex['C'], 8 });
    graph[vertexIndex['C']].push_back({ vertexIndex['F'], 8 });

    graph[vertexIndex['F']].push_back({ vertexIndex['H'], 11 });
    graph[vertexIndex['H']].push_back({ vertexIndex['F'], 11 });

    graph[vertexIndex['H']].push_back({ vertexIndex['D'], 17 });
    graph[vertexIndex['D']].push_back({ vertexIndex['H'], 17 });

    graph[vertexIndex['H']].push_back({ vertexIndex['I'], 15 });
    graph[vertexIndex['I']].push_back({ vertexIndex['H'], 15 });

    graph[vertexIndex['C']].push_back({ vertexIndex['E'], 31 });
    graph[vertexIndex['E']].push_back({ vertexIndex['C'], 31 });

    graph[vertexIndex['E']].push_back({ vertexIndex['D'], 32 });
    graph[vertexIndex['D']].push_back({ vertexIndex['E'], 32 });

    graph[vertexIndex['D']].push_back({ vertexIndex['I'], 21 });
    graph[vertexIndex['I']].push_back({ vertexIndex['D'], 21 });

    char startVertex;

    do
    {
        cout << "Введите стартовую вершину (A-I): ";
        cin >> startVertex;

    } while (vertexIndex.find(startVertex) == vertexIndex.end());  // Пока введенная вершина не найдена

    // Преобразуем стартовую вершину в индекс
    int start = vertexIndex[startVertex];

    // Вызываем функцию Дейкстры и сохраняем результат
    vector<int> distances = dijkstra(start, graph);

    cout << "Расстояния от вершины " << startVertex << ":" << endl;

    for (int i = 0; i < n; i++)
    {
        if (distances[i] == numeric_limits<int>::max())
        {
            cout << "Вершина " << indexVertex[i] << ": бесконечность" << endl;
        }
        else
        {
            cout << "Вершина " << indexVertex[i] << ": " << distances[i] << endl;
        }
    }

    cout << "Сложность алгоритма: O(31,4900028)" << endl;

    return 0;
}

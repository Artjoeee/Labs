#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>

using namespace std;

// Класс для представления графа списком рёбер
class GraphEdges 
{
public:
    vector<pair<int, int>> edges;

    void addEdge(int u, int v) 
    {
        edges.emplace_back(u, v);
    }

    // Преобразование списка рёбер в список смежности
    unordered_map<int, vector<int>> toAdjList() const 
    {
        unordered_map<int, vector<int>> adjList;

        for (const auto& edge : edges) 
        {
            adjList[edge.first].push_back(edge.second);
            adjList[edge.second].push_back(edge.first); // Для неориентированного графа
        }

        return adjList;
    }
};

// Класс для представления графа матрицей смежности
class GraphMatrix 
{
public:
    vector<vector<int>> matrix;  // Матрица смежности

    int n;  // Количество вершин

    // Инициализация матрицы размером (n+1) x (n+1) для индексации с 1
    GraphMatrix(int n) : n(n) 
    {
        matrix.assign(n + 1, vector<int>(n + 1, 0));
    }

    // Добавить ребро
    void addEdge(int u, int v) 
    {
        if (u > n || v > n || u < 1 || v < 1) 
        {
            cout << "Неверные вершины: " << u << ", " << v << endl;

            return;
        }

        matrix[u][v] = 1;
        matrix[v][u] = 1; // Для неориентированного графа
    }

    // Преобразование матрицы смежности в список смежности
    unordered_map<int, vector<int>> toAdjList() const 
    {
        unordered_map<int, vector<int>> adjList;

        for (int i = 1; i <= n; ++i) 
        {
            for (int j = 1; j <= n; ++j) 
            {
                if (matrix[i][j] == 1) 
                {
                    adjList[i].push_back(j);
                }
            }
        }

        return adjList;
    }

    // Вывести матрицу смежности
    void printMatrix() const 
    {
        cout << "Матрица смежности:\n   ";

        for (int i = 1; i <= n; ++i) 
        {
            cout << i << " ";
        }

        cout << endl;

        for (int i = 1; i <= n; ++i) 
        {
            cout << i << ": ";

            for (int j = 1; j <= n; ++j)
            {
                cout << matrix[i][j] << " ";
            }

            cout << endl;
        }
    }
};

// Класс для представления графа списком смежности
class GraphAdjList 
{
public:
    unordered_map<int, vector<int>> adjList;

    // Добавить ребро
    void addEdge(int u, int v) 
    {
        adjList[u].push_back(v);
        adjList[v].push_back(u); // Для неориентированного графа
    }
};

// Класс для выполнения BFS и DFS
class GraphTraversal 
{
public:
    unordered_map<int, vector<int>> adjList;

    // Конструктор на основе списка смежности
    GraphTraversal(const unordered_map<int, vector<int>>& adjList) : adjList(adjList) {}

    // Поиск в ширину (BFS)
    void BFS(int start) const 
    {
        vector<bool> visited(adjList.size() + 1, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        cout << "BFS: ";
        while (!q.empty()) 
        {
            int vertex = q.front();
            q.pop();

            cout << vertex << " ";

            for (int neighbor : adjList.at(vertex)) 
            {
                if (!visited[neighbor]) 
                {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }

        cout << endl;
    }

    // Поиск в глубину (DFS)
    void DFS(int start) const 
    {
        vector<bool> visited(adjList.size() + 1, false);
        stack<int> s;

        s.push(start);

        cout << "DFS: ";
        while (!s.empty()) 
        {
            int vertex = s.top();
            s.pop();

            if (!visited[vertex]) 
            {
                visited[vertex] = true;

                cout << vertex << " ";
            }

            // Добавляем соседей в стек в обратном порядке для правильного обхода
            for (auto it = adjList.at(vertex).rbegin(); it != adjList.at(vertex).rend(); ++it) 
            {
                if (!visited[*it]) 
                {
                    s.push(*it);
                }
            }
        }

        cout << endl;
    }
};

int main() 
{
    setlocale(0, "RU");

    int vertices = 10;  // Количество вершин
    int choice;

    // Инициализация объектов для различных способов хранения графа
    GraphEdges graphEdges;
    GraphMatrix graphMatrix(vertices);
    GraphAdjList graphAdjList;

    // Добавляем рёбра согласно новому списку
    vector<pair<int, int>> newEdges = {
        {1, 2}, {1, 5}, {2, 7}, {2, 8}, {7, 8},
        {8, 3}, {5, 6}, {6, 4}, {6, 9}, {4, 9}, {9, 10}
    };

    for (const auto& edge : newEdges)
    {
        graphEdges.addEdge(edge.first, edge.second);
        graphMatrix.addEdge(edge.first, edge.second);
        graphAdjList.addEdge(edge.first, edge.second);
    }

    cout << "Выберите способ хранения графа:\n";
    cout << "1. Список рёбер\n";
    cout << "2. Матрица смежности\n";
    cout << "3. Список смежности\n";
    cout << "Введите ваш выбор: ";
    cin >> choice;

    GraphTraversal* g = nullptr;

    switch (choice) 
    {
    case 1: 
    {
        cout << "\nИспользуется список рёбер.\n";

        unordered_map<int, vector<int>> adjList = graphEdges.toAdjList();
        g = new GraphTraversal(adjList);

        break;
    }
    case 2: 
    {
        cout << "\nИспользуется матрица смежности.\n";

        graphMatrix.printMatrix();

        unordered_map<int, vector<int>> adjList = graphMatrix.toAdjList();
        g = new GraphTraversal(adjList);

        break;
    }
    case 3: 
    {
        cout << "\nИспользуется список смежности.\n";

        cout << "Список смежности:\n";
        for (const auto& pair : graphAdjList.adjList) 
        {
            cout << pair.first << ": ";

            for (const auto& neighbor : pair.second) 
            {
                cout << neighbor << " ";
            }

            cout << endl;
        }

        g = new GraphTraversal(graphAdjList.adjList);

        break;
    }
    default:
        cout << "Неверный выбор!" << endl;

        return 1;
    }

    if (g != nullptr) 
    {
        int startVertex;

        cout << "\nВведите стартовую вершину для обхода (BFS и DFS): ";
        cin >> startVertex;

        cout << "\nВыполнение обходов BFS и DFS начиная с вершины " << startVertex << ":\n";

        g->BFS(startVertex);
        g->DFS(startVertex);

        delete g;
    }

    cout << "\nСложность BFS и DFS при списке смежности: O(V + E): " << 21 << endl;
    cout << "Сложность при списке рёбер O(V): " << 10 << endl;
    cout << "Сложность при матрице смежности: O(V^2): " << 100 << endl;

    return 0;
}
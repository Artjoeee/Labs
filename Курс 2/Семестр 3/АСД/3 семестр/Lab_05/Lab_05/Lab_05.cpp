#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

const int INF = INT_MAX;

// Функция для нахождения вершины с минимальным ключевым значением среди тех, что ещё не включены
int minKey(const vector<int>& key, const vector<bool>& inMST, int V)
{
    int min = INF;
    int min_index{};

    for (int v = 0; v < V; v++)
        if (!inMST[v] && key[v] < min)
        {
            min = key[v];
            min_index = v;
        }

    return min_index;
}

// Алгоритм Прима
void primMST(const vector<vector<int>>& graph, int V)
{
    vector<int> parent(V);
    vector<int> key(V, INF);
    vector<bool> inMST(V, false);

    int totalWeight = 0;

    for (int count = 0; count < V - 1; count++)
    {
        int u = minKey(key, inMST, V);

        // Включаем найденную вершину
        inMST[u] = true;

        // Обновляем ключевые значения и родительские вершины для всех соседей выбранной вершины.
        for (int v = 0; v < V; v++)
            if (graph[u][v] && !inMST[v] && graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
    }

    cout << "Ребра минимального остовного дерева (Прима):\n";

    for (int i = 1; i < V; i++)
    {
        cout << (parent[i] + 1) << " - " << (i + 1) << " \tВес: " << graph[i][parent[i]] << "\n";
        totalWeight += graph[i][parent[i]];
    }

    cout << "Общий вес минимального остовного дерева: " << totalWeight << "\n";
    cout << "Сложность алгоритма O(V^2): O(64)\n\n";
}


//----------------------------------------------------------------------------------------------------


// Структура для представления ребра графа
struct Edge
{
    int src, dest, weight;
};

// Структура для представления графа
struct Graph
{
    int V, E;
    vector<Edge> edges;
};

// Структура для представления множества
struct Subset
{
    int parent;
    int rank;
};


// Функция для поиска корня множества
int find(vector<Subset>& subsets, int i)
{
    // Если текущий элемент не является своим собственным родителем
    if (subsets[i].parent != i)
        // Выполняем сжатие путей, присваивая текущему элементу непосредственного родителя
        subsets[i].parent = find(subsets, subsets[i].parent);

    return subsets[i].parent;
}

// Функция для объединения двух множеств по рангу
void Union(vector<Subset>& subsets, int x, int y)
{
    // Находим корни множеств, к которым принадлежат x и y.
    int rootX = find(subsets, x);
    int rootY = find(subsets, y);

    // Объединяем множества на основе их рангов.
    if (subsets[rootX].rank < subsets[rootY].rank)
        subsets[rootX].parent = rootY;
    else if (subsets[rootX].rank > subsets[rootY].rank)
        subsets[rootY].parent = rootX;
    else
    {
        subsets[rootY].parent = rootX;
        subsets[rootX].rank++;
    }
}

// Функция для сравнения двух рёбер по весу
bool compareEdges(Edge a, Edge b)
{
    return a.weight < b.weight;
}

// Алгоритм Краскала
void kruskalMST(Graph& graph)
{
    vector<Edge> result;
    vector<Subset> subsets(graph.V); 

    int totalWeightEdge = 0;

    // Инициализация множеств
    for (int v = 0; v < graph.V; ++v)
    {
        subsets[v].parent = v;  // Изначально каждый элемент является родителем самого себя
        subsets[v].rank = 0;
    }

    sort(graph.edges.begin(), graph.edges.end(), compareEdges);

    int e = 0;
    int i = 0;  // Индекс для перебора отсортированных рёбер.

    while (e < graph.V - 1 && i < graph.E)
    {
        Edge nextEdge = graph.edges[i++];

        // Находим корни для вершин src и dest, чтобы проверить, принадлежат ли они разным компонентам.
        int x = find(subsets, nextEdge.src);
        int y = find(subsets, nextEdge.dest);

        if (x != y)
        {
            result.push_back(nextEdge);  // Добавляем ребро
            Union(subsets, x, y);
            e++;
        }
    }

    cout << "Ребра минимального остовного дерева (Краскала):\n";

    for (auto& edge : result)
    {
        cout << edge.src + 1 << " - " << edge.dest + 1 << " \tВес: " << edge.weight << "\n";
        totalWeightEdge += edge.weight;
    }

    cout << "Общий вес минимального остовного дерева: " << totalWeightEdge << "\n";
    cout << "Сложность алгоритма O(E * log(v)): O(33,27)\n";
}


int main()
{
    setlocale(0, "RU");

    int V = 8;

    vector<vector<int>> graph = {
        {0, 2, 0, 8, 2, 0, 0, 0},
        {2, 0, 3, 10, 5, 0, 0, 0},
        {0, 3, 0, 0, 12, 0, 0, 7},
        {8, 10, 0, 0, 14, 3, 1, 0},
        {2, 5, 12, 14, 0, 11, 4, 8},
        {0, 0, 0, 3, 11, 0, 6, 0},
        {0, 0, 0, 1, 4, 6, 0, 9},
        {0, 0, 7, 0, 8, 0, 9, 0}
    };

    int N = 8, M = 16;

    Graph graphEdge = { N, M, {
        {0, 1, 2}, {1, 2, 3}, {0, 3, 8}, {0, 4, 2},
        {1, 3, 10}, {1, 4, 5}, {2, 4, 12}, {3, 4, 14},
        {3, 5, 3}, {4, 5, 11}, {5, 6, 6}, {2, 7, 7},
        {4, 7, 8}, {6, 7, 9}, {3, 6, 1}, {4, 6, 4}
    } };

    primMST(graph, V);
    kruskalMST(graphEdge);

    return 0;
}

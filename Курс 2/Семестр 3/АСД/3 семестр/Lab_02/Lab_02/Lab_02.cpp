#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e9;

static vector<int> bfs(const vector<vector<int>>& graph, int start) 
{
    vector<int> dist(graph.size(), INF);
    queue<int> q;

    dist[start] = 0;
    q.push(start);

    while (!q.empty()) 
    {
        int v = q.front();
        q.pop();

        for (int to : graph[v]) 
        {
            if (dist[to] > dist[v] + 1) 
            {
                dist[to] = dist[v] + 1;
                q.push(to);
            }
        }
    }

    return dist;
}

int main() 
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    // Создаем граф с учетом, что вершины начинаются с 1
    vector<vector<int>> graph(vertexCount + 1);

    for (int i = 0; i < edgeCount; i++) 
    {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int start;
    cin >> start;

    // Обрабатываем BFS с учетом, что индексы вершин начинаются с 1
    vector<int> dist = bfs(graph, start);

    for (int i = 1; i < dist.size(); i++) 
    {
        if (dist[i] != INF)
            cout << dist[i] << " ";
        else
            cout << "X";
    }

    return 0;
}

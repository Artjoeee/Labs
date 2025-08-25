#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

const double evaporationRate = 0.5;
const double Q = 100.0;

// Функция для генерации случайной матрицы расстояний
void generateRandomDistances(vector<vector<double>>& distances, int n)
{
    srand(time(0));

    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            distances[i][j] = distances[j][i] = rand() % 100 + 1;
        }
    }
}

// Функция для вывода матрицы расстояний
void displayDistances(const vector<vector<double>>& distances, int n)
{
    cout << "Матрица расстояний:" << endl;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << distances[i][j] << "\t";
        }

        cout << endl;
    }
}

// Функция для проверки, был ли город посещен
bool isVisited(const vector<int>& path, int node)
{
    return find(path.begin(), path.end(), node) != path.end();
}

// Функция для выбора следующего города на основе вероятностей
int selectNextCity(const vector<vector<double>>& pheromones, const vector<vector<double>>& distances,
    const vector<int>& path, int currentCity, double alpha, double beta, int n)
{
    vector<double> probabilities(n, 0.0);
    double totalProbability = 0.0;

    for (int nextCity = 0; nextCity < n; ++nextCity)
    {
        if (!isVisited(path, nextCity))
        {
            probabilities[nextCity] = pow(pheromones[currentCity][nextCity], alpha) * pow(1.0 / distances[currentCity][nextCity], beta);

            totalProbability += probabilities[nextCity];
        }
    }

    double randValue = (rand() / (double)RAND_MAX) * totalProbability;
    double cumulativeProbability = 0.0;

    for (int nextCity = 0; nextCity < n; ++nextCity)
    {
        if (!isVisited(path, nextCity))
        {
            cumulativeProbability += probabilities[nextCity];

            if (cumulativeProbability >= randValue)
            {
                return nextCity;
            }
        }
    }

    return -1;
}

// Функция для обновления феромонов
void updatePheromones(vector<vector<double>>& pheromones,
    const vector<vector<int>>& allPaths, const vector<double>& allPathLengths, int n)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            pheromones[i][j] *= (1.0 - evaporationRate);
        }
    }

    // Этап добавления феромонов
    for (size_t ant = 0; ant < allPaths.size(); ++ant)
    {
        const auto& path = allPaths[ant];
        double pathLength = allPathLengths[ant];

        for (size_t i = 0; i < path.size() - 1; ++i)
        {
            int from = path[i];
            int to = path[i + 1];

            pheromones[from][to] += Q / pathLength;
            pheromones[to][from] += Q / pathLength;
        }
    }
}

// Функция муравьиного алгоритма
pair<vector<int>, double> antColonyOptimization(int n, int iterations, double alpha, double beta, double initialPheromone)
{
    vector<vector<double>> distances(n, vector<double>(n, 0.0));
    vector<vector<double>> pheromones(n, vector<double>(n, initialPheromone));

    generateRandomDistances(distances, n);
    displayDistances(distances, n);

    vector<int> bestPath;
    double bestPathLength = numeric_limits<double>::infinity();

    for (int iter = 0; iter < iterations; ++iter)
    {
        vector<vector<int>> allPaths;
        vector<double> allPathLengths;

        for (int ant = 0; ant < n; ++ant)
        {
            vector<int> path;
            path.push_back(ant); 

            double pathLength = 0.0;

            while (path.size() < n)
            {
                int currentCity = path.back();
                int nextCity = selectNextCity(pheromones, distances, path, currentCity, alpha, beta, n);

                pathLength += distances[currentCity][nextCity];
                path.push_back(nextCity);
            }

            pathLength += distances[path.back()][path.front()];
            path.push_back(path.front());

            allPaths.push_back(path);
            allPathLengths.push_back(pathLength);

            if (pathLength < bestPathLength)
            {
                bestPath = path;
                bestPathLength = pathLength;
            }
        }

        updatePheromones(pheromones, allPaths, allPathLengths, n);

        cout << "Итерация " << iter + 1 << ":" << endl;
        cout << "Лучший маршрут: ";

        for (int city : bestPath) 
        {
            cout << city << " ";
        }

        cout << endl;
        cout << "Расстояние маршрута: " << bestPathLength << endl;
    }

    return { bestPath, bestPathLength };
}

int main()
{
    setlocale(0, "RU");

    int n, iterations;
    double initialPheromone, alpha, beta;

    cout << "Введите количество городов (N): ";
    cin >> n;

    cout << "Введите начальное значение феромонов: ";
    cin >> initialPheromone;

    cout << "Введите альфа (влияние феромонов): ";
    cin >> alpha;

    cout << "Введите бета (влияние расстояния): ";
    cin >> beta;

    cout << "Введите количество итераций: ";
    cin >> iterations;

    auto result = antColonyOptimization(n, iterations, alpha, beta, initialPheromone);

    cout << "Лучший найденный маршрут: ";

    for (int city : result.first) 
    {
        cout << city << " ";
    }

    cout << endl;
    cout << "Расстояние маршрута: " << result.second << endl;

    return 0;
}

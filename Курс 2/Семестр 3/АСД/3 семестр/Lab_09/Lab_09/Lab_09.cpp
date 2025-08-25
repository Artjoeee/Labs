#include <iostream>
#include <vector>
#include <random>
#include <numeric>
#include <string>

using namespace std;

const int INF = numeric_limits<int>::max();

vector<vector<int>> graph;

random_device rd;
mt19937 gen(rd());
uniform_real_distribution<> dis(0.0, 1.0);

struct Chromosome
{
    vector<int> path;
    int fitness;

    Chromosome(vector<int> p, int f) : path(p), fitness(f) {}
};


int calculateDistance(const vector<int>& path)
{
    int totalDistance = 0;

    for (size_t i = 0; i < path.size() - 1; ++i)
    {
        totalDistance += graph[path[i]][path[i + 1]];
    }

    totalDistance += graph[path.back()][path[0]];

    return totalDistance;
}


vector<Chromosome> initializePopulation(int populationSize, int numCities)
{
    vector<Chromosome> population;
    vector<int> initialPath(numCities);

    iota(initialPath.begin(), initialPath.end(), 0);

    for (int i = 0; i < populationSize; ++i)
    {
        shuffle(initialPath.begin(), initialPath.end(), gen);

        int fitness = calculateDistance(initialPath);

        population.emplace_back(initialPath, fitness);
    }

    return population;
}


// Функция турнира для отбора родителей
Chromosome tournamentSelection(const vector<Chromosome>& population)
{
    int tournamentSize = 3;

    vector<Chromosome> tournament;

    for (int i = 0; i < tournamentSize; ++i)
    {
        int randomIndex = rand() % population.size();

        tournament.push_back(population[randomIndex]);
    }

    return *min_element(tournament.begin(), tournament.end(),
        [](const Chromosome& a, const Chromosome& b)
        {
            return a.fitness < b.fitness;
        });
}


// Функция скрещивания
pair<Chromosome, Chromosome> crossover(const Chromosome& parent1, const Chromosome& parent2)
{
    int size = parent1.path.size();

    vector<int> child1(size, -1), child2(size, -1);

    int start = rand() % size;
    int end = start + rand() % (size - start);

    for (int i = start; i <= end; ++i)
    {
        child1[i] = parent1.path[i];
        child2[i] = parent2.path[i];
    }

    auto fillChild = [&](vector<int>& child, const vector<int>& parent)
    {
        int currentIndex = (end + 1) % size;

        for (int i = 0; i < size; ++i)
        {
            int city = parent[(end + 1 + i) % size];

            if (find(child.begin(), child.end(), city) == child.end())
            {
                child[currentIndex] = city;
                currentIndex = (currentIndex + 1) % size;
            }
        }
    };

    fillChild(child1, parent2.path);
    fillChild(child2, parent1.path);

    return { Chromosome(child1, calculateDistance(child1)), Chromosome(child2, calculateDistance(child2)) };
}


// Функция мутации хромосомы
void mutate(Chromosome& chromosome, double mutationRate)
{
    if (dis(gen) < mutationRate)
    {
        int idx1 = rand() % chromosome.path.size();
        int idx2 = rand() % chromosome.path.size();

        swap(chromosome.path[idx1], chromosome.path[idx2]);

        chromosome.fitness = calculateDistance(chromosome.path);
    }
}


void printGraph()
{
    cout << "\nМатрица смежности:" << endl;

    for (const auto& row : graph)
    {
        for (int weight : row)
        {
            cout << (weight == INF ? "INF" : to_string(weight)) << "\t";
        }

        cout << endl;
    }

    cout << endl;
}


void addCity()
{
    for (auto& row : graph)
    {
        row.push_back(INF);
    }

    graph.push_back(vector<int>(graph.size() + 1, INF));
    graph.back().back() = 0;

    cout << "\nГород добавлен" << endl;

    printGraph();
}


void removeCity(int cityIndex)
{
    if (cityIndex < 0 || cityIndex >= graph.size())
    {
        cout << "\nНекорректный индекс города" << endl;
        return;
    }

    graph.erase(graph.begin() + cityIndex);

    for (auto& row : graph)
    {
        row.erase(row.begin() + cityIndex);
    }

    cout << "\nГород удалён" << endl;

    printGraph();
}


void updateRoad(int city1, int city2, int weight)
{
    if (city1 < 0 || city2 < 0 || city1 >= graph.size() || city2 >= graph.size())
    {
        cout << "\nНекорректные индексы городов" << endl;
        return;
    }

    graph[city1][city2] = weight;
    graph[city2][city1] = weight;

    cout << "\nДорога обновлена" << endl;

    printGraph();
}


// Функция генетического алгоритма
void geneticAlgorithm(int populationSize, int numGenerations, double mutationRate, int numCrossovers, int offspringPerCrossover, int numCities)
{
    auto population = initializePopulation(populationSize, numCities);

    for (int generation = 0; generation < numGenerations; ++generation)
    {
        vector<Chromosome> newPopulation;

        for (int i = 0; i < numCrossovers; ++i)
        {
            auto parent1 = tournamentSelection(population);
            auto parent2 = tournamentSelection(population);

            auto offspring = crossover(parent1, parent2);

            Chromosome child1 = offspring.first;
            mutate(child1, mutationRate);

            Chromosome child2 = offspring.second;
            mutate(child2, mutationRate);

            newPopulation.push_back(child1);
            newPopulation.push_back(child2);

            
            for (int j = 2; j < offspringPerCrossover; ++j)
            {
                auto extraOffspring = crossover(parent1, parent2);

                Chromosome extraChild = extraOffspring.first;

                mutate(extraChild, mutationRate);

                newPopulation.push_back(extraChild);
            }
        }

        population = newPopulation;

        auto& bestChromosome = *min_element(population.begin(), population.end(),
            [](const Chromosome& a, const Chromosome& b)
            {
                return a.fitness < b.fitness;
            });

        cout << "Поколение: " << generation + 1
            << ", Лучшая дистанция: " << bestChromosome.fitness
            << ", Маршрут: ";

        for (int city : bestChromosome.path)
        {
            cout << city + 1;
        }

        cout << endl;
    }

    cout << endl;
}


int main()
{
    setlocale(0, "RU");

    graph = {
        {0, 10, 15, 20, 25, 30, 35, 40},
        {10, 0, 35, 25, 15, 20, 30, 45},
        {15, 35, 0, 30, 20, 25, 40, 50},
        {20, 25, 30, 0, 25, 35, 20, 30},
        {25, 15, 20, 25, 0, 10, 30, 20},
        {30, 20, 25, 35, 10, 0, 40, 25},
        {35, 30, 40, 20, 30, 40, 0, 15},
        {40, 45, 50, 30, 20, 25, 15, 0}
    };

    int choice;

    do
    {
        cout << "Меню:\n"
            << "1. Добавить город\n"
            << "2. Удалить город\n"
            << "3. Изменить дорогу между городами\n"
            << "4. Запустить генетический алгоритм\n"
            << "5. Вывести матрицу смежности\n"
            << "0. Выход\n"
            << "\nВаш выбор: ";

        cin >> choice;

        switch (choice)
        {
            case 1:
            {
                addCity();
                break;
            }
            case 2:
            {
                int cityIndex;

                cout << "\nВведите индекс города для удаления: ";
                cin >> cityIndex;

                removeCity(cityIndex);
                break;
            }
            case 3:
            {
                int city1, city2, weight;

                cout << "\nВведите два города и вес дороги: ";
                cin >> city1 >> city2 >> weight;

                updateRoad(city1, city2, weight); 
                break;
            }
            case 4:
            {
                int populationSize, numGenerations, numCrossovers, offspringPerCrossover;
                int numCities = graph.size();

                double mutationRate;

                cout << "\nВведите изначальный размер популяции: ";
                cin >> populationSize;

                cout << "Введите количество скрещиваний (каждое создаёт потомков): ";
                cin >> numCrossovers;

                cout << "Введите количество потомков на одно скрещивание: ";
                cin >> offspringPerCrossover;

                cout << "Введите количество поколений: ";
                cin >> numGenerations;

                cout << "Введите показатель мутации (например, 0.1): ";
                cin >> mutationRate;

                cout << "\nГенетического алгоритм\n" << endl;

                geneticAlgorithm(populationSize, numGenerations, mutationRate, numCrossovers, offspringPerCrossover, numCities);
                break;
            }
            case 5:
            {
                printGraph();
                break;
            }
            case 0:
            {
                cout << "\nВыход." << endl;
                break;
            }
            default:
            {
                cout << "\nНекорректный выбор!" << endl;
            }
        }

    } while (choice != 0);

    return 0;
}

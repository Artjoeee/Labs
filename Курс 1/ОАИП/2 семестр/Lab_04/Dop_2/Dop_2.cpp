#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <Windows.h>

using namespace std;

// Структура для хранения информации о поезде
struct Train 
{
    string destination; // Пункт назначения
    int trainNumber; // Номер поезда
    int departureTime; // Время отправления
};

// Функция для сравнения поездов по названиям пунктов назначения
bool compareTrains(const Train& train1, const Train& train2) 
{
    return train1.destination < train2.destination;
}

int main() 
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int numTrains = 8;

    vector<Train> trains(numTrains); // Создаем вектор поездов

    // Ввод информации о поездах
    for (int i = 0; i < numTrains; ++i) 
    {
        cout << "Введите информацию о поезде " << i + 1 << ":" << endl;

        cout << "Пункт назначения: ";
        cin >> trains[i].destination;

        cout << "Номер поезда: ";
        cin >> trains[i].trainNumber;

        cout << "Время отправления: ";
        cin >> trains[i].departureTime;
    }

    // Сортируем поезда по названиям пунктов назначения
    sort(trains.begin(), trains.end(), compareTrains);

    int time;

    cout << "Введите текущее время: ";
    cin >> time;

    bool foundTrain = false;

    cout << "Поезда, отправляющиеся после " << time << ":" << endl;

    // Поиск и вывод информации о поездах, отправляющихся после указанного времени
    for (const Train& train : trains) 
    {
        if (train.departureTime > time) 
        {
            foundTrain = true;

            cout << "Номер поезда: " << train.trainNumber 
                << ", Пункт назначения: " << train.destination 
                << ", Время отправления: " << train.departureTime << endl;
        }
    }

    if (!foundTrain) 
    {
        cout << "Поездов, отправляющихся после указанного времени, нет." << endl;
    }

    return 0;
}
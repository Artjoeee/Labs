#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <Windows.h>

using namespace std;

// Структура для хранения информации о санаторных путевках
struct Sanatorium
{
    string name;
    string location;
    string profile;
    int availability;
};

// Функция для сравнения санаториев по названию
bool compareSanatorium(const Sanatorium& s1, const Sanatorium& s2)
{
    return s1.name < s2.name;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int numSanatoriums = 4;

    // Создание вектора структур Sanatorium
    vector<Sanatorium> sanatoriums(numSanatoriums);

    // Ввод информации о санаторных путевках
    for (int i = 0; i < numSanatoriums; ++i)
    {
        cout << "Введите информацию о санатории " << i + 1 << ":" << endl;

        cout << "Название санатория: ";
        cin >> sanatoriums[i].name;

        cout << "Местоположение: ";
        cin >> sanatoriums[i].location;

        cout << "Лечебный профиль: ";
        cin >> sanatoriums[i].profile;

        cout << "Количество путевок: ";
        cin >> sanatoriums[i].availability;
    }

    // Сортировка санаториев по лечебному профилю
    sort(sanatoriums.begin(), sanatoriums.end(),
        [](const Sanatorium& s1, const Sanatorium& s2) 
        {
            return s1.profile < s2.profile;
        });

    // Вывод информации в виде таблицы, сгруппированной по лечебным профилям и отсортированной по названиям санаториев
    cout << "----------------------------------------------" << endl;
    cout << "Название санатория | Местоположение | Кол-во путевок" << endl;
    cout << "----------------------------------------------" << endl;

    string currentProfile = "";

    for (const Sanatorium& sanatorium : sanatoriums)
    {
        if (sanatorium.profile != currentProfile)
        {
            cout << "Лечебный профиль: " << sanatorium.profile << endl;
            currentProfile = sanatorium.profile;
        }

        cout << sanatorium.name << " | " << sanatorium.location << " | " << sanatorium.availability << endl;
    }

    // Поиск информации
    string searchProfile;

    cout << "Введите лечебный профиль для поиска: ";
    cin >> searchProfile;

    cout << "Результаты поиска для лечебного профиля '" << searchProfile << "':" << endl;

    for (const Sanatorium& sanatorium : sanatoriums)
    {
        if (sanatorium.profile == searchProfile)
        {
            cout << sanatorium.name << " | " << sanatorium.location << " | " << sanatorium.availability << endl;
        }
    }

    return 0;
}
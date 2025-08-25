#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>

using namespace std;

// Перечисление для формы правления
enum Governance 
{
    MONARCHY = 1,
    REPUBLIC,
    DICTATORSHIP,
    THEOCRACY,
    DEMOCRACY
};

// Структура для хранения информации о государстве
struct Country 
{
    string name;
    string capital;
    long population;
    double area;
    Governance governance;
};

// Функция для ввода данных о новом государстве
Country inputCountryData() 
{
    Country country;

    cout << "Введите название государства: ";
    getline(cin, country.name);

    cout << "Введите название столицы: ";
    getline(cin, country.capital);

    cout << "Введите численность населения: ";
    cin >> country.population;

    cout << "Введите площадь: ";
    cin >> country.area;

    int governanceChoice;

    cout << "Выберите форму правления (1 - Монархия, 2 - Республика, 3 - Диктатура, 4 - Теократия, 5 - Демократия): ";
    cin >> governanceChoice;

    country.governance = static_cast<Governance>(governanceChoice);

    cin.ignore(); // Сброс символа новой строки

    return country;
}

// Функция для вывода информации о государстве
void displayCountryData(const Country& country) 
{
    string governanceString;

    switch (country.governance) 
    {
    case MONARCHY:
        governanceString = "Монархия";
        break;
    case REPUBLIC:
        governanceString = "Республика";
        break;
    case DICTATORSHIP:
        governanceString = "Диктатура";
        break;
    case THEOCRACY:
        governanceString = "Теократия";
        break;
    case DEMOCRACY:
        governanceString = "Демократия";
        break;
    default:
        governanceString = "Неизвестно";
    }

    cout << "Название государства: " << country.name << endl;
    cout << "Столица: " << country.capital << endl;
    cout << "Численность населения: " << country.population << endl;
    cout << "Площадь: " << country.area << endl;
    cout << "Форма правления: " << governanceString << endl;
}

int main() 
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    vector<Country> countries;
    int choice;

    do 
    {
        cout << "Меню:" << endl;
        cout << "1. Добавить государство" << endl;
        cout << "2. Вывести все государства" << endl;
        cout << "3. Удалить государство" << endl;
        cout << "4. Поиск государства по столице" << endl;
        cout << "5. Выход" << endl;
        cout << "Выберите действие: ";
        cin >> choice;

        cin.ignore(); // Сбрасываем символ новой строки

        switch (choice) 
        {
        case 1:
            countries.push_back(inputCountryData());
            break;
        case 2:
            cout << "Все государства:" << endl;
            for (const auto& country : countries) 
            {
                displayCountryData(country);
                cout << endl;
            }
            break;
        case 3:
            if (!countries.empty()) 
            {
                int index;

                cout << "Выберите государство для удаления (от 1 до " << countries.size() << "): ";              
                cin >> index;

                if (index >= 1 && index <= countries.size()) 
                {
                    countries.erase(countries.begin() + index - 1);
                    cout << "Государство удалено." << endl;
                }
                else 
                {
                    cout << "Некорректный индекс." << endl;
                }
            }
            else 
            {
                cout << "Список государств пуст." << endl;
            }
            break;
        case 4:
            if (!countries.empty()) 
            {
                string capital;

                cout << "Введите название столицы для поиска: ";
                getline(cin, capital);

                bool found = false;

                for (const auto& country : countries) 
                {
                    if (country.capital == capital) 
                    {
                        displayCountryData(country);
                        found = true;
                    }
                }
                if (!found) 
                {
                    cout << "Государство с такой столицей не найдено." << endl;
                }
            }
            else 
            {
                cout << "Список государств пуст." << endl;
            }
            break;
        case 5:
            cout << "Выход из программы." << endl;
            break;
        default:
            cout << "Некорректный выбор. Попробуйте снова." << endl;
        }
    } while (choice != 5);

    return 0;
}
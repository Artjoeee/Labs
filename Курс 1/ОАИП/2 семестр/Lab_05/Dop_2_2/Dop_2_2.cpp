#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <Windows.h>

using namespace std;

// Структура для хранения информации о горожанине
struct Citizen 
{
    string fullName;
    string dateOfBirth;
    string address;
    char gender; // 'м' - мужской, 'ж' - женский
};

// Функция для ввода данных о новом горожанине
Citizen inputCitizenData() 
{
    Citizen citizen;

    cout << "Введите Ф.И.О. горожанина: ";
    getline(cin, citizen.fullName);

    cout << "Введите дату рождения (ДД.ММ.ГГГГ): ";
    getline(cin, citizen.dateOfBirth);

    cout << "Введите адрес горожанина: ";
    getline(cin, citizen.address);

    cout << "Введите пол горожанина (м - мужской, ж - женский): ";
    cin >> citizen.gender;

    return citizen;
}

// Функция для вывода информации о горожанине
void displayCitizenData(const Citizen& citizen) 
{
    cout << "Ф.И.О.: " << citizen.fullName << endl;
    cout << "Дата рождения: " << citizen.dateOfBirth << endl;
    cout << "Адрес: " << citizen.address << endl;
    cout << "Пол: " << (citizen.gender == 'м' ? "мужской" : "женский") << endl;
}

// Функция для записи данных горожан в файл
void writeCitizensToFile(const vector<Citizen>& citizens, const string& filename) 
{
    ofstream file(filename);

    if (file.is_open()) 
    {
        for (const auto& citizen : citizens) 
        {
            file << citizen.fullName << ',' << citizen.dateOfBirth << ',' << citizen.address << ',' << citizen.gender << endl;
        }

        file.close();

        cout << "Данные успешно записаны в файл." << endl;
    }
    else 
    {
        cout << "Не удалось открыть файл для записи." << endl;
    }
}

// Функция для чтения данных горожан из файла
vector<Citizen> readCitizensFromFile(const string& filename) 
{
    vector<Citizen> citizens;
    ifstream file(filename);

    if (file.is_open()) 
    {
        string line;

        while (getline(file, line)) 
        {
            Citizen citizen;
            size_t pos = 0;

            pos = line.find(',');
            citizen.fullName = line.substr(0, pos);
            line.erase(0, pos + 1);

            pos = line.find(',');
            citizen.dateOfBirth = line.substr(0, pos);
            line.erase(0, pos + 1);

            pos = line.find(',');
            citizen.address = line.substr(0, pos);
            line.erase(0, pos + 1);

            citizen.gender = line[0];

            citizens.push_back(citizen);
        }

        file.close();
    }
    else 
    {
        cout << "Не удалось открыть файл для чтения." << endl;
    }

    return citizens;
}

int main() 
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    vector<Citizen> citizens;
    int choice;
    string yearOfBirth;

    do 
    {
        cout << "Меню:" << endl;
        cout << "1. Добавить горожанина" << endl;
        cout << "2. Вывести всех горожан" << endl;
        cout << "3. Записать горожан в файл" << endl;
        cout << "4. Прочитать горожан из файла" << endl;
        cout << "5. Поиск горожан по году рождения" << endl;
        cout << "6. Выход" << endl;
        cout << "Выберите действие: ";
        cin >> choice;
        cin.ignore(); // Сбрасываем символ новой строки

        switch (choice) 
        {
        case 1:
            citizens.push_back(inputCitizenData());
            break;
        case 2:
            cout << "Все горожане:" << endl;
            for (const auto& citizen : citizens) 
            {
                displayCitizenData(citizen);
                cout << endl;
            }
            break;
        case 3:
            writeCitizensToFile(citizens, "citizens.txt");
            break;
        case 4:
            citizens = readCitizensFromFile("citizens.txt");
            break;
        case 5:
            
            cout << "Введите год рождения для поиска: ";
            cin >> yearOfBirth;

            for (const auto& citizen : citizens) 
            {
                if (citizen.dateOfBirth.find(yearOfBirth) != string::npos) 
                {
                    displayCitizenData(citizen);
                    cout << endl;
                }
            }
            break;
        case 6:
            cout << "Выход из программы." << endl;
            break;
        default:
            cout << "Некорректный выбор. Попробуйте снова." << endl;
        }
    } while (choice != 6);

    return 0;
}
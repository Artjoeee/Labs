#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <Windows.h>

using namespace std;

// Структура для хранения результатов экзаменов студента
struct ExamResult 
{
    string fullName;  // ФИО студента
    int numExams;  // Число экзаменов
    vector<int> grades;  // Полученные оценки
};

// Функция для ввода результатов экзаменов студента
void inputStudentExams(ExamResult& student) 
{
    cout << "Введите ФИО студента: ";
    cin.ignore();  // Очистить буфер ввода

    getline(cin, student.fullName);  // Получаем ФИО студента

    cout << "Введите количество экзаменов: ";
    cin >> student.numExams;

    cout << "Введите оценки за каждый экзамен:" << endl;

    for (int i = 0; i < student.numExams; ++i) 
    {
        int grade;

        // Получаем оценку и добавляем в вектор оценок
        cout << "Экзамен " << i + 1 << ": ";
        cin >> grade;

        student.grades.push_back(grade);
    }
}

// Функция для вывода результатов экзаменов студента
void displayStudent(const ExamResult& student) 
{
    cout << "Студент: " << student.fullName << endl;
    cout << "Количество экзаменов: " << student.numExams << endl;
    cout << "Оценки: ";

    for (int grade : student.grades) 
    {
        cout << grade << " ";
    }

    cout << endl;
}

// Функция для вычисления процента студентов, сдавших экзамены на 4 и 5
float calculatePerformance(const vector<ExamResult>& students) 
{
    int passedCount = 0;

    for (const ExamResult& student : students) 
    {
        bool allPassed = true;

        for (int grade : student.grades) 
        {
            if (grade < 4) 
            {
                allPassed = false;  // Если есть оценка ниже 4, студент не сдал

                break;
            }
        }

        if (allPassed) 
        {
            passedCount++;
        }
    }

    // Возвращаем процент сдавших
    return static_cast<float>(passedCount) / students.size() * 100;
}

int main() 
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int numStudents;

    cout << "Введите количество студентов: ";
    cin >> numStudents;

    cin.ignore(); // Игнорируем символ новой строки из потока ввода

    vector<ExamResult> students(numStudents);  // Создаем вектор студентов

    for (int i = 0; i < numStudents; ++i) 
    {
        cout << "Введите данные студента " << i + 1 << ":" << endl;

        inputStudentExams(students[i]);
    }

    cout << endl << "Информация об экзаменах студентов: " << endl;

    for (const ExamResult& student : students) 
    {
        displayStudent(student);
    }

    float performance = calculatePerformance(students);

    cout << "Процент студентов, сдавших экзамены на 4 и 5: " << performance << "%" << endl;

    return 0;
}
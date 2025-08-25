#include <iostream>
#include "head.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");

    int choice;
    int x;

    Stack* myStk = nullptr;

    // Главный цикл программы
    for (;;)
    {
        cout << "Выберите команду:" << endl;
        cout << "1 - Добавление элемента в стек" << endl;
        cout << "2 - Извлечение элемента из стека" << endl;
        cout << "3 - Запись в файл" << endl;
        cout << "4 - Чтение из файла" << endl;
        cout << "5 - Вывод стека" << endl;
        cout << "6 - Удалить первый отрицательный элемент" << endl;
        cout << "7 - Выход" << endl;

        cin >> choice;

        // Обработка выбора пользователя
        switch (choice)
        {
        case 1:
            cout << "Введите элемент: " << endl;
            cin >> x;

            push(x, myStk);  // добавление элемента в стек
            break;

        case 2:
            x = pop(myStk);  // извлечение элемента из стека
            if (x != -1)
                cout << "Извлеченный элемент: " << x << endl;
            break;

        case 3:
            toFile(myStk);  // запись стека в файл
            break;

        case 4:
            fromFile(myStk);  // чтение стека из файла
            break;

        case 5:
            cout << "Весь стек: " << endl;
            show(myStk);  // вывод стека
            break;

        case 6:
            removeFirstNegative(myStk);  // удалить первый отрицательный элемент
            break;

        case 7:
            return 0;

        default:
            cout << "Неверная команда. Попробуйте снова\n";
        }
    }

    return 0;
}
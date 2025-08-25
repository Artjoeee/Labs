#include <iostream>
#include "myStack.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");

	int choice;
    char x;

	Stack* myStk = new Stack;  // Выделение памяти для стека

	myStk = NULL;  // Инициализация первого элемента	

    for (;;)
    {
        cout << "Выберите команду:" << endl;
        cout << "1 - Добавление элемента в стек" << endl;
        cout << "2 - Извлечение элемента из стека" << endl;
        cout << "3 - Запись в файл" << endl;
        cout << "4 - Чтение из файла" << endl;
        cout << "5 - Вывод стека" << endl;
        cout << "6 - Очистка стека" << endl;
        cout << "7 - Проверка наличия элемента равного следующему" << endl;
        cout << "0 - Выход" << endl;

        cout << "\nВаш выбор: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "\nВведите элемент: ";
            cin >> x;

            cout << endl;

            push(x, myStk);

            break;
        case 2:
            cout << "\nИзвлеченный элемент: " << pop(myStk) << endl << endl;

            break;
        case 3:
            toFile(myStk);

            break;
        case 4:
            fromFile(myStk);

            break;
        case 5:
            show(myStk);

            break;
        case 6:
            clear(myStk);

            break;
        case 7:
            if (hasEqualNextElement(myStk)) // true
            {
                cout << "\nВ стеке есть элемент, равный следующему за ним.\n" << endl;
            }
            else if (!hasEqualNextElement(myStk)) // false
            {
                cout << "\nВ стеке нет элементов, равных следующему за ним.\n" << endl;
            }

            break;
        case 0:
            return 0;
        }
    }

	return 0;
}
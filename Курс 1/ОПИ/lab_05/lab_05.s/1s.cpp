#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{   
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    char s;
    int n;
    
    cout << "Выберите вариант использования (1-4): ";

    cin >> n;
  
    switch (n)
    {
        case 1: puts("Введите символ"); // определение разницы значений кодов в ASCII буквы в прописном и строчном написании, если введен символ латинского алфавита

            cin >> s;

            if (s >= 'a' && s <= 'z')
            {
                int l, u, d;

                l = int(s);
                u = int(s - 32);
                d = u - l;

                cout << "Разница значений кодов в ASCII: " << d << endl;
            }

            else if (s >= 'A' && s <= 'Z')
            {
                int l, u, d;

                l = int(s + 32);
                u = int(s);
                d = u - l;

                cout << "Разница значений кодов в ASCII: " << d << endl;
            }

            else
            {
                cout << "Введен символ, не являющийся латинской буквой" << endl;
            }

            break;

        case 2: puts("Введите символ"); // определение разницы значений кодов в Windows-1251 буквы в прописном и строчном написании, если введен символ русского алфавита

            cin >> s;

            if (s >= 'а' && s <= 'я')
            {
                int l, u, d;

                l = int(s);
                u = int(s - 32);
                d = u - l;

                cout << "Разница значений кодов в Windows-1251: " << d << endl;
            }

            else if (s >= 'А' && s <= 'Я')
            {
                int l, u, d;

                l = int(s + 32);
                u = int(s);
                d = u - l;

                cout << "Разница значений кодов в Windows-1251: " << d << endl;
            }

            else
            {
                cout << "Введен символ, не являющийся русской буквой" << endl;
            }

            break;

        case 3: puts("Введите символ"); // вывод в консоль кода символа, соответствующего введенной цифре

            cin >> s;

            if (s >= '0' && s <= '9')
            {
                int k;

                k = int(s);

                cout << "Код символа: " << k << endl;
            }

            else
            {
                cout << "Введен символ, не являющийся цифрой" << endl;
            }

            break;

        case 4: puts("Конец программы"); // выход из программы

            break;

        default: puts("Неверно выбран вариант использования");

            break;
    }
    
    return 0;
}
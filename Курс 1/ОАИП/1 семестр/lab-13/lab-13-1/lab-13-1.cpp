#include <iostream>

using namespace std;

void removeLetterB(char *str) 
{
    int i = 0;
    int j = 0;

    while (str[i] != '\0') 
    {
        if (str[i] != 'b' && str[i] != 'B') 
        {
            str[j] = str[i];
            ++j;
        }

        ++i;
    }

    str[j] = '\0';
}

int main() 
{
    setlocale(LC_ALL, "RU");

    char text[] = "Hello, World! bbbbbbbbbbbbbbbbbBBBBBBBBBBB";

    cout << "Исходный текст: " << text << endl;

    removeLetterB(text);

    cout << "Текст без букв 'b': " << text << endl;

    return 0;
}
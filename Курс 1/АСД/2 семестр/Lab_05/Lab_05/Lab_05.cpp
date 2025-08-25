#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool checkBrackets(const string& str);

bool checkBrackets(const string& str) 
{
    stack<char> s;

    for (char c : str) 
    {
        if (c == '(' || c == '[' || c == '{') 
        {
            s.push(c);
        }
        else if (c == ')' || c == ']' || c == '}') 
        {
            if (s.empty()) 
            {
                return false;
            }

            char top = s.top();

            if ((c == ')' && top != '(') || (c == ']' && top != '[') || (c == '}' && top != '{'))                
            {
                return false;
            }

            s.pop();
        }
    }

    return s.empty();
}

int main() 
{
    setlocale(0, "ru");

    string inputString;

    cout << "Введите символьную строку с различными скобками: ";
    getline(cin, inputString);

    if (checkBrackets(inputString)) 
    {
        cout << "Скобки расставлены верно" << endl;
    }
    else 
    {
        cout << "Скобки расставлены не верно" << endl;
    }

    return 0;
}
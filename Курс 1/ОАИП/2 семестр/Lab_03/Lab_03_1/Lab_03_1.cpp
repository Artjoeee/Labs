#include <iostream>
#include <fstream>
#include <cctype>
#include <string>

using namespace std;

int main() 
{
    setlocale(0, "ru");

    // �������� ������
    ifstream file1("FILE1.txt");
    ofstream file2("FILE2.txt");

    if (!file1.is_open() || !file2.is_open())  // ���������, ������� �� ������� �����
    {
        cerr << "�� ������� ������� �����." << endl;

        exit(1);  // ��������� ��������� � ����� ������ 1
    }

    
    string line;  // ������� ��� ����������� ����� ��� ���� �� ������ ����� � ������

    int count = 0;

    while (getline(file1, line))  // �������� �� ���������� ����
    {
        bool hasDigit = false;

        for (char c : line) // �������� ������� ������� � ������
        {
            if (isdigit(c)) 
            {
                hasDigit = true;

                break;
            }
        }
        
        if (!hasDigit) // ���� ������ �� �������� ����, �������� �� � ���� FILE2
        {
            file2 << line << endl;

            if (!line.empty() && toupper(line[0]) == 'A') // ������� �����, ������������ �� ����� 'A'
            {
                count++;
            }
        }
    }

    //�������� ������
    file1.close();
    file2.close();

    cout << "���������� �����, ������������ �� ����� 'A' � ����� FILE2: " << count << endl;

    return 0;
}
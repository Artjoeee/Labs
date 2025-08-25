#include "stdafx.h"

using namespace std;

namespace In
{
    int item = 0;

    void removeExtraSpaces(string& input)// ������� ������ ������� �� ������� ������.
    {
        bool insideQuotes = false; // ���������� ��� ������������, ��������� �� �� ������ �������.

        for (size_t i = 0; i < input.length(); ++i) // �������� �� ���� �������� ������.
        {
            if (input[i] == '\'')
            {
                insideQuotes = !insideQuotes; // ���� ��������� ��������� �������, ����������� ����.
            }

            if (!insideQuotes && input[i] == ' ') // ���� ��� ������ � �� �� ������ �������.
            {
                if (i == 0 || i == input.length() - 1) // ���������, �� ������ �� ��� ��� ��������� ������ ������.
                {
                    input.erase(i, 1); // ������� ������, ���� �� � ������ ��� � ����� ������.
                    item++;
                    i--;
                    continue;
                }

                size_t spacesToRemove = 0; // ������� ���������������� ��������.

                while (i + spacesToRemove < input.length() && input[i + spacesToRemove] == ' ')
                {
                    ++spacesToRemove; // ������� ���������� ���������������� �������� ����� �������� �������.
                }

                if (spacesToRemove > 1) // ���� ������ ������ �������.
                {
                    if (input[i] == ' ')
                    {
                        item++;

                        if (i != input.length() - 1)
                        {
                            item--;
                        }
                    }

                    input.erase(i + 1, spacesToRemove - 1); // ������� ��� ������ �������, ����� ������.
                    item += spacesToRemove - 1;
                }
            }
        }
    }

    void removeSpacesAroundOperators(string& input)// ������� ������� ������ ���������� �� ������� ������.
    {
        const string operators = ";,}{()=+-/*"; // ������, ���������� ��� ���������, ������ ������� ����� ������ �������.

        for (size_t i = 0; i < input.length(); ++i) // �������� �� �������� ������.
        {
            if (operators.find(input[i]) != string::npos) // ���� ������� ������ �������� ����������.
            {
                // ������� ������� ����� ��������
                while (i > 0 && isspace(input[i - 1]))
                {
                    input.erase(i - 1, 1); // ������� ������ ����� ����������.
                    item++;
                    --i; // ������� ������ �����, ����� ���������� ��������.
                }

                // ������� ������� ����� �������
                while (i + 1 < input.length() && isspace(input[i + 1]))
                {
                    input.erase(i + 1, 1); // ������� ������ ����� ���������.
                    item++;
                }
            }
        }
    }

    IN getin(wchar_t infile[]) // ������� ��� ������ ������ �� ����� � �� ���������.
    {
        ifstream fin; // ������� ����� ��� ������ �����.

        char* outFile = new char[wcslen(infile) + 1]; // ������� ����� ��� ����� ����� � ������� char.

        wcstombs_s(NULL, outFile, wcslen(infile) + 1, infile, wcslen(infile) + 1); // ����������� ��� ����� �� wchar_t � char.

        fin.open(infile); // ��������� ���� ��� ������.

        if (fin.bad()) // ���������, �� ��������� �� ������ ��� �������� �����.
        {
            throw ERROR_THROW(116); // ���� ������, ����������� ����������.
        }

        if (!fin.is_open()) // ���� ���� �� ��������.
        {
            throw ERROR_THROW(110); // ����������� ����������.
        }

        IN resultIn; // ������� ��������� ��� �������� ������ �� �����.

        resultIn.ignorSpace = 0;
        resultIn.size = 0; // �������������� ��������� ������ ������.
        resultIn.lines = 0; // �������������� ���������� �����.

        int position = 0; // ���������� ��� ������������ ������� � ������.
        int ch; // ���������� ��� �������� �������� �������.

        string currentLine; // ������ ��� ���������� ��������.
        string buffer; // ����� ��� ���������� ����� �� �����.

        while (getline(fin, buffer)) // ��������� ������ �� �����.
        {
            resultIn.lines++; // ����������� ���������� �����.

            for (int i = 0; i < buffer.length(); i++) // �������� �� �������� ��������� ������.
            {
                ch = buffer[i]; // �������� ������� ������.

                if (ch == fin.eof()) // ���� �������� ����� �����.
                {
                    break; // ������� �� �����.
                }

                switch (resultIn.code[(unsigned char)ch]) // ������ ������� � ������� ������� resultIn.code.
                {
                    case IN::F: // ���� ������ �������� ������, ������ ��� ������ �������������, �� ��� �������������.
                    {
                        resultIn.text.push_back(currentLine); // ��������� ������� ������ � ���������.

                        throw ERROR_THROW_IN(111, resultIn.lines, ++position, buffer, resultIn.text); // ����������� ���������� ��� ������.
                        break;
                    }
                    case IN::I: // ���� ������ ������������.
                    {
                        resultIn.ignor++; // ����������� ������� ������������ ��������.
                        position++; // ����������� ������� ������� � ������� ������.
                        break;
                    }
                    case IN::T: // ���� ������ �������� ��������� ��������.
                    {
                        currentLine += ch; // ��������� ������ � ������� ������.

                        position++; // ����������� ������� ������� � ������.
                        resultIn.size++; // ����������� ������ ������.

                        resultIn.ignorSpace = item;

                        break;
                    }
                    default: // ���� ������ �� �������� �� � ���� �� ���������.
                    {
                        currentLine += resultIn.code[(unsigned char)ch]; // ��������� ����������� ������.

                        resultIn.size++; // ����������� ������ ������.
                        position++; // ����������� ������� �������.
                        break;
                    }
                }
            }

            if (!currentLine.empty()) // ���� ������� ������ �� ������.
            {
                resultIn.size++; // ����������� ������ ������.
                position++; // ����������� ������� �������.
                position = 0; // ���������� ������� ����� ��������� ������.

                currentLine += resultIn.code[IN_CODE_ENDL]; // ��������� ������ ����� ������.

                removeExtraSpaces(currentLine); // ������� ������ ������� � ������.
                removeSpacesAroundOperators(currentLine); // ������� ������� ������ ����������.

                resultIn.text.push_back(currentLine); // ��������� ������� ������ � ���������.

                currentLine.clear(); // ������� ������ ��� ��������� ��������.
            }
        }

        fin.close();

        return resultIn;
    }
}

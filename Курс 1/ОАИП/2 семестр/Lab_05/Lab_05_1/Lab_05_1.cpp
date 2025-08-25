#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>

using namespace std;

// ������������ ��� ���� �����
enum AccountType
{
    SAVINGS,
    CURRENT,
    FIXED_DEPOSIT,
    OTHER
};

// ��������� ��� �������� ���������� � �������
struct BankClient
{
    string fullName;
    AccountType accountType;
    long accountNumber;
    double balance;

    // ������� ���� ��� �������� ���� ���������� ��������� 
    struct Date
    {
        unsigned int day : 5;
        unsigned int month : 4;
        unsigned int year : 16;
    } 
    lastModified;
};

// ������� ��� ������ ���������� � �������
void displayClient(const BankClient& client)
{
    cout << "���: " << client.fullName << endl;
    cout << "��� �����: ";

    // �������� ���� �����
    switch (client.accountType)
    {
    case SAVINGS:
        cout << "��������������" << endl;
        break;
    case CURRENT:
        cout << "�������" << endl;
        break;
    case FIXED_DEPOSIT:
        cout << "����������" << endl;
        break;
    case OTHER:
        cout << "������" << endl;
        break;
    }

    cout << "����� �����: " << client.accountNumber << endl;
    cout << "����� �� �����: " << client.balance << endl;
    cout << "���� ���������� ���������: " << client.lastModified.day << "." << client.lastModified.month << "." << client.lastModified.year << endl;
    cout << endl;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    vector<BankClient> clients; // ������ ��� �������� ��������

    int choice;

    do
    {
        cout << "����:" << endl;
        cout << "1. �������� �������" << endl;
        cout << "2. ������� ���� ��������" << endl;
        cout << "3. ����� �������� �� ����� �� �����" << endl;
        cout << "4. ������� �������" << endl;
        cout << "0. �����" << endl;
        cout << "�������� ��������: ";
        cin >> choice;
        cout << endl;

        switch (choice)
        {
        case 1: // ���������� ������ �������
        {
            BankClient newClient;

            cout << "������� ��� �������: ";
            cin.ignore(); // ������� ����� �����
            getline(cin, newClient.fullName);

            int accountTypeChoice;

            cout << "�������� ��� ����� (0 - ��������������, 1 - �������, 2 - ����������, 3 - ������): ";          
            cin >> accountTypeChoice;

            newClient.accountType = static_cast<AccountType>(accountTypeChoice);

            cout << "������� ����� �����: ";
            cin >> newClient.accountNumber;

            cout << "������� ����� �� �����: ";
            cin >> newClient.balance;

            int day, month, year;

            cout << "������� ���� ���������� ��������� (���� ����� ���): "; 
            cin >> day >> month >> year;

            // ���������� ������ � ���� ���������� ���������
            newClient.lastModified.day = day;
            newClient.lastModified.month = month;
            newClient.lastModified.year = year;

            clients.push_back(newClient); // ��������� ������� � ������

            cout << "������ ������� ��������!" << endl << endl;
            break;
        }
        case 2: // ����� ���� ��������
        {
            if (clients.empty())
            {
                cout << "��� ����������� ��������." << endl;
            }
            else
            {
                cout << "������ ��������:" << endl;
                for (const auto& client : clients)
                {
                    displayClient(client); // ������� ���������� � ������ �������
                }
            }
            break;
        }
        case 3: // ����� �������� �� ����� �� �����
        {
            double amount;

            cout << "������� ����� ��� ������ (<100, >100): ";
            cin >> amount;

            if (amount < 100)
            {
                cout << "������� � ������ �� ����� ������ 100:" << endl;
                for (const auto& client : clients)
                {
                    if (client.balance < 100)
                    {
                        displayClient(client); // ������� ���������� � �������
                    }
                }
            }
            else
            {
                cout << "������� � ������ �� ����� ������ ��� ������ 100:" << endl;
                for (const auto& client : clients)
                {
                    if (client.balance >= 100)
                    {
                        displayClient(client); // ������� ���������� � �������
                    }
                }
            }
            break;
        }
        case 4: // �������� �������
        {
            int index;

            cout << "������� ������ ������� ��� ��������: ";
            cin >> index;

            if (index >= 0 && index < clients.size())
            {
                clients.erase(clients.begin() + index); // �������� ������� �� �������
                cout << "������ ������� ������!" << endl;
            }
            else
            {
                cout << "������: �������� ������ �������." << endl;
            }
            break;
        }
        case 0: // ����� �� ���������
        {
            cout << "����� �� ���������." << endl;
            break;
        }

        default:
            cout << "�������� �����. ���������� ��� ���." << endl;
        }
    } while (choice != 0);

    return 0;
}
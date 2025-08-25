#include <iostream>
#include <fstream>
#include <Windows.h>

using namespace std;

// ��������� ������������ ������
struct Node
{
    char data;
    Node* next;
};

// ��������� �������
void insert(Node*& head, char value);
void remove(Node*& head, char value);
void searchAndPrintNext(Node* head, char value);
void printList(Node* head);
void toFile(Node* head);
void fromFile(Node*& head);
void menu();

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Node* head = nullptr;  // ��������� ����������
    int choice;
    char value;

    menu();  // ����� ���� ������ ��������

    cout << "��� �����: ";
    cin >> choice;

    // ���� ��������� ������ ��������
    while (choice != 0)
    {
        switch (choice)
        {
        case 1:
            cout << "������� ������: ";
            cin >> value;

            insert(head, value);  // ����� ������� ��� ������� ��������
            printList(head);  // ����� ������ ����� �������
            break;
        case 2:
            cout << "������� ������ ��� ��������: ";
            cin >> value;

            remove(head, value);  // ����� ������� ��� �������� ��������
            printList(head);  // ����� ������ ����� ��������
            break;
        case 3:
            cout << "������� ������ ��� ������ � ������ ����������: ";
            cin >> value;

            searchAndPrintNext(head, value);  // ����� ������� ��� ������ � ������ ���������� ��������
            break;
        case 4:
            printList(head);  // ����� �������� ������
            break;
        case 5:
            toFile(head);  // ������ ������ � ����
            break;
        case 6:
            fromFile(head);  // ������ ������ �� �����
            break;
        default:
            cout << "������������ �����" << endl;

            menu();  // ����� ���� ������ ��������
            break;
        }

        cout << "��� �����: ";
        cin >> choice;
    }

    return 0;
}

// ������� ��� ������� �������� � ������ ������
void insert(Node*& head, char value)
{
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

// ������� ��� �������� �������� �� ������
void remove(Node*& head, char value)
{
    Node* current = head;
    Node* previous = nullptr;  // ��������� ����������

    while (current != nullptr)
    {
        if (current->data == value)
        {
            if (previous == nullptr)
            {
                head = current->next;
            }
            else
            {
                previous->next = current->next;
            }

            delete current;
            return;
        }

        previous = current;
        current = current->next;
    }

    cout << "������ �� ������ ��� ��������" << endl;
}

// ������� ��� ������ � ������ ���������� �������� ������
void searchAndPrintNext(Node* head, char value)
{
    Node* current = head;

    while (current != nullptr)
    {
        if (current->data == value && current->next != nullptr)
        {
            cout << "��������� ������: " << current->data << ", ��������� ������: " << current->next->data << endl;
            return;
        }

        current = current->next;
    }

    cout << "������ �� ������ ��� ����������� ��������� ������" << endl;
}

// ������� ��� ������ ��������� ������
void printList(Node* head)
{
    if (head == nullptr)
    {
        cout << "������ ����" << endl;
    }
    else
    {
        cout << "������:" << endl;
        Node* current = head;

        while (current != nullptr)
        {
            cout << "-->" << current->data;
            current = current->next;
        }

        cout << "-->NULL" << endl;
    }
}

// ������� ��� ������ ������ � ����
void toFile(Node* head)
{
    ofstream file("symbol.txt");

    if (file.is_open())
    {
        Node* current = head;

        while (current != nullptr)
        {
            file << current->data << " ";
            current = current->next;
        }

        file.close();

        cout << "������ ������� � ���� symbol.txt" << endl;
    }
    else
    {
        cout << "������ �������� �����" << endl;
    }
}

// ������� ��� ������ ������ �� �����
void fromFile(Node*& head)
{
    ifstream file("symbol.txt");

    if (file.is_open())
    {
        char value;

        while (file >> value)
        {
            insert(head, value);
        }

        file.close();

        cout << "������ ������ �� ����� symbol.txt" << endl;
    }
    else
    {
        cout << "������ �������� �����" << endl;
    }
}

// ������� ��� ������ ���� ������ ��������
void menu()
{
    cout << "�������� �����:" << endl;
    cout << "1 - �������� �������" << endl;
    cout << "2 - ������� �������" << endl;
    cout << "3 - ����� � ����� ���������� ��������" << endl;
    cout << "4 - ������� ������" << endl;
    cout << "5 - �������� ������ � ����" << endl;
    cout << "6 - ������� ������ �� �����" << endl;
    cout << "0 - ����� �� ���������" << endl;
}
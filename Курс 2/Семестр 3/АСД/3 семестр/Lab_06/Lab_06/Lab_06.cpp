#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <queue>
#include <Windows.h>

using namespace std;

// Структура для представления узла дерева Хаффмана
struct Node
{
    char ch;
    int freq;
    Node* left;
    Node* right;

    // Конструктор для создания нового узла
    Node(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
};


// Компаратор для очереди с приоритетом
struct Compare
{
    // operator() перегружен для сравнения двух узлов
    bool operator()(Node* l, Node* r)
    {
        return l->freq > r->freq; // Узел с большей частотой идет дальше в очереди
    }
};


// Рекурсивная функция для построения кодов Хаффмана
void buildHuffmanCodes(Node* root, const string& str, unordered_map<char, string>& huffmanCode)
{
    if (!root)
        return;

    // Если нет дочерних узлов, то это символ
    if (!root->left && !root->right)
    {
        huffmanCode[root->ch] = str;
    }

    buildHuffmanCodes(root->left, str + "0", huffmanCode);
    buildHuffmanCodes(root->right, str + "1", huffmanCode);
}


// Функция для декодирования закодированной строки
string huffmanDecoding(Node* root, const string& encodedString)
{
    string decodedString;
    Node* currentNode = root;

    for (char bit : encodedString)
    {
        if (bit == '0')
            currentNode = currentNode->left;
        else
            currentNode = currentNode->right;

        // Если достигнут листовой узел, добавляем его символ в результат
        if (!currentNode->left && !currentNode->right)
        {
            decodedString += currentNode->ch;
            currentNode = root; // Возвращаемся к корню для декодирования следующего символа
        }
    }

    return decodedString;
}

// Функция для построения дерева Хаффмана и кодирования текста
void huffmanEncoding(const string& text)
{
    unordered_map<char, int> freq;

    for (char ch : text)
    {
        freq[ch]++;
    }

    cout << "Частота символов:\n";

    for (const auto& pair : freq)
    {
        cout << pair.first << ": " << pair.second << "\n";
    }

    cout << "\n";

    priority_queue<Node*, vector<Node*>, Compare> pq;

    // Заполнение очереди узлами для каждого уникального символа
    for (const auto& pair : freq)
    {
        pq.push(new Node(pair.first, pair.second));
    }

    // Построение дерева Хаффмана
    while (pq.size() != 1)
    {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();

        int sum = left->freq + right->freq;

        Node* newNode = new Node('\0', sum); // Промежуточный узел, поэтому символ не задан

        // Устанавливаем извлеченные узлы как дочерние для нового узла
        newNode->left = left;
        newNode->right = right;

        pq.push(newNode);
    }

    // Корень дерева Хаффмана
    Node* root = pq.top();

    unordered_map<char, string> huffmanCode;

    buildHuffmanCodes(root, "", huffmanCode);

    cout << "Коды Хаффмана:\n";

    for (const auto& pair : huffmanCode)
    {
        cout << pair.first << ": " << pair.second << "\n";
    }

    cout << "\n";

    string encodedString;

    for (char ch : text)
    {
        encodedString += huffmanCode[ch];
    }

    cout << "Закодированная последовательность:\n" << encodedString << "\n";

    // Декодирование закодированной строки
    string decodedString = huffmanDecoding(root, encodedString);

    cout << "\nДекодированная строка:\n" << decodedString << "\n";
}


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string text;

    cout << "Введите текст для кодирования: ";
    getline(cin, text);

    huffmanEncoding(text);

    return 0;
}

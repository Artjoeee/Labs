#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <Windows.h>

using namespace std;

struct Item
{
    string name;
    int weight;
    int value;
};

void knapsack(int capacity, const vector<Item>& items)
{
    int n = items.size();

    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; ++i)
    {
        for (int w = 1; w <= capacity; ++w)
        {
            if (items[i - 1].weight <= w)
            {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - items[i - 1].weight] + items[i - 1].value);
            }
            else
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    int max_value = dp[n][capacity];

    vector<Item> selected_items;
    int w = capacity;

    for (int i = n; i > 0 && max_value > 0; --i)
    {
        if (dp[i][w] != dp[i - 1][w])
        {
            selected_items.push_back(items[i - 1]);
            w -= items[i - 1].weight;
            max_value -= items[i - 1].value;
        }
    }

    cout << "Максимальная стоимость: " << dp[n][capacity] << endl;

    cout << "Выбранные предметы:" << endl;
    for (const auto& item : selected_items)
    {
        cout << "- " << item.name << " (вес: " << item.weight << ", стоимость: " << item.value << ")" << endl;
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int capacity;

    cout << "Введите вместимость рюкзака: ";
    cin >> capacity;

    int num_items;

    cout << "Введите количество предметов: ";
    cin >> num_items;

    cout << endl;

    vector<Item> items;

    for (int i = 0; i < num_items; ++i)
    {
        Item item;

        cout << "Введите название предмета: ";
        cin >> item.name;

        cout << "Введите вес предмета: ";
        cin >> item.weight;

        cout << "Введите стоимость предмета: ";
        cin >> item.value;

        items.push_back(item);

        cout << endl;
    }

    knapsack(capacity, items);

    return 0;
}

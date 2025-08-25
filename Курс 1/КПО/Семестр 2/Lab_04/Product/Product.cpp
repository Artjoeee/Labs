#include <string>
#include <iostream>

using namespace std;

// Псевдонимы типов данных для полей структуры
typedef string Type;
typedef string Name;
typedef int InventoryNumber;
typedef double Quantity;
typedef double Price;
typedef string Manufacturer;
typedef string ExpirationDate;

// Определение структуры Product
struct Product
{
    Type type;  // Тип товара
    Name name;  // Название товара
    InventoryNumber inventory_number;  // Инвентарный номер
    Quantity quantity;  // Количество единиц товара
    Price price;  // Цена товара
    Manufacturer manufacturer;  // Производитель
    ExpirationDate expiration_date;  // Срок реализации
};

// Вычисление общей стоимости товара
double CalculateCost(const Product& item)
{
    return item.quantity * item.price;
}

// Сумма товаров по цене
double CalculateTotalCost(const Product& item1, const Product& item2)
{
    return (item1.price * item1.quantity) + (item2.price * item2.quantity);
}

// Перегрузка оператора <
bool operator<(const Product& item1, const Product& item2) 
{
    return item1.price < item2.price;
}

// Перегрузка оператора >
bool operator>(const Product& item1, const Product& item2)
{
    return item1.price > item2.price;
}

int main()
{
    setlocale(LC_ALL, "ru");

    Product item1 = { "Фрукт", "Яблоко", 12345, 1.5, 100, "Fruit Co.", "31.12.2024" };
    Product item2 = { "Фрукт", "Банан", 54321, 1.0, 200, "Tropical Farms", "30.11.2024" };

    double сost1 = CalculateCost(item1);
    double сost2 = CalculateCost(item2);

    cout << "Цена (" << item1.name << "): $" << сost1 << endl;
    cout << "Цена (" << item2.name << "): $" << сost2 << endl;

    double totalCost = CalculateTotalCost(item1, item2);

    cout << "Общая цена (" << item1.name << " и " << item2.name << "): $" << totalCost << endl;

    if (item1 > item2)
    {
        cout << item1.name << " дороже чем " << item2.name << endl;
    }
    else if (item1 < item2)
    {
        cout << item2.name << " дороже чем " << item1.name << endl;
    }
    else
    {
        cout << item1.name << " и " << item2.name << " стоят одинаково." << endl;
    }

    return 0;
}
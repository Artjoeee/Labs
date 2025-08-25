#include <iostream>
#include <chrono>

using namespace std;
using namespace chrono;

void hanoi(int n, int from, int to, int via);

int step = 0;

void hanoi(int n, int from, int to, int via) 
{
    if (n == 1) 
    {
        cout << "Перемещение диска 1 из " << from << " башни в " << to << endl;
        step++;
    }
    else 
    {
        hanoi(n - 1, from, via, to);
        cout << "Перемещение диска " << n << " из " << from << " башни в " << to << endl;
        hanoi(n - 1, via, to, from);
        step++;
    }
}

int main() 
{
    setlocale(LC_ALL, "rus");

    int n;
    int tower;
    int from;
    int to;
    int via;

    do
    {
        cout << "Введите количество дисков (не меньше 2): ";
        cin >> n;
        
    } while (n < 2);

    do 
    {
        cout << "Введите количество башен (не меньше 3): ";
        cin >> tower;
        
    } while (tower < 3);
    
    cout << "\n(Номера не должны быть меньше 1 и больше количества башен)\n\n";

    do
    {
        cout << "Номер начальной башни: ";
        cin >> from;
        
    } while (from < 1 || from > tower);
    
    do
    {
        cout << "Номер промежуточной башни: ";
        cin >> to;
        
    } while (to < 1 || to > tower || to == from);
    
    do
    {
        cout << "Номер конечной башни: ";
        cin >> via;
        
    } while (via < 1 || via > tower || via == from || via == to);

    cout << endl;
    
    auto begin = steady_clock::now();

    hanoi(n, from, via, to);

    auto end = steady_clock::now();

    auto elapsed_ms = duration_cast<milliseconds>(end - begin);

    cout << "\nВремя: " << elapsed_ms.count() << " мс\n";

    cout << "Количество ходов: " << step;
}
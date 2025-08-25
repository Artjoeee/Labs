#include <iostream>
#include <vector>

using namespace std;

void binarySearch(int n);

void binarySearch(int n) 
{
    int steps = 0;
    int low = 1, high = n;

    vector<int> searchSteps;

    while (low <= high) 
    {
        int mid = low + (high - low) / 2;

        searchSteps.push_back(mid);
        steps++;

        cout << mid << endl;

        cout << "Введите ответ (1 - мало, 2 - много, 3 - угадал): ";

        int userInput;

        cin >> userInput;

        if (userInput == 3) 
        {
            cout << "\nМаксимальное количество шагов = " << steps << endl;

            for (const auto& step : searchSteps) 
            {
                cout << step << endl;
            }

            return;
        }
        else if (userInput == 1) 
        {
            low = mid + 1;
        }
        else if (userInput == 2) 
        {
            high = mid - 1;
        }
    }
}

int main() 
{
    setlocale(0, "ru");

    int n;

    cout << "Введите число N: ";
    cin >> n;

    int x = n / 2;

    cout << "Число X: " << x << endl;

    binarySearch(n);

    return 0;
}
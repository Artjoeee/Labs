#include <iostream> 

using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");

    float a, b, c, r, s, t;

    cout << "¬ведите длину коробки: ";
    cin >> a;

    cout << "¬ведите ширину коробки: ";
    cin >> b;

    cout << "¬ведите высоту коробки: ";
    cin >> c;

    cout << "¬ведите длину посылки: ";
    cin >> r;

    cout << "¬ведите ширину посылки: ";
    cin >> s;

    cout << "¬ведите высоту посылки: ";
    cin >> t;

    if (a <= r && b <= s && c <= t)
    {
        cout << "¬аша коробка вместитс€ в посылку" << endl;
    }

    else
    {
        cout << "¬аша коробка не вместитс€ в посылку" << endl;
    }

    return 0;
}
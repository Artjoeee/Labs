#include <iostream>
#include "Varparm.h"

using namespace std;
using namespace Varparm;

int main() 
{
    // ivarparm
    cout << "ivarparm (1): " << ivarparm(1, 10) << endl;
    cout << "ivarparm (2): " << ivarparm(2, 2, 3) << endl;
    cout << "ivarparm (3): " << ivarparm(3, 4, 5, 6) << endl;
    cout << "ivarparm (4): " << ivarparm(7, 1, 2, 3, 4, 5, 6, 7) << endl;

    // svarparm
    cout << "svarparm (1): " << svarparm(1, 10) << endl;
    cout << "svarparm (2): " << svarparm(2, 2, 3) << endl;
    cout << "svarparm (3): " << svarparm(3, 4, 5, 6) << endl;
    cout << "svarparm (4): " << svarparm(7, 1, 2, 3, 4, 5, 6, 7) << endl;

    // fvarparm
    cout << "fvarparm (1): " << fvarparm(0.0f, 1.0f) << endl;
    cout << "fvarparm (2): " << fvarparm(0.0f, 2.0f, 3.0f) << endl;
    cout << "fvarparm (3): " << fvarparm(0.0f, 4.0f, 5.0f, 6.0f) << endl;
    cout << "fvarparm (4): " << fvarparm(0.0f, 1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 0.0f) << endl;

    // dvarparm
    cout << "dvarparm (1): " << dvarparm(0.0, 1.0) << endl;
    cout << "dvarparm (2): " << dvarparm(0.0, 2.0, 3.0) << endl;
    cout << "dvarparm (3): " << dvarparm(0.0, 4.0, 5.0, 6.0) << endl;
    cout << "dvarparm (4): " << dvarparm(0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 0.0) << endl;

    return 0;
}

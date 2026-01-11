#include <iostream>
using namespace std;

namespace A
{
    int i;
    void dispI()
    {
        cout << i;
    }
}

namespace Inside
{
    int insideI;
    void dispInsideI()
    {
        cout << insideI;
    }
}

int main()
{
    A::i = 10;
    cout << A::i;
    A::dispI();

    Inside::insideI = 20;
    cout << Inside::insideI;
    Inside::dispInsideI();
    return 0;
}
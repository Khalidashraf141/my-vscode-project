#include <iostream>
namespace N1
{
    int x;
    namespace N2
    {
        int y;
    }
}

using namespace N1;
using namespace N1::N2;
using namespace std;

int main()
{
    x = 10;
    y = 20;
    cout << x << ' ' << y << "\n";
    return 0;
}
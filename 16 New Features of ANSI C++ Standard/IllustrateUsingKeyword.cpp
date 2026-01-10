#include <iostream>
using namespace std;

// Defining a namespace
namespace Name1
{
    double x = 4.56;
    int m = 100;
    namespace Name2
    {
        double y = 1.23;
    }
}

namespace Name3
{
    int m = 200;
    int n = 300;
}

int main()
{
    using namespace Name1; //bring members of Name1 to current scope

    cout << "x = " << x << "\n";
    cout << "m = " << m << "\n";
    cout << "y = " << Name2::y << "\n";
    using Name3::n;
    cout << "m = " << Name3::m << "\n";
    cout << "n = " << n << "\n";
    return 0;
}
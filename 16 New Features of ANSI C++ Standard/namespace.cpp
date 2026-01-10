/*
Note: There is no difference between a class definition and a namespace definition. The namespace is concluded with a closing brace but no terminating semicolon.
*/
#include <iostream>
using namespace std;

//Defining a namespace
namespace Name1
{
    double x = 4.56;
    int m = 100;

    namespace Name2     // Nesting namespaces
    {
        double y = 1.23;
    }
}

namespace       // Unnamed namespace
{
    int m = 200;
}

int main()
{
    cout << "x = " << Name1::x << "\n";
    cout << "m = " << Name1::m << "\n";
    cout << "y = " << Name1::Name2::y << "\n";

    cout << "m = " << m << "\n"; // m is global
    return 0;
}
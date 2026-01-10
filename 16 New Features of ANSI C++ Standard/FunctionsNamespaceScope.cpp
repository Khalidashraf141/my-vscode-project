#include <iostream>
using namespace std;

namespace Functions
{
    int divide(int x, int y)
    {
        return(x/y);
    }
    int prod(int x, int y);
}

int Functions::prod(int x, int y)
{
    return(x*y);
}

int main()
{
    using namespace Functions;
    cout << "Division: " << divide(20,10) << "\n";
    cout << "Multiplication: " << prod(20,10) << "\n";
    return 0;
}
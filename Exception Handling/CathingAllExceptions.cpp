#include <iostream>
using namespace std;

void test(int x)
{
    try
    {
        if(x == 0) throw x;
        if(x == -1) throw 'x';
        if(x == 1) throw 1.0;
    }
    catch(...)
    {
        cout << "Caught an exception\n";
    }
}

int main()
{
    cout << "Testing Generic Catch\n";
    test(-1);
    test(0);
    test(1);
    return 0;
}

/*
Note that all the throws were caught by the catch(...) statement
it may be a good idea to use the catch(...) as a default statement along with other catch handlers so that it can catch all those exceptions which are not handled explicitly.
!note catch(...) should always be placed last in the list of handlers. placing it before other catch blocks would prevent those blocks from catching exceptions and will cause a syntax error
*/

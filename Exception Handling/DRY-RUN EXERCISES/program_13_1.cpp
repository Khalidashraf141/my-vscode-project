#include <iostream>
using namespace std;

int main()
{
    int a, b, r;
    a = 10;
    b = 0;
    try
    {
        if(b == 0)
            throw "divisor is 0";   // a string literal is thrown
        r = a/b;
        cout << "Result = " << r << endl;
    }
    catch(int arg)
    {
        cout << "Exception caught" << endl;
    }
    cout << "End of program";
    return 0;
}
/*
catch(const char* msg)  string literal catch handler
{
    cout << "Exception caught: " << msg << endl;
}
*/

/*
Output:
    During execution, a string literal is thrown when the divisor is zero. Since there is no matching catch handler for the thrown type, the exception remains uncaught, resulting in abnormal program termination.
*/
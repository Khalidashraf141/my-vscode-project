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
            throw 0.0;
        r = a/b;
        cout << "Result = " << r << endl;
    }
    catch(int arg)
    {
        cout << "Exception caught first" << endl;
    }
    catch(float arg)
    {
        cout << "Exception caught second" << endl;
    }
    cout << "End of program";
    return 0;

}

/*
output:
    terminate called after throwing an instance of 'double'

Exception handling in C++ requires an exact type match; implicit conversion are not performed during exception matching

Throw float explicitly
    throw 0.0f

Since 0.0 is of type double by default and there is not matching catch(double) handler, the exception remains uncaught, resulting in abnormal program termination
*/
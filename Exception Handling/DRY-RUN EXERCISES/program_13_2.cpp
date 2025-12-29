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
            throw 0;
        r = a / b;
        cout << "Result = " << r << endl;

    }
    catch(int arg1)
    {
        cout << "Exception caught first" << endl;
    }
    catch(int arg2) //unreachable
    {
        cout << "Exception caught second" << endl;
    }
    cout << "End of program";
    return 0;
    
}

/*
output:

Exception caught first
End of program
    !compiler warning - Both catch handlers have the same exception type(int)
                        !exception of type 'int' will be caught by earlier handler
    

    
When multiple catch handlers of the same type are used, only the first matching handler is executed, and subsequent handlers are ignored, making them unreachable.

*/
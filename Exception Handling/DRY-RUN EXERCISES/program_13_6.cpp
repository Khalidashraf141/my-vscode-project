#include <iostream>
using namespace std;

void fun()
{
    cout << "Inside function" << "\n";
    throw 10;
}

int main()
{
    int b;
    b = 0;
    try
    {
        if(b != 0)
            throw b;
        try{
            throw b;
        }
        catch(int arg)
        {
            cout << "Caught Exception 1: " << "\n";
            fun();
        }
        catch(...)
        {
            cout << "Caught Exception 2: " << "\n";
        }
    }
    
    catch(int arg)
    {
        cout << "Caught Exception 3: " << "\n";
    }
    cout << "End of main\n";
    return 0;
}
/*
Output:
    Caught Exception 1:
    Inside function
    Caught Exception 2:
    End of main

The catch-all handler is skipped because exception thrown by fun() occurs outside the scope of the inner try block, and is therefore handled by the outer catch handler



The inner exception is caught by the inner catch block. The function fun() throws a new integer exception which is not handled locally and therefore propagates to the outer try block, where it is caught by catch(int). The catch-all handler is not executed since a matching typed handler exists.
*/
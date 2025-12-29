#include <iostream>
using namespace std;

int main()
{
    int a, b, r;
    a = 25;
    b = 0;
    try{
    try{
        if(b == 0)
            throw b;
    }
    catch(int arg)
    {
        cout << "Caught Exception 1: " << arg << "\n";
        throw;
    }   
    }

    catch(int arg)
    {
        cout << "Caught Exception 2: " << arg << "\n";
    } 
    cout << "End of main\n";
    return 0;
    
}

/*
output:
    Caught Exception 1: 0
    Caught Exception 2: 0
    End of main

In this program, the exception thrown in the inner try block is caught, partially handled,
and then rethrown using throw; The rethrown exception is subsequently caught by the outer catch block, demonstrating nested exception handling and rethrowing.
*/
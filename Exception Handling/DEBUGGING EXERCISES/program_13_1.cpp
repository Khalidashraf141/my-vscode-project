#include <iostream>
using namespace std;
int main()
{
    int p,q;
    cout << "Input two integer numbers: ";
    cin >> p >> q;
    try
    {
        if(q != 0)
        {
            float div = (float)p/q;

            if(div < 0)
                throw div;
            cout << "p/q = " << div;
        }
        else
            throw (q);
    }

    catch(int){
        cout <<"Exception Caught: Division by zero";
    }
    catch(float){
        cout << "Exception Caught: Division is less than 1";
    }
    return 0;

}

/*
The error occurs because a float value is thrown, but no corresponding catch(float) handler exists. Since exception handling in C++ requires an exact type match, the exception remains uncaught, causing abnormal program termination

*/
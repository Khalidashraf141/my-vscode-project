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
        r = a/b;
        cout << "Result = " << r << endl;
    }
    // catch(...)
    // {
    //     cout << "Exception caught first" << endl;
    // }
    catch(int arg)
    {
        cout << "Exception caught second" << endl;
    }
    catch(...)
    {
        cout << "Exception caught first" << endl;
    }
    cout << "End of program";
    return 0;
}

/*
The program is incorrect because the catch all handler catch(...) is placed before the specific catch handler. Since catch(...) can handle all types of exceptions, it intercepts the
exception first, making subsequent catch block unreachable. Therefore, catch(...) must always be placed at the bottom.
*/
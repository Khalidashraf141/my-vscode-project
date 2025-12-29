/*Write a program that demonstrate now certain exception types are not allowed to be thrown*/
#include <iostream>
using namespace std;

void test()throw(int)   //only int exceptions are allowed (Exception specifications like throw(int) are deprecated) Modern C++ uses (noexcept).
{
    cout << "Inside test function\n";
    throw 'A';  //char exception not allowed
}

int main()
{
    try{
        test();
    }
    catch(int)
    {
        cout << "Integer exception caught\n";
    }
    catch(...)
    {
        cout << "Unhandled exception caught\n";
    }
    return 0;
}

/*it is not allowed because an exception outside the specified list violates the function's exception contract and leads to abnormal program termination to maintain program safety.*/

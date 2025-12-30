#include <iostream>
using namespace std;

class Test
{
    int* ptr;
public:
    Test()
    {
        ptr = new int[5];
    }
/*
    ~Test()
    {
        try
        {
            cout << "Destructor running\n";
            throw 10;
        }
        catch(int e)
        {
            cout << "Exception handled inside destructor\n";
        }
        delete[] ptr;   //resource safely released
        cout << "Memory freed safely\n";
    }
*/
    /*Modern way*/
    ~Test()noexcept{
        cout << "Destructor running\n";
        delete[] ptr;
        cout << "Memory freed safely\n";
    }
};

int main()
{
    Test obj;
    cout << "Main ends\n";
}
/*
If an exception is throw from destructor, it may lead to memory leaks or program termination, especially during stack unwinding. Although such exceptions can be caught in the main function, it is unsafe. Therefore, exceptions raised inside a destructor should be handled within the destructor itself, and the destructor should never rethrow exceptions.

Golden rule 
destructor should never throw exceptions


A destructor should never throw exceptions to the calling function. Any exception raised inside a destructor must be handled within the destructor itself to avoid abnormal program termination.
*/
#include <iostream>
using namespace std;

class Test
{
    int* ptr;
public:
    Test()
    {
        try
        {
            ptr = new int[5]; // memory allocate
            cout << "Memory allocated\n";
            throw 10;   // exception
        }
        catch(int e)
        {
            delete[] ptr;
            cout << "Memory deleted inside constructor\n";
            throw;  //rethrow
        }
    }
    ~Test()
    {
        cout << "Destructor called\n";
    }
};

int main()
{
    try
    {
        Test obj;
    }
    catch(int e)
    {
        cout << "Exception caught in main\n";
    }
    return 0;
}
/*
this program demonstrate that if an exception occurs in a constructor, the destructor is not called. Therefore, memory allocated in the constructor must be released inside the constructor itself, and the exception should be rethrown to be handled in main().


If an exception is thrown in a constructor, the destructor is not called. Therefore, exceptions must be caught inside the constructor to release allocated resources and then rethrown for handling in the calling function.


Constructor me exception aaye -> destructor nahi chalega
    • Constructor ka kaam = object banana
    • Agar constructor beech me fail ho gaya (exception aa gaya)
    • To object complete bana hi nahi
    Rule yaad rakho 
        Destructor is called only for fully constructed objects.
    ❌ Object incomplete -> ❌ Destructor call

    Exception ko rethrow kiya jata hai taaki main() ke catch me handle ho
*/
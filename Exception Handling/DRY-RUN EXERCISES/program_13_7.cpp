#include <iostream>
using namespace std;

void Myclass()
{
    try{
        throw "y";
    }
    catch(const char*)
    {
        cout << "Exception inside Myclass\n";
        throw;
    }
}

int main()
{
    cout << "Now main starts\n";
    try{
        Myclass();
    }
    catch(const char*)
    {
        cout << "Exception inside Main\n";
    }
    cout << "Now Main ends\n";
    return 0;
}

/*
Output:
    Now main starts
    Exception inside Myclass
    Exception inside Main
    Now Main ends


*/
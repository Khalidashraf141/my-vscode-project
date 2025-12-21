// Throw point outside the try block
#include <iostream>
using namespace std;

void divide(int x, int y, int z)
{
    cout << "\nWe are inside the function\n";
    if(x-y != 0)
    {
        int R = z/(x-y);
        cout << "Result = " << R << "\n";
    }
    else{
        throw(x-y);// this will trigger catch
    }
}

int main()
{
    try
    {
        cout <<"We are inside the try block\n";
        divide(10,10,30);
    }
    catch(int i)
    {
        cout << "Caught the exception\n";
    }
    return 0;
}
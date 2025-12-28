/*Demonstrate with appropriate syntax what should be placed inside try block*/
#include <iostream>
using namespace std;

int main()
{
    int a = 10, b = 0;

    try
    {
        //Risky code
        if(b == 0)
        {
            throw b;
        }
        cout << a / b << endl;
    } 
    catch(int)
    {
        cout << "Error: Division by Zero" << endl;
    }
    cout << "Program continues normally" << endl;
    return 0;
}
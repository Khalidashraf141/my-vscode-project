/*Write a program containing a possible exception. Use a try block to throw it and a catch block to handle it properly*/
#include <iostream>
using namespace std;

int main()
{
    int a, b, result;
    a = 12;
    b = 0;
    try{
        if(b == 0)
        {
            throw b;    //possible exception
        }
        result = a/b;
        cout << "Result = " << result << endl;
    }
    catch(int arg)
    {
        cout<< "Exception caught: Division by 0" << endl;
    }
    cout << "End of program" << endl;
    return 0;
}
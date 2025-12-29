/*Write a program that illustrate the application of multiple catch statements*/
#include <iostream>
using namespace std;

int main()
{
    int a, b;
    a = 12;
    b = 0;
    try{
        if(b == 0){
            throw b;
        }
        if(a < 0)
            throw 'a';
        
        cout << "Result = " << a/b << endl;
    }
    catch(int x)
    {
        cout << "Exception caught: Division by 0" << endl;
    }
    catch(char c)
    {
        cout << "Exception caught: Negative value" << endl;
    }
    cout << "End of program" << endl;
    return 0;
}
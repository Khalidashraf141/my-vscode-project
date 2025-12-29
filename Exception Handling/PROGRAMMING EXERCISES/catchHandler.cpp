/*Write a program which uses catch(...) handler*/

#include <iostream>
using namespace std;

int main()
{
    int a, b;
    a = 12;
    b = 0;
    try
    {
        if(b == 0){
            throw 'a';
        }
        if(a < 0){
            throw a;
        }
    }
    catch(char x)
    {
        cout << "Exception caught: Division by 0" << endl;
    }
    catch(...)
    {
        cout << "Exception caught: Negative Number" << endl;
    }
    return 0;
}
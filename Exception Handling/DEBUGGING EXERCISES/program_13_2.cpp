#include <iostream>
using namespace std;
void practical(int x)
{
    try
    {
        throw 20;
        throw 30;   //unreachable
    }
    catch(int e)
    {
        cout << "Exception caught:\n" << e <<"\n";
    }
    // catch()
    // {
    //     cout << "Exception caught:\n";
    // }
}

int main()
{
    practical(1);
    practical(2);
    return 0;
}
/*
The second catch handler is incorrect because catch() without any parameter is not allowed in C++. Moreover, since only integer exceptions are thrown using throw 20; a single catch(int e) handler is sufficient. Also, only the first throw statement is executed, and the second throw is unreachable.

*/
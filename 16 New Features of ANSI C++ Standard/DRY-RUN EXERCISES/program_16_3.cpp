#include <iostream>
using namespace std;

namespace demo
{
    int x = 50;
}
using namespace demo;

void fun1()
{
    int x = 5;
    cout << x << "\n";
}
void fun2()
{
    cout << x << "\n";
}

int main()
{
    int x = 10;
    cout << x << "\n";
    fun1();
    fun2();
    return 0;
}
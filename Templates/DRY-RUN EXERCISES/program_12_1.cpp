#include <iostream>
using namespace std;

template<class T>
void fun(T arg1, int arg2)
{
    cout << "Fun 1: " << arg1 << " " << arg2 << endl;
}

template<class T1, class T2>
void fun(T1 arg1, T2 arg2)
{
    cout << "Fun 2: " << arg1 << " " << arg2 << endl;
}

void fun(int arg1, int arg2)
{
    cout << "Fun 3: " << arg1 << " " << arg2 << endl;
}

int main()
{
    fun(25,28); // Fun3
    fun(25,28.0);   // Fun2
    fun(25.0,28); // Fun1
    return 0;                        
}
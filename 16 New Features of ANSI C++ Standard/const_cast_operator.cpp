/*Removes const or volatile qualifier*/
#include <iostream>
using namespace std;

int main()
{
    // const int x = 10; modifying a truly const object using const_cast results in undefined behavior
    int a = 10;
    const int* p = &a;

    int* q = const_cast<int*>(p);
    *q = 20;

    cout << a;
    return 0;
}
/*
Works only with pointers or references
*/
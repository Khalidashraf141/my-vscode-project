// TOPIC: Assignment Operator Overloading In C++

// POINTS:
// 0. When should we write our own assignment operator in C++?
// 1. This comes under binary operator overloading?
// 2. When we need deep copy, assignment operator must be overloaded.
// 3. We should also create own copy constructor when overloading assignment operator and vice versa.

// FUNCTION POINTS
// 0. Check self assignmet because it is dangerous 
// 1. Assignment operator must be overloaded by a non-static member function only.

#include <iostream>
using namespace std;
class Test
{
    int *x;
public:
    Test(int val = 0):x{new int(val)} {}
    void setX(int val) {*x = val;}
    void print() {cout << "OUTPUT: "<< *x << "\n";}
    ~Test() {delete x;}

    Test& operator = (const Test& rhs)
    {
        if(this != &rhs)
            *x = *rhs.x;
        return *this;
    }

};

int main()
{
    Test t1(10);
    Test t2;
    t2 = t1;
    t1.setX(20); 
    t1.print();
    t2.print();
    return 0;
}

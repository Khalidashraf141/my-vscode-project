#include <iostream>
using namespace std;

class B
{
    float b;
public:
    B()
    {
        b = 5.0;    // 4 bytes
    }
    virtual void show() // adds a vptr
    {
        cout << b << endl;
    }
};

class D : public B
{
    float d;
    float d1;
public:
    D()
    {
        // B::B();
        d = 10.0;
        d1 = 20.0;
    }
    void show()
    {
        cout << d << endl;
    }
};

int main()
{
    B ob, *ptr;
    D ob1;
    ptr = &ob;

    cout << sizeof(*ptr) << endl;
    ptr = &ob1; // still B* that's why 8 and 8 output 
    cout << sizeof(*ptr) << endl;

    cout << sizeof(D) << endl; //now it is pointing to D
    return 0;
}
/*
!C++ does not perform dynamic type deduction in sizeof().
✔️ sizeof() only cares about:
    - this TYPE written in code.
    - which is decided at compiler time

⭐Visual Explanation 
class B object layout (on my system)
[B object]
b      -> 4 bytes
vptr   -> 4 bytes
-----------------
total  -> 8 bytes


class D object layout:
[D object] 
b   -> 4 bytes (from B) (inherited)
vptr-> 4 bytes (from b)
d   -> 4 bytes 
d1  -> 4 bytes
--------------
total-> 16 bytes

✔️ float b
Takes 4 bytes
✔️ virtual void show()
because of this virtual function, the compiler insets:
    vptr(virtual table pointer)

!This is a hidden pointer added to every object of a class with virtual functions.
    - On your system (32-bit) -> vptr = 4 bytes
    - On a 64-bit system -> vptr = 8 bytes

So total for your system:
    float (4) + vptr (4) = 8 bytes
sizeof(B) = 8



*/
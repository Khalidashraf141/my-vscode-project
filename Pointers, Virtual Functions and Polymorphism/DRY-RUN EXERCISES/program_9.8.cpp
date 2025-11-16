#include <iostream>
using namespace std;
class B
{
    float b;
public:
    B()
    {
        b = 5.0;
    }
    void show()
    {
        cout << b << endl;
    }
};
class D : public virtual B
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
    cout << sizeof(*ptr) << endl;
    ptr = &ob1;
    cout << sizeof(*ptr) << endl;
    return 0;
}

//!to avoid multiple copy we use virtual inheritance
/*
                                     A
                                    / \
                                   B   C
                                    \ /
                                     D
                                    - class B inherits form A
                                    - class C inherits from A
                                    - class D inherits from B and C
                                    !without virtual inheritance, 
                                    D gets two copies of A (one from B, one from C).
                                    This causes:
                                        - Ambiguity
                                        - Duplicate data
                                        - Memory waste
                                Solution:
                                    class B : public virtual A{};
                                    class C : public virtual A{};
                                    class D : public B, public C{};

                                    Now:
                                        - D gets only one copy of A
                                        - Compiler resolves ambiguity
                                        - Memory is saved
                                        - Correct behaviour
WHEN to use virtual inheritance
    ✔️ You have multiple inheritance
    ✔️ And the base class appears more than one through different paths
    ✔️ To avoid duplicate copies of the base class
    ✔️ To avoid ambiguous references
    ✔️ To ensure only one shared base class exists

❌ When NOT to use virtual inheritance
Do NOT use virtual inheritance if:
    - You have single inheritance
    - You are not facing the diamond problem
    - You do not need shared base class
    - You do not understand why you need it


Meaning of overhead in computer
    - extra memory
    - extra CPU work
    - extra complexity
    - extra time
that comes in addition to the main task.

1. Memory Overhead
Extra bytes added to an object or process.
    example:
        when you use virtual functions, the compiler adds a vptr(virtual pointer) -> extra 4 or 8 bytes.
    This is extra memory is overhead
2. Runtime Overhead
Extra CPU work at run time.
    Example:
        Calling a virtual function uses dynamic dispatch, which takes slightly more CPU steps than a normal function call.
Those extra CPU steps = overhead

3. Code Overhead
Extra lines of machine code
*/
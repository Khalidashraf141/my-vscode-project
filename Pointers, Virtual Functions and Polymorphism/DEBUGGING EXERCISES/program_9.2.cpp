#include <iostream>
using namespace std;

int main()
{
    int p = 10;
    double q = 20.33;

    int *x = &p;
    double *y = &q;

    // y = &p; //!WRONG
    // x = &q; //!WRONG
/*
    These two are wrong ❌
    1)we already store the address of p in pointer x and q in pointer y
    2)we can't sore the address of int value in double and double address value in int
*/
    cout << "Value 1 : " << p << endl;
    cout << "Value 2 : " << q <<endl;
    return 0;
}

/*
*Explanation 
❌Wrong Line 1:
    y = &q; // ERROR
Why?
Because:
    - y is a pointer to double -> double*
    - &p is the address of an int -> int*
A double* cannot store an int*
The types don't match

❌Wrong Line 2:
    x = &q; // ERROR
Why?
Because:
    - x is a pointer to int -> int*
    - &q is the address of a double -> double*
An int* cannot store a double*

!Why types must match?
Pointers point to memory, and different data types have different size:
    - int = usually 4 byes
    - double = usually 8 bytes
If you store an int address in a double*, the CPU will try to read 8 bytes from an address that contain only 4bytes of valid int data, causing memory corruption.

This is why C++ strictly prevents mixing pointer types for safety




*/
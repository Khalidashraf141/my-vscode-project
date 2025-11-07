/*
Pointers
-pointer is a derived data type
-A pointer is a variable that stores the memory address of another variable

Normal variable -> stores a value
Pointer -> stores the address of of that value

    & -> Address-of operator (gives memory address)
    * -> Dereference operator (accesses value at that address)

In simple words:
    A pointer is like a house key that tells you where the value (house) is located in memory
    Using *ptr, you can enter the house and see or change the value inside.

*/

//Example
#include <iostream>
using namespace std;

int main()
{
    int num = 10; // normal variable
    int *ptr = &num; // pointer variable storing address of num;

    cout << "Value of num: " << num << endl;
    cout << "Address of num: " << &num << endl;
    cout << "Value stored in ptr (address): " << ptr << endl;
    cout << "Value pointed by ptr: " << *ptr << endl; //*ptr gives value at address (it is called dereferencing)


    cout << "\n\n";
    int a, *add1, **add2;
    add1 = &a;
    add2 = &add1;

    cout << "The address of a: " << add1 << "\n";
    cout << "The address of add1: " << add2;
    cout << "\n\n";
    cout << "After incrementing the address values:\n\n";
    add1+=2;
    cout << "The address of a : " << add1 << "\n";
    add2+=2;
    cout << "The address of add1 : " << add2 << "\n";


    cout << "\n\n\n";

/*
-Void pointers(generic pointers)
    -A void pointer is a special type of pointer that can point any data type (int float char double etc)
    but it (does not know the type of data it points to.)

*/
    int k = 10;
    float l = 5.5;
    char c = 'K';
    //but before using *loc you must typecast it to the correct pointer type - otherwise the compiler doesn't know how many bytes to read.
    
    void* loc = &k;
    cout << "Integer value: " << *(int*)loc << endl; // here we are typecasting loc into int

    void* llo = &l;
    cout << "Float value: " << *(float*)llo << endl;

    void* cll = &c;
    cout << "Character value: " << *(char*)cll << endl;
    return 0;
}
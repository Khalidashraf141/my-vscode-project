/*
1. 🔴Shallow Copy (Default Copy)
[A shallow copy simply copies the values of data members--including pointers--as they are]
[In shallow copy: Both t1.ptr and t2.ptr point to the same memory address]
[so if you change one: Then both objects see the change because they share the same memory]
❌Problem:
-When one object is destroyed, the memory is deleted.Then the other object still tries to access the same delted memory-causing a crash (dangling pointer).
*/

/*
2.Deep Copy
-A deep copy makes a completely new copy of the data in memory
*/


#include <iostream>
using namespace std;

class Test
{
    int *ptr;
public:
    //shallow copy
    Test(int val)
    {
        ptr = new int(val);
    }

    //deep copy constructor
    Test(const Test  &obj)
    {
        ptr = new int(*obj.ptr); // copy the value, not the address
    }

    ~Test()
    {
        delete ptr;
    }
};

int main()
{
    //deep copy
    Test t1(5); //t1.ptr-> points its own memory
    Test t2 = t1; //t2.ptr-> points to a different memory block with the same value

    //so changing one doesn't affect the other.
    //and when one is destroyed, the other's memroy is sill safe.

    return 0;
}

/*
-Shallow copy: You and your friend share the same key-- one gets lost, both are affected
-Deep copy: You both have seperate copies-- losing one doesn't affect the other 


*/
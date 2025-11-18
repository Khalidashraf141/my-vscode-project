#include <iostream>
using namespace std;
//TODO:PRACTICE DONE
int main()
{
    int a = 10;
    int *ptr = &a;

    cout << "The value of a is: " << *ptr << endl;
    *ptr+=10;
    cout << "After increment the value of a is: " << *ptr << endl;
    cout << "After increment the value of a is: " << a << endl;
    
    
    /*
    Caution->
    -Before dereferencing a pointer, it is essential to assign a value to the pointer. If we attempt to dereference an uninitialized pointer, it will cause runtime error by referring to any other location memory.
    */
   
   //Example:
   int *add; //❌ uninitialized pointer (contains garbage address)
   *add = 20; // trying to write value to random location
   cout << *add; // runtime error or crash
//This causes undefined behavior because ptr doesn't point to any real variable(this is not a good practice)
   return 0;
}
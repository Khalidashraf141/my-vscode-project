/*
    *Virtual Functions
- Polymorphism refers to the property by which object belonging to different classes are able to respond to the same message but in different forms we use pointer to base class to refer to all the derived object.

we just discovered that a base class. The compiler simply ignores the contents of the pointer and always executes the function in the base class. The compiler simply ignores the contents of the pointer and chooses the member function that matches the pointer. 

How do we then achieve polymorphism?
-It is achieved using what is known as (Virtual Function)

When we use the same function name in both the base and derived classes, the function in base class is derived  as virtual using keyword virtual preceding its normal function.

When a function is made virtual, C++ determines which function to use at runtime base on the type of object pointed to by the (base pointer), 

!rather than the type of the pointer by making the base pointer to point to different objects,
(In C++ when a function is declared as virtual, the function that gets executed is determined at runtime based on the (type of the object being pointed to), rather than the type of the pointer by making base pointer to different derived class objects)

we can execute different versions of the virtual function
*/

#include <iostream>
using namespace std;

class Base
{
    public:
        void display(){cout << "\n Display Base ";}
        virtual void show(){cout << "\n show base";}
};

class Derived : public Base
{
    public:
        void display(){cout << "\n Display derived";}
        void show(){cout << "\n show derived";}
};

int main()
{
    Base B;
    Derived D;
    Base *bptr;

    cout << "\n bptr points to Base \n";
    bptr = &B;
    bptr->show(); // calls Base version
    bptr->display(); // calls Base version

    cout << "\n\n bptr points to Derived\n";
    bptr = &D;
    bptr->display();    //Note: calls Base version. This is because the function display() has not been made virtual in the Base class.
    bptr->show();   // calls Derived version

    return 0;
}
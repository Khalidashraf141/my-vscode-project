/*Virtual constructor is not possible*/
/*Virtual destructor is possible*/
#include <iostream>
using namespace std;

// Base class with VIRTUAL destructor
class Base
{
    public:
        Base()
        {
            cout <<"Base constructor\n";
        }

        // Virtual destructor
        virtual ~Base()
        {
            cout <<"Base Destructor\n";
        }

        // Virtual function 
        virtual void show()
        {
            cout <<"Base show\n";
        }
};

// Derived class 
class Derived : public Base{
    private:
         int* data; // dynamically allocated memory
    public:
        Derived()
        {
            data = new int[5]; // dynamically allocated memory
            cout << "Derived constructor\n";
        }

        ~Derived()
        {
            delete[] data;      // freeing memory
            cout << "Derived Destructor\n";
        }

        void show() override{
            cout << "Derived Show\n";
        }
};

int main()
{
    Base* ptr = new Derived(); // Base pointer -> Derived object

    ptr->show();    // Calls Derived::show() (virtual dispatch)

    delete ptr; // IMPORTANT: Base pointer deleting Derived
                // Because destructor is virtual:
                // 1. Derived destructor runs first
                // 2. Base destructor runs second

    return 0;
}

/*
*Base Constructor
*Derived Constructor
*Derived show
*Derived Destructor
*Base Destructor
*/

/*
1. Why constructor order is Base -> Derived?
Because:
    - Base part of the object is created first
    - Then derived part is created
So output:
    Base Constructor
    Derived Constructor

2. Why derived show is printed?
because show() is virtual
so:
    Base* ptr = new Derived();
    ptr-> show();
-> Goes to Derived's vtable
-> Calls Derived::show()

this is virtual dispatch

3. Why destructor runs Derived -> Base?
When virtual destructor is present:
    delete ptr;
steps:
    ✔️Setp 1: Derived destructor runs
because vtable points to Derived's destructor
 -> deletes dynamic memory safely
    ✔️setp 2: Base destructor runs
cleans the base class of the object
so output:
    Derived destructor
    Base destructor
this is exactly the correct cleanup order.

Why virtual destructor is important?
Because if the destructor is NOT virtual.

Base* ptr = new Derived();
delete ptr;

Then:
    - only Base destructor runs
    - Derived destructor is skipped
    - Memory leak occurs (data never freed)

So always use virtual destructor in polymorphic base classes.


note: a virtual destructor ensures that destroying an object through a base pointer calls the derived destructor first and prevents memory leaks.


*/
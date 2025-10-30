/*
🧠Concept: Effect of Access Specifiers in Inheritance
    1.Private Inheritance
    -When a base class is privately inherited,
    ->public and protected members of the base class become private in the derived class.
    ->So,the derived class's own member function can use them, but objects of the derived class cannot access them directly.

    In short:
        - ✅Accessible inside derived class methods.
        - ❌Not accessible through derived class objects.
*/

#include <iostream>
using namespace std;

class Base
{
    public:
        void show(){
            cout << "Base public member" << "\n";
        }
};

class Derived : private Base{
    public:
        void display(){
            show(); // OK (accessible inside derived class)
        }
};

int main()
{
    Derived d;
    d.display(); //Ok
    // d.show(); ❌ Error! (not accessible through object)

    return 0;
}
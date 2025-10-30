/*
🧩Concept: Function Overriding in Inheritance
-When both the class and the derived class have a function with the same name and same parameters, then the derived class function overrides (or replaces) the base function for the derived class objects.

*/

//Example->
#include <iostream>
using namespace std;

class Base
{
    public:
        void show(){
            cout << "Base class function" << "\n";
        }
};

class Derived : public Base
{
    public:
        void show(){ //same name as Base Class
            cout << "Derived class function" << "\n";
        }
};

int main()
{
    Derived d;
    d.show(); // Derived class has its own version of show(), it overrides the show() of the Base class
// derived class function hides the base class function of the same name.

    d.Base::show();// You can still access the base class version using the scope resolution operator
    Base b;
    b.show();
    return 0;
}
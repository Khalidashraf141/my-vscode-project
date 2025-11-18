/*
Compile-time polymorphism simply means that an object is bound to its function call at the compile time.That means there is no ambiguity at the compile time about which a function is to be linked to a particular function's call. This mechanism is called (early binding) or (static binding) or (static linking)

Compile-time polymorphism means that the function call is linked (or bound) to its function definition during compile time.

!That is, the compiler knows exactly which function to call before the program runs, so there is no ambiguity at runtime.

*/
//TODO:PRACTICE DONE
#include <iostream>
using namespace std;

class Print
{
    public:
        void show(int a)
        {
            cout << "Integer: " << a << endl;
        }
        void show(double a)
        {
            cout << "Double: " << a << endl;
        }
};



class B
{
    public:
        void show()
        {
            cout << "Base\n";
        }
};

class D : public B
{
    public:
        void show()
        {
            cout << "Derived\n";
        }
};


int main()
{
    Print p;
    p.show(5);  // Calls show(int)
    p.show(5.5); //Calls show(double)

    //The compiler decides at compile time which version of show() to use-based on the argument type.
    // So there's no confusion (no ambiguity) at runtime


    D d;
    d.show();   // calls derived class show() function
    d.B::show(); // calls based class show() function
    //*d.show() function call overrides the show() function defined in the base class. To make the object d specifically call the base class show() function. we have used the class resolution operator

    return 0;
}

/*
run-time polymorphism:- is known which function will be invoked till an object actually makes the function call during the program's execution.This process is referred as late or dynamic binding
*run time polymorphism is achieved with the help of virtual function
*/
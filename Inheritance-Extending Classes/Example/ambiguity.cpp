/*
🧩 Ambiguity in Inheritance
-Ambiguity occurs when a derived class inherits two or more base classes that have functions with same name. Then the compiler gets confused--it doesn't know which function to call
*/

#include <iostream>
using namespace std;

class A
{
    public:
        void show(){cout << "Class A show()" << "\n";}
};

class B
{
    public:
        void show(){cout << "Class B show()" << "\n";}
};

class C : public A, public B
{
    public:
        void display()
        {
            A::show(); // call A's version
            B::show(); // call B's version
            /*
            -You can explicitly tell the compiler which base class's function you want to use by using the scope resolution operator(::)
            */
        }
};

int main()
{
    C obj;
    obj.display();
    return 0;
}
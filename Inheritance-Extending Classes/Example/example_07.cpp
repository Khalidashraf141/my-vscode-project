/*
    2.Public Inheritance
        -public members of the base class remain public in the derived class.
        -protected members remain protected.
        -Therefore, they can be accessed using objects of the derived class.
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

class Derived : public Base{
    public:
        void display(){
            show(); //Ok
        }
};

int main()
{
    Derived d;
    d.show();
    d.display();
    return 0;
}
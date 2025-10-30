/*
    3.Private Members
        -Private members of the base class are never inherited directly.
        -Even the derived class cannot access them- it can only use them through public or protected functions of the base class
*/

/*
-A protected function (or variable) in a class something that:
    - Cannot be accessed by objects directly.
    - Can be accessed inside the class and also by derived (child classes)


*/

#include <iostream>
using namespace std;

class Base{
    protected:
        void protectedFunction(){
            cout << "This is a protected function of Base." << "\n";
        }
};

class Derived : public Base{
    public:
        void accessBaseFunction(){
            protectedFunction(); // ✅Allowed (Derived can access protected members of Base)
        }
};

int main()
{
    Derived obj;
    obj.accessBaseFunction(); // works (calls through derived function)
    // obj.protectedFunction(); // Error! not accessible by object

    return 0;
}
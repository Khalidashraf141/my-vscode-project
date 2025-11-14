/*
                PURE VIRTUAL FUNCTION
-declare a function virtual inside the base class and redefine it in derived class
-function inside the base class is seldom used for performing any task. It only serves as a placeholder.

                                   +----------------------------------------------+
                                   |                 BaseClass                    |
                                   +----------------------------------------------+
                                   |  virtual void display() { }                  |
                                   |        |                                     |
                                   |        |---> This is an empty virtual func   |
                                   |        |---> Also called "do-nothing" func   |
                                   +----------------------------------------------+
                                  !|  These kinds of functions are treated as     |
                                  !|  PURE VIRTUAL FUNCTIONS                      |
                                   +----------------------------------------------+

-> that a class containing pure virtual function cannot be used to declare any objects of its own.
            imp -> such classes are called (abstract base classes)

note-> aagar class me pure virtual function hai to uska objects nhi ban sakta hai aur aise class ko abstract base classes class bolte hai


    !The main objective of abstract base classes to provide some traits to the derived class and to create a base pointer required for achieving run time polymorphism
*/

#include <iostream>
using namespace std;

class Balagurusamy  //base class
{
    public:
        virtual void example()=0;  //Denotes pure virtual Function Definition
};

class C : public Balagurusamy   //derived class 1
{
    public:
        void example()
        {
            cout << "\nC text Book written by Balagurusamy";
        }
};

class oops : public Balagurusamy  //derived class 2
{
    public:
        void example()
        {
            cout << "\nC++ text Book written by Balagurusamy";
        }
};

int main()
{
    Balagurusamy* arr[2];
    C e1;
    oops e2;
    arr[0]=&e1;
    arr[1]=&e2;

    arr[0]->example();
    arr[1]->example();
    return 0;
}
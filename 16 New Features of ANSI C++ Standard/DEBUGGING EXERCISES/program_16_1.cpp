#include <iostream>
class A
{
    public:
        A(){

        }
        A(int i)
        {

        }
};

class B
{
    public:
        B()
        {

        }
        explicit B(int)
        {

        }
};

int main()
{
    A a1 = 12;
    A a2;
    A a3 = a1;
    // B b1 = 12; WRONG
    B b1(12);//Right 
    /*
    Class B (explicit constructor)
    B b1 = 12; -> WRONG
    Why?
        explicit B(int) blocks implicit conversion
        Copy-initialization (=) is not allowed
    Compiler will not convert 12 -> B(12) automatically
    */
}
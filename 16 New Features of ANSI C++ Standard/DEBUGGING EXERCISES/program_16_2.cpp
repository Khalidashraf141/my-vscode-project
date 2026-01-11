#include <iostream>
using namespace std;

class A
{
    protected:
        int i;
    public:
        A()
        {
            i = 10;
        }
        virtual int getI()
        {
            return i;
        }
};

class B : public A
{
    public:
        B()
        {

        }
        int getI()
        {
            return i + i;
        }
};

int main()
{
    // A *a = new A();
    A *a = new B();
    // B *b = static_cast<B*>(a);
    B *b = dynamic_cast<B*>(a);

    if(b)
    cout << b->getI();
    return 0;
}
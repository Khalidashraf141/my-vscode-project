#include <iostream>
using namespace std;

class original_base
{
    public:
        virtual void print()
        {
            cout << "print version of base class" << endl;
        }
        void show()
        {
            cout << "show version of base class" << endl;
        }
};

class derived_from : public original_base
{
    public:
        void print()
        {
            cout << "print version of derived class" << endl;
        }
        void show()
        {
            cout << "show version of derived class" << endl;
        }
};

int main()
{
    original_base *ptr;
    derived_from x;
    ptr = &x;
    ptr->print();
    ptr->show();

    return 0;
}
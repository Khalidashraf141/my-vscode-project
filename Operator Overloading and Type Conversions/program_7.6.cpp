#include <iostream>
using namespace std;

class test
{
    public:
        int num;
        test(int j)
        {
            num = j;
        }

        test* operator ->(void)
        {
            return this;
        }
};

int main()
{
    test T(5);
    test *Ptr = &T;

    cout << "T.num = " << T.num; // Accessing num normally
    cout << "\nPtr->num = " << Ptr->num; //Accessing num using normal object pointer
    cout << "\nT->num = " << T->num; // Accessing num using overloaded ->Operator

    return 0;
}
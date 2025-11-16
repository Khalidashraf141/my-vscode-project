/*What will happen when the following program is run?*/
#include <iostream>
using namespace std;

class B
{
    float b;
public:
    B()
    {
        b = 5.0;
    }
    void show()
    {
        cout << b << endl;
    }
};

class D : public B
{
    float d;
    float d1;
public:
    D()
    {
        //B::B(); this was written
        d = 10.0;
        d1 = 20.0;
    }
    void show()
    {
        cout << d << endl;
    }
};

int main()
{
    B ob, *ptr;
    D ob1;
    ptr = &ob1;
    ptr->show();//this will show not run class D show because this function is not virtual class B show() will run 

    cout << ptr << endl;
    ptr++;
    cout << ptr;
    return 0;
}
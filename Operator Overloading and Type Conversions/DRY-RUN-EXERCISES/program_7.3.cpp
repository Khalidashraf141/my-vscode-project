#include <iostream>
using namespace std;

class demo
{
    int data;
public:
    demo(){}
    demo(int d)
    {
        data = d;
    }
    void show(void)
    {
        cout << data <<"\n";
    }

    void operator ++()
    {
        data++;
    }
    demo &operator = (demo &t)
    {
        t.data = data; //we copy ob1 in ob2 (it is in reverse order)
        return t;
    }
};

int main()
{
    demo ob1(10),ob2;
    ++ob1; 
    ob1 = ob2;
    ob1.show();
    ob2.show();
    return 0;

}

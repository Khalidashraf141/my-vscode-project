#include <iostream>
using namespace std;

class p
{
    public:
        int i;
};

class q : virtual public p
{
    public:
        int j;
};

class r: virtual public p
{
    public:
        int k;
};

class s :  public q, public r
{
    public:
        int mul;
};

int main()
{
    s obj1;
    obj1.i = 1;
    obj1.j = 20;
    obj1.k = 30;
    obj1.mul = obj1.i * obj1.j * obj1.k;
    cout << "Mul is : " << obj1.mul << "\n";
    return 0;
}
//for more understanding program_8.3.md read this file
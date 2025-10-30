#include <iostream>
using namespace std;

class pract
{
    int a,b,c;
    public:
    pract(int x, int y, int z)
    {
        a = x;
        b = y;
        c = z;
    }
    void show()
    {
        cout << "\nValues " << a << "\t" << b << "\t" << c;
    }
};

int main()
{
    pract Object1(10,20,30);
    pract Object2 = Object1;
    pract Object3 = Object2;
    Object3.show();
    return 0;
}
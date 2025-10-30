#include <iostream>
using namespace std;

class integer
{
    int m, n;
    public:
        integer()
        {
            m = 0;          //constructor 1
            n = 0;
        }

        integer(int a, int b)
        {
            m = a;          //constructor 2
            n = b;
        }

        integer(integer &x)
        {
            m = x.m;        //constructor 3
            n = x.n;
        }
        void display(void)
        {
            cout << "m = " << m << " n = " << n << "\n";
        }
};

int main()
{
    integer I1;
    I1.display();
    integer I2(10,20);
    I2.display();
    integer I3(I2);
    I3.display();

    return 0;
}
/*
The first constructor receives no arguments
The second receives two integer arguments
The third receives one integer object as an argument (such a constructor is called copy constructor)
*/
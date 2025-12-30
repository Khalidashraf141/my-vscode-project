#include <iostream>
using namespace std;

class Complex
{
    int x, y;
public:
    class FLAG{};   // user-defined exception

    Complex(int a = 0, int b = 0)
    {
        x = a;
        y = b;
    }

    Complex operator+(const Complex &c)
    {
        if(c.x == 0 && c.y == 0)
            throw FLAG();
        return Complex(x + c.x, y+c.y);
    }

    void show()const
    {
        cout << x << " + " << y << "i\n";
    }
};

int main()
{
    Complex c1(2,3), c2(0,0);

    try
    {
        Complex c3 = c1 + c2;
        c3.show();
    }
    catch(Complex::FLAG)
    {
        cout << "Add Zero Exception\n";
    }
    return 0;
}

/*
Exception handling can be incorporated in operator overloaded functions to handle invalid operations. Uer-defined exceptions may be thrown from the operator function and caught in the calling function. This ensures safe and controlled execution of overloaded operators.




*/
#include <iostream>
using namespace std;

class complex
{
    float x, y;
    public:
        complex(){ }; //default constructor 
        complex(float a)
        {
            x = y = a;
        }
        complex(float real, float imag)
        {
            x = real;
            y = imag;
        }
        friend complex sum (complex, complex);
        friend void show(complex);
};
complex sum (complex c1, complex c2)
{
    complex c3;
    c3.x = c1.x + c2.x;
    c3.y = c1.y + c2.y;
    return c3;
}
void show(complex c)
{
    cout << c.x << " +j " << c.y << "\n";
}

int main()
{
    complex A(1.7,4.7);
    complex B(1.9);
    complex C; //for this
    C = sum(A,B);
    cout << "A = "; show(A);
    cout << "B = "; show(B);
    cout << "C = "; show(C);

    complex P, Q, R;
    P = complex(1.8,9.2);
    Q = complex(3.4);
    R = sum(P,Q);
    show(R);
    return 0;
}
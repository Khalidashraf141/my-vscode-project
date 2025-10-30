/*
-Write a program to perform mathematical operations on complex numbers using unary and binary operator overloading
🧠 Concept
--- A complex number has two parts:
= real + imaginary*i

We'll make a Complex class that supports:
    -Binary operators:
    -> +,- -> add and subtract two complex numbers

    -Unary operator:
    -> - (negation) --> changes sign of both real and imaginary parts

*/

#include <iostream>
using namespace std;

class Complex
{
    float real;
    float imag;

public:
    // Default and parameterized constructor
    Complex(float r = 0, float i = 0)
    {
        real = r;
        imag = i;
    }

    // Display function
    void display()const
    {
        if(imag>=0)
        {
            cout << real << " + " << imag << "i" << "\n";
        }else{
            cout << real << " - " << -imag << "i" << "\n";
        }
    }


    //---------------- Binary Operator Overloading-------------
    Complex operator+(const Complex &c) const{
        return Complex(real + c.real, imag + c.imag);
    }

    Complex operator-(const Complex &c)const{
        return Complex(real - c.real, imag - c.imag);
    }

    //------------------Unary Operator Overloading-------------
    Complex operator-()const{
        return Complex(-real,-imag);
    }
};

int main()
{
    Complex c1(3,4);
    Complex c2(1,-2);

    cout << "c1 = ";
    c1.display();
    cout << "c2 = ";
    c2.display();

    // Binary + operator
    Complex sum = c1 + c2;
    cout << "\nSum = ";
    sum.display();

    // Binary - operator
    Complex diff = c1 - c2;
    cout << "Difference = ";
    diff.display();

    // Unary - Operator
    Complex neg = -c1;
    cout << "Negation of c1 = ";
    neg.display();

    return 0;
}
//TODO:PRACTICE


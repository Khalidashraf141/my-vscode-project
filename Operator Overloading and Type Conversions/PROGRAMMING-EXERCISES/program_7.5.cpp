/*
Define two classes Polar and Rectangle to represent points in the polar and rectangle systems. Use conversion routines to convert from one system to the other.
*/
#include <iostream>
#include <cmath>
using namespace std;

class Rectangle; //forward declaration

class Polar
{
    float r; // radius
    float a; // angle (in radians)
public:
    Polar(): r(0), a(0) {}
    Polar(float radius, float angle): r(radius), a(angle){}

    // conversion to Rectangle
    operator Rectangle();

    void display()const{
        cout << "Polar -> Radius = " << r << ", Angle = " << a << " radians\n";
    }

    float getR() const {return r;}
    float getA() const {return a;}
};

class Rectangle
{
    float x, y;
public:
    Rectangle(): x(0), y(0) {}
    Rectangle(float xval, float yval): x(xval), y(yval){}

    // conversion to Polar
    operator Polar()
    {
        float r = sqrt(x * x + y * y);
        float a = atan2(y,x); //atan2 handles all quadrants
        return Polar(r,a);
    }

    void display()const{
        cout << "Rectangle -> x = " << x << ", y = " << y << "\n";
    }

    float getX() const{return x;}
    float getY() const{return y;}
};

// Define Polar -> Rectangle conversions
Polar::operator Rectangle()
{
    float x = r * cos(a);
    float y = r * sin(a);
    return Rectangle(x,y);
}

int main()
{
    Polar p1(5,0.7854); //Polar point (r = 5, a = 45)
    Rectangle r1;

    // Convert Polar -> Rectangle
    r1 = p1; //automatic conversion using overloaded operator
    p1.display();
    r1.display();

    // Convert Rectangle -> Polar
    Rectangle r2(3,4);
    Polar p2;
    p2 = r2; // automatic conversion
    r2.display();
    p2.display();

    return 0;
}
//TODO:PRACTICE
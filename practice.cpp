#include <iostream>
#include <cmath>
using namespace std;

class Rectangle; //forward declaration

class Polar
{
    float r;
    float a;
public:
    Polar():r(0), a(0){}
    Polar(float radius, float angle):r(radius), a(angle){}

    operator Rectangle();

    void display(void)const{
        cout << "Polar -> Radius = "<< r << "Angle " << a << " radians" << "\n";
    }

    float getR()const{return r;}
    float getA()const{return a;}
};

class Rectangle
{
    float x;
    float y;
public:
    Rectangle():x(0), y(0){}
    Rectangle(float xval, float yval):x(xval), y(yval){}

    operator Polar(){
        float r = sqrt(x*x + y*y);
        float a = atan2(y,x);
        return Polar(r,a);
    }

    void display()const{
        cout << "Rectangle -> x = " << x << ", y = " << y << "\n";
    }

    float getX()const{return x;}
    float getY()const{return y;}
};

Polar::operator Rectangle()
{
    float x = r*cos(a);
    float y = r*sin(a);
    return Rectangle(x,y);

}

int main()
{
    Polar p1(5,0.7854);
    Rectangle r1;
    p1 = r1;
    p1.display();
    r1.display();

    return 0;
}
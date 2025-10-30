//!Out of Programming Exercises Question
//?Convert Polar to Cartesian 
//?Convert Cartesian to Polar
#include <iostream>
#include <cmath>
using namespace std;

class Polar
{
    float r; // radius
    float a; // angle in radians
public:
    //Default constructor
    Polar() : r(0), a(0) {}

    //Parameterized constructor (polar values)
    Polar(float radius, float angle)
    {
        r = radius;
        a = angle;
    }

    // Function to set Polar coordinates using Cartesian (x, y)
    void setFromCartesian(float x, float y)
    {
        r = sqrt(x*x + y*y); //formula: r = root(x*x + y*y)
        a = atan(y/x);       //formula: a = atan(y/x)
    }

    // Function to convert Polar -> Cartesian
    void toCartesian(float &x, float &y)
    {
        x = r* cos(a);
        y = r* sin(a);
    }

    void display()
    {
        cout << "Radius = " << r << ", Angle = " << a << " radians\n";
    }
};

int main()
{
    Polar p1(5,0.7854); // Polar point (r = 5, a = 45d = 0.7854 rad)
    float x, y;

    //!Convert to Cartesian (polar to cartesian)
    p1.toCartesian(x,y);
    cout << "Cartesian Coordinates: x = " << x << ", y = " << y << "\n";

    //!Create another Polar object from Cartesian (cartesian to polar)
    Polar p2;
    p2.setFromCartesian(x,y);
    p2.display();

    return 0;
}
//TODO:PRACTICE
#include <iostream>
#include <cmath>
using namespace std;

class Polar
{
    double radius;
    double angle; // in radians
public:
    Polar():radius(0), angle(0){}
    Polar(double r, double a):radius(r), angle(a){}

    Polar operator +(const Polar &x)const
    {
        double x1 = radius * cos(angle);
        double y1 = radius * sin(angle);

        double x2 = x.radius * cos(x.angle);
        double y2 = x.radius * sin(x.angle);

        // Add rectangular components
        double s = x1 + x2;
        double k = y1 + y2;

        // Convert result back to polar from
        double r = sqrt(s*s + k*k);
        double a = atan2(k,s);

        return Polar(r,a);
    }

    void display(void)const
    {
        cout << "Radius = " << radius << ", Angle = " << angle << " radians" << "\n";
    }
};

int main()
{
    Polar p1(5,M_PI/4); // radius 5, 45 degrees
    Polar p2(3,M_PI/3); // radius 3, 60 degrees

    cout << "First Polar Coordinates: ";
    p1.display();

    cout << "Second Polar Coordinates: ";
    p2.display();

    Polar p3 = p1 + p2;
    cout << "\nAfter Addition:\n";
    p3.display();

    return 0;
}
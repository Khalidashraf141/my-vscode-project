// TOPIC: Unary Operator Overloading in C++

// POINTS
// 0. Operator overloading works with {class/struct}.
// 1. Unary operator overloading needs only one operand.

#include <iostream>
using namespace std;

class Point 
{
    int x;
    int y;
public:
    Point(int x = 0, int y = 0):x{x}, y{y} {}
    void print(void)
    {
        cout << "x: " << x << " y: " << y << "\n";
    }

    Point operator -()
    {
        return Point (-x,-y);
    }
};
int main()
{
    Point p1(-1,2), p2;
    p1.print();
    p2.print();
    Point p3 = -p1;
    p3.print();
    return 0;
}


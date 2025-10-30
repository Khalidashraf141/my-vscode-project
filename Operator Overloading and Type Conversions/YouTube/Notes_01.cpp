// TOPIC:
// Operator Overloading In C++

//NOTES:
// 1. In C++ it is possible to change the behaviour of operators. (+,-,*......)
// 2. But we can change the behaviour for use defined types (class, struct) only.

#include <iostream>
using namespace std;

class Point
{
    int x;
    int y;
public:
    //default constructor
    // Point(int x = 0, int y = 0)
    // {
    //     x = x;
    //     y = y;
    // } This is wrong because both parameters names (x and y) are the same as the data members(x and y) so the parameters hide the member variables inside the constructor
    //we can fix it with the use of this->

    Point (int x = 0, int y = 0)
    {
        this->x = x;
        this->y = y;   //this-> it refer to the data memebers 
                        /*
                        so the assignments are:
                        data member x = parameter x;
                        data member y = parameter y;
                        
                        */
    }

    Point operator + (const Point& rhs)
    {
        Point p;
        p.x = x + rhs.x;
        p.y = y + rhs.y;
        return p;
    }

    Point operator - (const Point& rhs)
    {
        Point p;
        p.x = x - rhs.x;
        p.y = y - rhs.y;
        return p;
    }

    Point add (const Point& rhs)
    {
        Point p;
        p.x = x + rhs.x;
        p.y = y + rhs.y;
        return p;
    }

    void print(void)
    {
        cout << "x: " << x << " y: " << y << "\n";
    }
};

int main()
{
    Point p1(1,2), p2(5,3);
    Point p3 = p1 + p2;
    Point p4 = p3 - p1;
    Point p5 = p1.add(p4);
    cout << "P5: ";
    p5.print();
    cout << "\nP4: ";
    p4.print();
    cout << "\nP3: ";
    p3.print();

    return 0;
}

//POINTS
//1 . if we use them our program becomes more intutive 

//There are few operators we can't overload
// A. ::
// B. ?:
// C. .
// D. *
// E. sizeof
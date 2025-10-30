/*This is program defines a class called Point that stores the x and y coordinates of a point. The class uses parameterized constructor for initializing the class objects*/
#include <iostream>
using namespace std;

class Point
{
    int x, y;
    public:
        Point(int a, int b) //inline parameterized constructor definition
        {
            x = a;
            y = b;
        }
        void display(void)
        {
            cout << "("<<x<<","<<y<<")\n";
        }
};

int main()
{
    Point P1(10,20);
    Point P2(2,3);
    cout <<"Point P1 = ";
    P1.display();
    cout << "Point P2 = ";
    P2.display();

    return 0;
}
/*
-Create a class FLOAT that contains one float data member.
Overload all the four arithmetic operators so that they operate on the objects of FLOAT.
*/
#include <iostream>
using namespace std;
class FLOAT
{
    float a;
public:
    FLOAT():a(0.0f){}
    FLOAT(float x):a(x){}

    // Overload + operator
    FLOAT operator +(const FLOAT &n)
    {
        return FLOAT(a + n.a);
    }
    
    // Overload - operator
    FLOAT operator - (const FLOAT &n)
    {
        return FLOAT(a - n.a);
    }

    // Overload * operator
    FLOAT operator * (const FLOAT &n)
    {
        return FLOAT(a * n.a);
    }

    // Overload / operator
    FLOAT operator / (const FLOAT &n)
    {
        return FLOAT (a / n.a);
    }

    void display(void)
    {
        cout << "The value is: " << a << "\n";
    }

};

int main()
{
    FLOAT obj1(10), obj2(2.5), obj3;
    obj3 = obj1 + obj2;
    obj3.display();
    obj3 = obj1 - obj2;
    obj3.display();
    obj3 = obj1 * obj2;
    obj3.display();
    obj3 = obj1 / obj2;
    obj3.display();

    return 0;


}
//TODO:PRACTICE
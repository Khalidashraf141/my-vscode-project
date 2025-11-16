/*
Run the above program with the following modifications:
    (a) Remove the definition of display_are() form one of the derived classes.
    (b) In addition to the above, declare the display_area() as virtual in the base class shape.
*/
/*
Create a base class called shape. Use this class to store two double type values that could be used to compute the area of figures. Derive two specific classes called triangle and rectangle from the base shape. Add to the base class
a member function get_data() to initialize base class data members and another member function display_area() to compute and display the area of figures. Make display_area() as a virtual function and redefine this function in the derived classes to suit their requirements.

Using these three classes, design a program that will accept dimensions of a triangle or a react angle interactively, and display the area

Remember the two values give as input will be treated of two sides in the case of rectangles, and as base and height in the case of triangles, and used as follows:
*/
#include <iostream>
#include <cmath>
using namespace std;

class Shape
{
protected:
    float length;
    float width;
public:
    void get_data(float l, float w = 0)
    {
        length = l;
        width  = w;
    };
    virtual void display_area() = 0;
};

class Rectangle : public Shape
{
public:
    Rectangle(){ };
    Rectangle(float l, float w)
    {
        get_data(l,w);
    }
    void display_area()override
    {
        cout << "Area of Rectangle: " << length*width << endl;
    }
};

class Triangle : public Shape
{
    public:
        Triangle(){ }
        Triangle(float b, float h)
        {
            get_data(b,h);
        }
        void display_area()override
        {
            cout << "Area of Triangle: " << 0.5*length*width << endl;
        }
};

class Circle : public Shape
{
    public:
        Circle(){ }
        Circle(float radius)
        {
            get_data(radius);
        }
        // void display_area()override{
        //     cout << "Area of Circle: " << M_PI*length*length <<endl; //!according to the question we delete one display_are() so now what happen 
        // }
        /*
        NOW:
            we know that display_area() in base is virtual -> Correct
            ❌ but Circle CANNOT be created because it become abstract class and we
            cannot make object of abstract class 
             !error: cannot declare variable 'c' to be of abstract type 'Circle'       
             Circle c;
            ^
            .\program_9.1.cpp:55:7: note:   because the following virtual functions are pure within 'Circle': 
            we got this error
        */
};

int main()
{
    Shape *ptr;
    Rectangle r;
    Triangle t;
    // Circle c; ❌ WRONG - cannot create object of abstract class
    ptr = &r;
    r.get_data(10,10);
    r.display_area();
    ptr = &t;
    ptr->get_data(4,14);
    ptr->display_area();

    // ptr = &c;         ❌
    // c.get_data(2);    ❌
    // c.display_area(); ❌
    return 0;
}
//for improvement https://chatgpt.com/share/691928e3-578c-800e-a3be-bcee6498ebee
//file:///C:/Users/zeros/Downloads/pointer_dataTypesError.pdf

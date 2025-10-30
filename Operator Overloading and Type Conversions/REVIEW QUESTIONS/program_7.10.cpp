/*
We have two classes X and Y. If a is an object of X and b is an objectt of Y ans we want to say a = b, produce the conversion to be used with relevant place of use
*/

//Option 1: Conversion Consturctor in X - 
//-> X can create object using object of Y.

#include <iostream>
using namespace std;

class Y
{
    int data;
public:
    Y(int d){data = d;}
    int getData(){return data;}
};

class X
{
    int value;
public:
    X(){}

    //conversion constructor: converts Y -> X
    X(Y obj)
    {
        value = obj.getData();
    }

    void display()
    {
        cout << "Value in X: " << value << "\n";
    }
};

int main()
{
    Y b(10);
    X a;
    
    a = b; // Works because X(Y) constructor is defined
    a.display();

    return 0;
}

//TODO: PRACTICE AND UNDERSTAND
#include <iostream>
using namespace std;

class B;

class A
{
    int x;
    public:
    void setdata(int d)
    {
        x = d;
    }
    void display(void)
    {
        cout << x << "\n";
    }

    friend void add (A &, B);
};

class B
{
    int x;
    public:
    void setdata(int d) 
    {
        x = d;
    }
    void display(void)
    {
        cout << x << "\n";
    }
    friend void add (A & , B);
};

void add(A & ob_A, B ob_b)
{
    ob_A.x+=ob_b.x; //a ke andar add hua hai
}

int main()
{
    A a;
    B b;
    a.setdata(10);
    b.setdata(10);
    add(a,b);
    a.display(); //20
    b.display(); //10 
    return 0;
}
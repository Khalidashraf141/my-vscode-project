#include <iostream>
using namespace std;

class B
{
    int a; // private, not inheritable
public:
    int b; // public, ready for inheritance

    void set_ab();
    int get_a(void);
    void show_a(void);
};

class C : public B
{
    int c;
public:
    void mul(void);
    void display(void);
};


//------------------------------------------------------------------------------------
void B :: set_ab(void)
{
    a = 5, b = 10;
}

int B :: get_a()
{
    return a;
}

void B :: show_a()
{
    cout << "a = " << a << "\n";
}

void C :: mul()
{
    c = b * get_a();
}
void C :: display()
{
    cout << "a = " << get_a() << "\n";
    cout << "b = " << b << "\n";
    cout << "c = " << c << "\n\n";
}

int main()
{
    C c;
    c.set_ab();
    c.mul();
    c.show_a();
    c.display();
    c.b = 20;
    c.mul();
    c.display();
}
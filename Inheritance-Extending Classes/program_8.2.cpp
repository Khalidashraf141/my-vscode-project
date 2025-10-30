#include <iostream>
using namespace std;

class B
{
    int a;      //private not inheritable
public:
    int b;      //public ready for inheritance
    void get_ab();
    int get_a(void);
    void show_a(void);
};

class D : private B //private derivation
{
    int c;
public:
    void mul(void);
    void display(void);
};

void B :: get_ab(void)
{
    cout << "Enter values for a and b: ";
    cin >> a >> b;
}

int B :: get_a()
{
    return a;
}

void B :: show_a()
{
    cout <<"a = " << a << "\n";
}

void D :: mul()           
{
    get_ab();
    c = b * get_a();    // 'a' cannot be used directly
}

void D :: display()
{
    show_a();          // outputs value of 'a'
    cout << "b = " << b << "\n"
        <<"c = " << c << "\n\n";
}

int main()
{
    D d;
    // d.get_ab(); WON'T WORK
    d.mul();
    // d.show_a(); WON'T WORK
    d.display();
    // d.b = 20; WON'T WORK; B HAS BECOME PRIVATE
    d.mul();
    d.display();

    return 0;
}
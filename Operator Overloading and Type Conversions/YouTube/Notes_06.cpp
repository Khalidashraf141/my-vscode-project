// TOPIC: Overload Type Cast In C++

// POINTS:
// 1. There are no need to typecast implicit data types (Compile Knows How to Do That)
// 2. User defined data types needs this overloading.

#include <iostream>
using namespace std;
double dollarToRupeeExchangeRate()
{
    return 71.5;
}

class Rupee
{
    double rupee;
public:
    Rupee(double d = 0): rupee{d} {}
    void print() {cout << rupee << "\n";}
};

class Dollar
{
    double dollar;
public:
    Dollar(double d = 0): dollar{d} {}
    void print () {cout << dollar << "\n";};

    operator Rupee()
    {
        return Rupee(dollar*dollarToRupeeExchangeRate());
    }
};

int main()
{
    Dollar d(10);
    Rupee r;
    r = d;
    d.print();
    r.print();

    return 0;
}
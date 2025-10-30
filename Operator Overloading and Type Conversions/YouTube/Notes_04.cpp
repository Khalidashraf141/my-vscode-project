// TOPIC: << & >> Operator Overloading In C++
// << extraction operator
// >> stream insertion

// POINTS:
// 1. When we need overload << & >> ?
// cout << (user defined type) OR cin >> (user defined type).
// 2. It can't be class member function , you have to make it friend function of your class.

#include <iostream>
using namespace std;

class Test
{
    int x;
public:
    Test(int x = 0):x{x} {}
    friend istream& operator >> (istream& input, Test& obj);
    friend ostream& operator << (ostream& output, Test& obj);
};

istream& operator >> (istream& input, Test& obj)
{
    input >> obj.x;
    return input;
}

ostream& operator << (ostream& output, Test& obj)
{
    output << obj.x << "\n";
    return output;
}

int main()
{
    Test t;
    cin >> t;
    cout << t;
    return 0;
}
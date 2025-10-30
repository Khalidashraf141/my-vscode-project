/*
-Write a program to compare two fractional numbers by overloading the relational operator (==,!=,>=,<=)
*/

#include <iostream>
using namespace std;

class Fraction
{
    int num; //numerator
    int dem; //denominator
public:

    //Constructor
    Fraction(int n = 0, int d = 1)
    {
        num = n;
        dem = d != 0? d: 1; // prevent division by zero
    }

    // Display function
    void display()const{
        cout << num << "/" << dem;
    }

    // Overload ==
    bool operator==(const Fraction &f) const{
        return (num * f.dem == dem * f.num);
    }

    // Overload !=
    bool operator!=(const Fraction &f)const{
        return !(*this == f);
    }

    // Overload >=
    bool operator>=(const Fraction &f)const{
        return (num * f.dem >= dem * f.num);
    }

    // Overload <=
    bool operator<=(const Fraction &f)const{
        return (num * f.dem <= dem * f.num);
    }
};

int main()
{
    Fraction f1(3,4);
    Fraction f2(1,2);

    cout << "Comparing ";
    f1.display();
    cout << " and ";
    f2.display();
    cout << ":\n";

    cout << "f1 == f2 ?" << (f1 == f2? "True" : "False") << "\n";
    cout << "f1 != f2 ?" << (f1 != f2? "True" : "False") << "\n";
    cout << "f1 >= f2 ?" << (f1 >= f2? "True" : "False") << "\n";
    cout << "f1 <= f2 ?" << (f1 <= f2? "True" : "False") << "\n";
    return 0;
}
//TODO:PRACTICE
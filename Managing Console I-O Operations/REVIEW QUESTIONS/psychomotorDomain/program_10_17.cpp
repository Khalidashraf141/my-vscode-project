/*
Discuss the syntax for creating user-defined manipulators. Design specifically a single manipulator to provide the following ouput specifications for printing float values.
(a) 10 columns width
(b) Right-justified
(c) Two digits precision
(d) Filling of unused place with*
(e) Trailing zeros shown
*/
#include <iostream>
#include <iomanip>
using namespace std;

ostream & symbol(ostream &output)
{
    // right justification
    output.setf(ios::right, ios::adjustfield);

    // always show decimal point and trailing zeros
    output.setf(ios::showpoint);

    // fixed decimal places
    output.setf(ios::fixed, ios::floatfield);

    // fill unused space with '*'
    output << setfill('*');

    // width = 10
    output << setw(10);

    // precision = 2 digits after decimal
    output << setprecision(2);

    return output;

}


int main()
{
    float num = 202.000;
    cout << symbol << num;
    return 0;
}
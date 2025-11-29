/*
Perform without an error and find the result of the following program segment:
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    for(double i = 0.25; i <= 1.0; i = i+0.25)
    {
        cout.precision(5);
        cout.width(7);
        cout << i;
        cout.width(10);
        cout << i*i << "\n";
    }
    cout << setw(10) << "TOTAL = " << setw(20) << setprecision(2) << 1234.567 << endl;

    return 0;
}
/*
🔥 Important Point:
C++ switches to scientific format automatically when the number is too large to display in normal form with the requested significant digits.
-This is automatic formatting behavior

!Remember
    Explicit = you tell C++ exactly what to do.
    Implicit = C++ decides automatically based on rules
*/
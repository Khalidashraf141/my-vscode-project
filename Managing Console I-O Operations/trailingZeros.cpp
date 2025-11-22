/*
Displaying Trailing Zeros and Plus Sign
Some format flags in C++ do not belong to any named bit-field.
    -These flags are independent, meaning:
        -They do not fall under basefield, floatfield, or adjustfield
        -They are not mutually exclusive
        -They can be set or cleared independently
        -They use the single-argument form of setf():

    These flags do NOT have a bit-field -> so no second argument required.
    - They do NOT affect each other.
    - Can be turned ON/OFF at any time:
    syntax:
        cout.setf(ios::showpos); turn ON
        cout.unsetf(ios::showpos); turn OFF

Meaning of They are not mutually exclusive
it means:
    You can turn ON more than one of these flags at the same time.
    They do NOT conflict with each other.
!Unlike some flags that cannot coexist (like left and right)
these independent flags can be active together.

Mutually Exclusive example
if you set:
    syntax:
        cout.setf(ios::left, ios::adjustfield)
        cout.setf(ios::right, ios::adjustfield)
    The second one automatically cancels the first
    These are mutually exclusive.


!NOT mutually exclusive = they can work together, they don't cancel each other.
so flags like showpoint showpos showbase (all can be turned on (simultaneously).
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    cout.setf(ios::showpoint); //forces the ouput always show trailing zeros
    cout.setf(ios::showpos);//show a + sign before positive numbers.
    cout.precision(3);//controls number of digits after decimal when using fixed
    cout.setf(ios::fixed, ios::floatfield);//precision(3) + fixed -> 3 digits after decimal
    cout.setf(ios::internal,ios::adjustfield);// pad between sign and number
    //spaces come after the sign but before the number.
    //!This only works when width() is larger then the printed value.
    cout.width(10);
    cout << 275.5 << "\n";
    return 0;
/*
    output:
        +275.500 = 8 characters 
        we need width 10 so 2 spaces must be added after sign:
    
?if we not use precision
and use the (ios::fixed, ios::floatfield);
default precision = 6 digits after decimal
    output:
        275.500000
        because:
        -fixed -> decimal places controlled by precision
        -Default precision is 6



*/
}
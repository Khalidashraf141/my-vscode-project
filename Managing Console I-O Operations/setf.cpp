/*
⭐ 1. What is setf()?
-setf() means set flag.
it is used to change the formatting behavior of ouput like cout.

    stream.setf(flag); -one-argument version
    stream.setf(flag,mask) -tow-argument version


⭐ 2. Why do we need two versions?
✔️ One-argument:
    - just turns a flag ON, but does not remove conflicting flags.
✔️ Two-argument:
    - sets a flag AND clears all other flags in the same category (mask).
    This gives correct and predictable formatting.

⭐ Important MASKS (Categories of Flags)
(1) iso::adjustfield -> Alignment group
Contains:
    - ios::left
    - ios::right
    - ios::internal
(2) iso::floatfield -> Floating-point format group
Contains:
    - ios::scientific
    - ios::fixed
(3) ios::basefield -> Number base group
    - ios::dec
    - ios::hex
    - ios::oct

⭐ 4 Why Mask Needed? (very important)
cout.setf(ios::left);
cout.setf(ios::right);
!(Both flags stay ON -> unpredictable output)

cout.setf(ios::right, ios::adjustfield);
!(This clears left and internal before applying right)

*/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    cout << "WITHOUT MASK:\n";
    cout.setf(ios::right); // right flag ON
    cout.width(10);
    cout << "Hello" << endl;

    cout.setf(ios::left); //left ON but right still ON!
    cout.width(10);
    cout << "Hello" << endl; // unpredictable ouput


    cout << "\nWITH MASK:\n";
    cout.setf(ios::right, ios::adjustfield);
    cout.width(10);
    cout << "Hello" << endl;

    cout.setf(ios::left, ios::adjustfield);
    cout.width(10);
    cout << "Hello" << endl;

    cout << "\n\n";

    cout << "Scientific and Fixed Notation\n";
    double x = 1234.5689;

    cout.setf(ios::scientific, ios::floatfield);
    cout << x << endl;

    cout.setf(ios::fixed, ios::floatfield); // By default: digits after decimal
    cout << x << endl;

    cout << "\n\n";
    cout << "\nNumber Base (dec/hex/oct)\n";

    int n = 16;

    cout.setf(ios::dec, ios::basefield);
    cout << "Decimal : " << n << endl;
    /*
    You know decimal system-digits go from 0 to 9.
    Decimal: 255
    means:
    2x100 + 5x10 + 5x1 = 255

    Decimal: 10
    means:
    1x10 + 0x1 = 10

    */

    cout.setf(ios::hex, ios::basefield);
    cout << "Hex     : " << n << endl;
    /*
    Hexadecimal (Base 16)
    Digits allowed:
    - 0 1 2 3 4 5 6 7 8 9 A B C D E F
    Where:
    A = 10
    B = 11
    C = 12
    D = 13
    E = 14
    F = 15

    Convert 255 to hexadecimal:
    Divide by 16:
    255 ÷ 16 = 15 remainder 15
    15 in hex = f

    so:
    Hex ff = (15 x 16^1) + (15 x 16^0)
           = 240 + 15
           = 255
    That's why hex ouput is:
    ff
    


    Convert 10 to Hex
    10 ÷ 16 = 0 remainder 10
    10 -> A
    Decimal 10 -> Hex A


    Convert 15 to Hex
    15 ÷ 16 = 0 remainder 15
    15 -> F
    Decimal 15 -> Hex F

    Convert 16 to Hex
    16 ÷ 16 = 1 remainder 0 
    1 x 16^1 + 0 x 16^0
    16 -> Hex 10
    Decimal 16 -> Hex 10


    Convert 26 to Hex
    26 ÷ 16 = 1 remainder 10
    10 -> A
    so hex = 1A
    Decimal 26 -> Hex 1A


    step 1:
    Convert 2748 to Hex 
    2748 ÷ 16 = 171 remainder 12 -> C

    step 2:
    171 ÷ 16 = 10 remainder 11 -> B

    step 3:
    10 ÷ 16 = 0 remainder 10 -> A
    read from bottom to top:
    ABC
    Decimal 2748 -> Hex ABC
    */







    cout.setf(ios::oct, ios::basefield);
    cout << "Octal   : " << n << endl;
    /*
    Octal (Base 8)
    Convert 10 to octal
    10 ÷ 8 = 1 remainder 2
    1 ÷ 8 = 0 remainder 1

    bottom to top -> 12 octal

    convert 20 to Octal
    20 ÷ 8 = 2 remainder 4
    2 ÷ 8 = 0 remainder 2

    read bottom to top: 24 octal

    convert 25 to Octal
    25 ÷ 8 = 3 remainder 1
    3 ÷ 8 = 0 remainder 3

    read bottom to top: 31 octal

    convert 50 to octal
    50 ÷ 8 = 6 remainder 2
    6 ÷ 8 = 0 remainder 6

    read bottom to top: 62

    convert 100 to octal
    100 ÷ 8 = 12 remainder 4
    12 ÷ 8 = 1 remainder 4
    1 ÷ 8 = 0 remainder 1

    read bottom to top: 144

    
    
    
    */
    cout <<"\n\nKeeps the sign on the left\n";
    cout.setf(ios::dec, ios::basefield); // RESET TO DECIMAL
    cout.setf(ios::internal, ios::adjustfield);
    cout.width(10);
    cout << -56;

    return 0;
}
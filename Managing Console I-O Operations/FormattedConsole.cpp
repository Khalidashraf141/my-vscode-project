/*
Formatted Console I/O in C++
-Formatted I/O means controlling the appearance and structure of input/ouput, such as width,
precision, alignment, and number format.

    C++ provides this through:
        1. Operators (<<, >>)
        2. ios class functions
        3. Manipulators (setw, setprecision, left, right, hex, dec, ect.)

*/

#include <iostream>
#include <cstring>
#include <iomanip>
#include <limits>
using namespace std;

int main()
{
    // 1. Formatted Ouput Using Insertion Operator (<<)
    int x = 25;
    double y = 3.14;
    cout << "x = " << x <<", y = " << y;
    /*
    !Notes
        automatically format values
        Converts different data types
        Most basic method for formatted ouput

    */

    // 2. Formatted Input Using Extraction Operator(>>)
    int a;
    float b;
    cin >> a >> b;
    /*
    !Notes
        skips whitespace
        stops reading at first whitespace
        useful for fast input
    */

    //3. Formatted I/O using ios functions
    /*
        These allow fine control over formatting
        3.1 width(int w)
        -> sets minimum field width for the next ouput only.
    */
   cout << "\n\n";
    cout.width(10);
    cout << 123;
    //Notes: affects only next insertion - if width < data length -> no effect

    //3.2 precision(int p)
    /*
        -> Sets number of digits displayed for floating point.
        works like rounding
        affects all future float output unless changed
    */
   cout << "\n\n";
   cout.precision(4);
   cout << 33.43213242;


   //fill(char c)
   /*
    -> Fills empty width with given character
   */
    cout << "\n\n";
    cout.fill('*');
    cout.width(10);
    cout << 25;



    cout << "\n\n";
    /*
    3.4 setf() -> set formatting flags
    3.5 unsetf() -> remove formatting flags
    */
   cout.setf(ios::showpos); //show + sign
   cout << 10;
   cout.unsetf(ios::showpos);
   
   cout <<"\n\n";

   int z = 255;
   cout << hex << x << endl;
   cout << dec << x << endl;
   cout << oct << x << endl;

   cout << left << setw(10) << 100;
   return 0;
}
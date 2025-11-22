/*
Attention:-
    !By default, C++ print floating-point number with 6 significant digits,
    not six digits after the decimal


*/

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    cout << "Default" << endl;
    cout << 123.456789 << endl;
    //Output:123.457 (6 significant digits -> rounded)


    cout << 0.00123456 << endl;
    //Output:0.00123456


    cout<<"\n\n\n";



    cout << "Precision set to 3 digits\n\n";
    cout.precision(3);

    cout.width(10);
    cout << "VALUE";
    cout.width(15);
    cout << "SQRT_OF_VALUE" << "\n";

    for(int n = 1; n <= 5; n++)
    {
        cout.width(8);
        cout << n;
        cout.width(13);
        cout << sqrt(n) << "\n";
    }

    cout << "\nPrecision set to 5 digits \n\n";
    cout.precision(5); //precision parameter changed
    cout << "sqrt(10) = " << sqrt(10) << " (default setting)\n";

    cout << "\n\n";

    //⭐ Two simple rules
    /*
    1️⃣ If you use only setprecision(n)
     - C++ prints n digits total (counts digits before and after decimal)
    */
   cout << setprecision(4) << 12.3456;
   cout << "\n";
//output: 12.35

    //2️⃣ if you use fixed + setprecision(n)
    /*
     -C++ prints n digits after the decimal point.
    */
   cout << fixed << setprecision(4) << 12.458393;

//output: 12.4583

    //🎯 The EASIEST WAY to remember
    /*
    ✔️setprecision(n) -> n digits TOTAL
    ✔️fixed + setprecision(n) -> n digits AFTER decimal
    */

    cout << "\n\n";
    cout.precision(2);
    cout.width(5);
    cout << 1.2345;
    return 0;

}

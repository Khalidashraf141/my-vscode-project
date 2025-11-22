/*
fill()
    - sets the character used to pad empty spaces when formatting ouput.
!   - stays in effect until changed again.

?Why banks use padding
ans-> Banks print cheque amounts with special characters filling the empty space so people cannot add extra digits

Example
    #####500.0
    No one can add amount to the left

*/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    double amount = 500.00;
    cout << "Cheque Amount (padded):" << endl;
    //set fill character
    cout << setfill('*');

    cout <<setw(15) << fixed << setprecision(2) << amount << endl;

    cout << "\n\n";

    cout.fill('<');
    cout.precision(3);
    for(int n = 1; n<=6; n++)
    {
        cout.width(5);
        cout << n;
        cout.width(10);
        cout << 1.0 /float(n) << "\n";
        if(n == 3)
            cout.fill('>');
    }
    cout << "\nPadding changed \n\n";
    cout.fill('#');
    cout.width(15);
    cout << 12.34567 << '\n';
    return 0;
}
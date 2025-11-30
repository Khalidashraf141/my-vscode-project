/*
Write a program to read list containing item name, item code, and cost interactively and produce a three column output as show below
Note that the name and code are left-justified and the cost is right-justified with a precision of two digits.Trailing zeros are shown

program 10.2 modify the above program to fill the unused spaces with hyphens
*/
#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

int main()
{
    string name;
    int code;
    float cost;

    // Set formatting for cost
    cout.fill('-');
    cout << fixed << showpoint << setprecision(2);

    // Print table header
    cout << left << setw(15) << "NAME"
         << left << setw(10) << "CODE"
         << right << setw(10) << "COST" << endl;
    
    // read 3 items 
    for(int i = 0; i < 3; i++)
    {
        // cout << "\nEnter item name: ";
        getline(cin,name);

        // cout << "Enter item code: ";
        cin >> code;

        // cout << "Enter cost: ";
        cin >> cost;
        cin.ignore(numeric_limits<streamsize>::max(),'\n');

        // Print formatted row
        cout << left << setw(15) << name
             << left << setw(10) << code
             << right << setw(10) << cost << endl;
    }
    return 0;
}


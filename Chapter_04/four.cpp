//4.7-Write a function power() to raise a number m to a power n. The function takes a double value for m an dint value for n, and returns the result correctly. Use a default value of 2 for n to make the function to calculate squares when the argument is omitted. Write a main that gets the values of m and n from the user to test the function..
#include <iostream>
#include <cmath>
using namespace std;

double power(int m, int n = 2){
    return pow(m,n);
}

int main()
{
    double m;
    int n;
    char choice;

    cout << "Enter a number (m): ";
    cin >> m;
    cout << "Do you want to enter the power (y/n)";
    cin >> choice;
    if(choice == 'y' || choice == 'Y')
    {
        cout << "Enter the power (n): ";
        cin >> n;
        cout << m << " raised to " << n << " is " << power(m,n) << "\n";
    }
    else{
        cout << m << " square is " << power(m) << "\n";
    }
    return 0;
}
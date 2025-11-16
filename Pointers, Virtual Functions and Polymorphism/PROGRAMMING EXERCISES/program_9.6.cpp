//Question:- Write a program to calculate factorial of an integer using pointer to function concept
#include <iostream>
using namespace std;
//Function pointer meaning pointer variable that stores address of a function

//---------------------------------------
// FUNCTION TO CALCULATE FACTORIAL
//---------------------------------------

int factorial (int n)
{
    int fact = 1;
    for(int i = 1; i < n; i++)
    {
        fact *= i;
    }
    return fact;
}



int main()
{
    int num;
    cout << "Enter a number: ";
    cin >> num;

    //---------------------------------------
    // FUNCTION POINTER DECLARATION
    //---------------------------------------
    int (*fp)(int); //fp is a pointer to a function taking int & returning int

    fp = factorial; // storing address of factorial function

    //---------------------------------------
    // Calling factorial using the function pointer
    //---------------------------------------

    int result  = fp(num);

    cout << "Factorial = " << result << endl;

    return 0;
}

//note: function pointer  and pointe to function both are same (ex-> car and automobile)


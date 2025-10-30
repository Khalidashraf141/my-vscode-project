//4.8 Write a function that performs the same operation as that exericise 4.7 but takes an int value for m. Both the functions should have the same name. Write a main that calls both function. Use the concept of function overloading..
#include <iostream>
#include <cmath>
using namespace std;

int power(int m , int n){
    return pow(m,n);
}

double power(double m, int n = 2){
    return pow(m,n);
}

int main()
{
    cout << power(2,4) << "\n";
    cout << power(5.5);
    return 0;
}
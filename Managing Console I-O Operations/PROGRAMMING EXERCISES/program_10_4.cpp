/*
Write a program to find the value of e in the following series:
    e = 1 + 1/1! + 1/2! +......upto acc = 0.0001

*/
#include <iostream>
#include <iomanip>

int main()
{
    const long double acc = 0.0001L; // required accuracy
    long double sum = 1.0L; // start with first term = 1
    long double term = 1.0L; // current term(1/0! = 1)
    int n = 1; // next factorial index (1!, 2!, ....)

    // keep adding terms until the next term becomes smaller than accuracy
    while(true)
    {
        term = term/ n; // compute 1/n! using previous term
        if(term<acc) break; 
        sum+= term; // add term to total
        n++; // move to next factorial
    }

    //print the result
    std::cout << std::fixed << std::setprecision(6);
    std::cout << "Approximate value of e = " << sum << std::endl;
    std::cout << "Series computed until 1/" << (n-1) << "! >= " << acc << std::endl;

    return 0;
}
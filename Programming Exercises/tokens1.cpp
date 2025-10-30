#include <iostream>
#include <cmath>
using namespace std;

int main(){
    //practice this code
    double x, term, sum;
    int n = 1; //power of x in each term
    const double accuracy = 0.000001; //for ~0.0001% accuracy

    cout << "Enter x in radians: ";
    cin >> x;

    term = x; // first term is x
    sum = term;

    while(fabs(term)>accuracy){
        n +=2;
        term = -term * x * x/(n*(n-1));
        sum +=term;
    }
    cout << "Calculated sin(x) = " << sum << "\n";
    cout << "Using built-in sin(x) = " << sin(x) << endl;
    return 0;

    
}
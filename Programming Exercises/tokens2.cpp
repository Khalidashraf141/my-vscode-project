#include <iostream>
#include <cmath>
using namespace std;

int main(){
    //practice this code and maths
    double sum = 0.0, term;
    int n = 1;

    do{
        term = pow(1.0/n,n);
        sum += term;
        n++;
    }while (fabs(term/sum)*100>0.0001);

    cout.precision(10);
    cout << "Sum of series = " << sum << "\n";
    cout << "Number of term used =" << n-1 << "\n";
    return 0;

    
}
#include <iostream>
#include <cmath>
using namespace std;

int main(){
    double x, term,sum;
    int n =0;

    cout << "Enter x in radins: ";
    cin >> x;

    term = 1;
    sum = term;

    while (fabs(term/sum)*100>0.0001)
    {
        n++;
        term = -term * x * x /((2*n-1) * (2*n));
        sum += term;
    }
    cout.precision(10);
    cout << "cos("<< x <<") =" << sum << '\n';
    cout << "Actual cos("<< x <<")=" << cos(x) << "\n";
    return 0;
}
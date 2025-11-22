#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double x = 1234.56789;
    cout << scientific << x << endl;
    cout << scientific << setprecision(3)<< x << endl;
    return 0;
}
/*
output:
    1.234568e+03
How to read it-> 1.234568e+03
    Which means = 1.234568 x 10^3
    10^3 = 1000
?1.234568 x 1000 = 1234.568    
output:
    1.235e+03
How to read it-> 1.235e+03
    Which means = 1.235 x 10^3
    10^3 = 1000
?1.235 x 1000 = 1235

*/
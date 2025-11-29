/*identify the error in the following program if any:*/
#include <iostream>
using namespace std;
int main()
{
    float pi = 22.0/7.0;
    cout.fill('$');
    cout.width(10);
    cout.precision(2);
    cout << pi << "\n";
    return 0;
}
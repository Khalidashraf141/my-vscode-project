/*the static_cast operator is used for any standard conversion of data types*/
#include <iostream>
using namespace std;


int main()
{
    int m = 73;
    double x = static_cast<double>(m);
    char ch = static_cast<char>(m);
    cout << ch;
}
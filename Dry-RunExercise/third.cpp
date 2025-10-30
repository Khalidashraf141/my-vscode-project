//what  will happen when the following program is run?
//doubt
#include <iostream>
using namespace std;
int & fun (int &);
int main()
{
    int a = 5;
    fun(a) = a;
    cout << a << "\n";
    fun(a) = ++a;
    cout << a << "\n";
    fun(a) = a++;
    cout << a <<"\n";
    return 0;
}
int & fun (int &x)
{
    x++;
    return x;
}
//identify the error in the following program
#include <iostream>
using namespace std;

int sub(int a, int b = 20)  //default arguments should be left to right
{
    return a - b;
}
int main()
{
    int a = 100;
    int b = 200;
    int result;
    result = sub(a);
    cout << "Value 1 :" << result << "\n";
    result = sub(a,b);
    cout << "Value 2 :" << result << "\n";
    return 0;
}
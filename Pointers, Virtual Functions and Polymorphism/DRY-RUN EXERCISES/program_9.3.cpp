/*What will happen when the following program si run?*/
#include <iostream>
using namespace std;

void square(int * snum)
{
    cout << "Square of 10 is ";
    *snum *= *snum;
}

int main()
{
    int num = 20;
    square(&num);
    cout << num << endl;
    return 0;
}
/*Write a program to demonstrate function overloading*/
#include <iostream>
using namespace std;

int add(int a, int b)
{
    return a + b;
}

int add (int a, int b, int c)
{
    return a + b + c;
}

float add(float a, float b)
{
    return a + b;
}

int main()
{
    cout << "Add two integers: " << add(10,20) << endl;
    cout << "Add three integers: " << add(5, 10, 15) << endl;
    cout << "Add two floats: " << add(2.5f, 3.5f) << endl;

    return 0;
}
/*the suffix f is used to specify a floating-point literal as float; otherwise it is treated as double*/

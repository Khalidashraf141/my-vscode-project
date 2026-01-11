#include <iostream>
using namespace std;

namespace constants
{
    const int MAX = 100;
    const float PI = 3.14f;
    const double GRAVITY = 9.8;
}
int main()
{
    cout << "Max = " << constants::MAX << endl;
    cout << "PI = " << constants::PI << endl;
    cout << "GRAVITY = " << constants::GRAVITY << endl;

    return 0;
}
/*
    - :: is the scope resolution operator
    - It tells the compiler where the identifier belongs
*/
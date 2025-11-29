#include <iostream>
using namespace std;

int main()
{
    istream &in = cin;
    ostream &out = cout;

    int x;
    in.operator>>(x);
    out.operator<<(x);
    return 0;
}
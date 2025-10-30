//dry run
#include <iostream>
using namespace std;

class personal
{
    public:
    int p();
};

int personal :: p()
{
    return 1;
}

int main()
{   
    personal a;
    int (personal::*x)() = &personal::p; //pointer to member function
    cout << (a.*x)();
    return 0;
}
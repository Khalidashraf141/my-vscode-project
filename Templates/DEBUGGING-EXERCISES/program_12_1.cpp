/*12.1 Identify the error in the following program*/
#include <iostream>
using namespace std;
class Test
{
    int intNumber;
    float floatNumber;
public:
    Test()
    {
        intNumber = 0;
        floatNumber = 0.0;
    }
    int getIntNumber()
    // int getNumber()
    {
        return intNumber;
    }
    float getFloatNumber()
    // float getNumber()
    {
        return floatNumber;
    }
};

int main()
{
    Test objTes1;
    cout << objTes1.getIntNumber();
    cout << endl;
    cout << objTes1.getFloatNumber();
    return 0;
}
/*
The program is invalid because two member functions getNumber() are declared with identical parameters lists and differ only by return type, which is not allowed in C++.


*/
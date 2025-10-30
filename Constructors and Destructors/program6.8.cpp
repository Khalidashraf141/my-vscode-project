//Memory Allocation to an Object using Destructor
#include <iostream>
using namespace std;

class test
{
    int *a;
    public:
    test(int size)
    {
        a = new int[size];
        cout << "\n\nConstructor Msg: Integer array of size " << size <<" createed..";
    }
    ~test()
    {
        delete[] a;
        cout << "\n\nDestructor Msg: Freed up the memory allocated for integer array";
    }
};

int main()
{
    int s;
    cout << "Enter the size of the array..";
    cin >> s;
    cout << "\n\nCreating an object of test class..";
    test T(s);
    cout << "\n\nPress any key to end the program..";

    return 0;
}
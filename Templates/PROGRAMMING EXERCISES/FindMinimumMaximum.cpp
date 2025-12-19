/*12.1 Write a function template to find the minimum and maximum values by passing non-type arguments to the template*/

#include <iostream>
using namespace std;

// Function template with non-type parameters
template<int A, int B>
void findMinMax()
{
    if(A > B)
        cout << "Max = " << A << ", Min = " << B << endl;
    else
        cout << "Max = " << B << ", Min = " << A << endl;
}

int main()
{
    findMinMax<10,25>();
    findMinMax<40,15>();
    return 0;
}
#include <iostream>
using namespace std;

class arr
{
    int a[5];
public:
    arr(int *s)
    {
        for(int i = 0; i < 5; i++)
        {
            a[i] = s[i];
        }
    }

    //Overloading the subscript operator
    int operator [] (int k)
    {
        return a[k];
    }
};

int main()
{
    int x[5] = {1,2,3,4,5};
    arr A(x);
    for(int i = 0; i < 5; i++)
    {
        cout << A[i] << "\t"; //Using subscript operator to access the private arrya elements
    }
    return 0;
}
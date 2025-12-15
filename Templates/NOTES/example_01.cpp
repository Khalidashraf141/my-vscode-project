#include <iostream>
using namespace std;

class vector
{
    int *v;
    int size;
public:
    vector(int m)
    {
        size = m;
        v = new int[size];
        for(int i = 0; i < size; i++)
        {
            v[i] = 0;
        }
    }
    vector(int *a,int m)

    {
        size = m;
        v = new int[size];
        for(int i = 0; i < size; i++)
        {
            v[i] = a[i];
        }
    }
    int operator*(vector &y)
    {
        int sum = 0;
        for(int i = 0; i < size; i++)
        {
            sum += this->v[i] * y.v[i];
        }
        return sum;
    }
};

int main()
{
    int x[3] = {1,2,3};
    int y[3] = {4,5,6};

    vector v1(x,3);       // Creates a null vector of 3 integers
    vector v2(y,3);

    int R = v1 * v2;
    cout << "R = " << R;
    return 0;
}

/*
if we want to store float values using the vector class, replacing int with float would require redefining the entire class. The -template mechanism solves this problem by allowing the class to be written in a generic form, enabling it to work with different data types without rewriting the code.
*/
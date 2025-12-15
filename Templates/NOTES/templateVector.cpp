#include <iostream>
using namespace std;

template<class T>
class vector
{
    T* v;
    int size;
public:
    vector(int m)
    {
        size = m;
        v = new T[size];
        for(int i = 0; i < size; i++)
        {
            v[i] = 0;
        }
    }
    vector(T *a, int m)
    {
        size = m;
        v = new T[size];
        for(int i = 0; i < size; i++)
        {
            v[i] = a[i];
        }
    }
    T operator*(vector &y)
    {
        T sum = 0;
        for(int i = 0; i < size; i++)
        {
            sum+= this->v[i] * y.v[i];
        }
        return sum;
    }
};

int main()
{
    float x[3] = {1,2,3};
    float y[3] = {4.5,5.3,6.8};

    vector<float> v1(x,3);
    vector<float> v2(y,3);

    float R = v1 * v2;
    cout << "R = " << R;
    return 0;

}
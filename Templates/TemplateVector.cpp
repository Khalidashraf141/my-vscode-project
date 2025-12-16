#include <iostream>
using namespace std;

// Class template..........
template<class T>
class vector
{
    T* v;
    int size;
public:
    vector(int m);
    vector(T* a, int m);
    T operator*(vector &y);
};

//Member function templates.........
template<class T>
vector<T> :: vector(int m)
{
    v = new T[size = m];
    for(int i = 0; i < size; i++)
    {
        v[i] = 0;
    }
}

template<class T>
vector<T> :: vector(T* a, int m)
{
    v = new T[size = m];
    for(int i = 0; i < size; i++)
    {
        v[i] = a[i];
    }
}

template<class T>
T vector<T> :: operator*(vector &y)
{
    T sum = 0;
    for(int i = 0; i< size; i++)
    {
        sum += this->v[i] * y.v[i];
    }
    return sum;
}

int main()
{
    int x[5] = {10,4,5,8,9};
    int y[5] = {3,4,3,2,7};

    vector<int> v1(x,5);
    vector<int> v2(y,5);

    cout << v1*v2;
    return 0;
}
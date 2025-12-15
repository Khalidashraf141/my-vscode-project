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
    vector(T* a,int m)
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
            sum += this->v[i] * y.v[i];
        }
        return sum;
    }

    void display(void)
    {
        for(int i = 0; i < size; i++)
        {
            cout << v[i] << "  ";
        }
        cout << "\n";
    }
};

int main()
{
    float x[3] = {1.1,2.2,3.3};
    float y[3] = {4.4,5.5,6.6};

    vector <float> v1(x,3);
    vector <float> v2(y,3);

    cout << "v1 = ";
    v1.display();

    cout << "v2 = ";
    v2.display();

    cout << "v1 X v2 = " << v1*v2;
    return 0;
}
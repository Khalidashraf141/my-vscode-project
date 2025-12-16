                                                        // Bubble Sort using Template Function
#include <iostream>
using namespace std;

template<class X>
void swap(X &a, X &b)
{
    X temp = a;
    a = b;
    b = temp;
}

template<class T>
void bubble(T a[], int n)
{
    for(int i = 0; i < n-1; i++)                
    {
        for(int j = n-1; i < j; j--)
        {
            if(a[j]<a[j-1])
            {
                swap(a[j],a[j-1]);
            }
        }
    }
}

int main()
{
    int x[5] = {10,50,30,40,20};
    float y[5] = {1.1,5.5,3.3,4.4,2.2};

    bubble(x,5);    // calls template function for int values
    bubble(y,5);    // calls template function for float values

    cout << "Sorted x-array: ";
    for(int i = 0; i<5; i++)
    {
        cout << x[i] << " ";
    }
    cout << endl;

    cout << "Sorted y-array: ";
    for(int j = 0; j < 5; j++)
    {
        cout << y[j] << " ";
    }
    cout << "\n";
    return 0;
}
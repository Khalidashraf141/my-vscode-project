/*
12.2 Write a class template to represent a generic vector. Include member functions to perform the following tasks.
    (a) To create the vector.
    (b) To modify the value of a given element
    (c) To multiply by a scalar value.
    (d) To display the vector in the form(10,20,30.....)

*/
#include <iostream>
using namespace std;

template<class T>
class Vector
{
    T* v;
    int size;
public:
    Vector(int m)
    {
        size = m;
        v = new T[size];
        for(int i = 0; i < size; i++)
        {
            v[i] = 0;
        }
    }

    // Create vector from array
    Vector(T a[], int m)
    {
        size = m;
        v = new T[size];
        for(int i = 0; i < size; i++)
        {
            v[i] = a[i];
        }
    }

    // Modify value of given element
    void ModifyVector(int index, T value)
    {
        if(index >= 0 && index < size)
            v[index] = value;
        else
            cout << "Invalid index" << endl;
    }

    // Multiply by scalar value
    void MultiplyScalar(T scalar)
    {
        for(int i = 0; i < size; i++)
        {
            v[i] = v[i] * scalar;
        }
    }

    // Display vector
    void display()
    {
        cout << "(";
        for(int i = 0; i < size; i++)
        {
            cout << v[i];
            if(i != size-1)
                cout << ",";
        }
        cout << ")" << endl;
    }
};

int main()
{
    int arr[] = {10,20,30};
    Vector<int> v1(arr,3);
    v1.display();
    v1.ModifyVector(1,50);
    v1.display();

    v1.MultiplyScalar(2);
    v1.display();
    
    return 0;
}
/*Write a function template to perform linear search in an array*/
#include <iostream>
using namespace std;

template<class T>
int linearSearch(T arr[], int n, T key)
{
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == key)
            return i; // element found
    }
    return -1;  // element not found
}

int main()
{
    int a[] = {10,20,30,40,50};
    int pos;

    pos = linearSearch(a,5,30);

    if(pos != -1)
        cout << "Element found at index " << pos;
    else
        cout << "Element not found";


    return 0;
}
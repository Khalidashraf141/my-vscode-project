/*
new-> Dynamically allocates memory at runtime and returns its address(pointer)
delete-> Frees (deallocates) that memory to avoid memory leaks.
*/

//pointer = new datatype; (allocate single variable)
//pointer = new datatype[size]; (allocate array)
//delete pointer; (Free single variable)
//delete[] pointer; (free array)

#include <iostream>
using namespace std;

int main(){
    int size;
    cout << "Enter size: ";
    cin >> size;

    int* arr = new int[size]; //allocate array dynamically

    for(int i = 1; i<size; i++){
        arr[i] = i+1;
    }
    cout << "Array elements: ";
    for(int i =1; i<size; i++){
        cout << arr[i] << " ";
    }
    delete[]arr;         //free array memory
    arr = nullptr;
}
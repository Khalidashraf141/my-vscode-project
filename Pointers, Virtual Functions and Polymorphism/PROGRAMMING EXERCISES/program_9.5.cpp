/*Write a program to sort an array of integer using function pointer in descending order and resort this array in ascending order using virtual function*/
#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

// =============================================
// DESCENDING SORT USING FUNCTION POINTER
// =============================================
void sortDescending(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            if(arr[j]>arr[i]) //Descending
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            } 
        }
    }
}
// ===============================================
// BASE CLASS WITH VIRTUAL FUNCTION
// ===============================================
class Sorter
{
    public:
        virtual void sortArray(int arr[], int n) = 0; //pure virtual
};

// ===============================================
// ASCENDING SORT USING VIRTUAL FUNCTION
// ===============================================
class Ascending : public Sorter
{
    public:
        void sortArray(int arr[], int n)override
        {
            for(int i = 0; i < n; i++)
            {
                for(int j = i+1; j < n; j++)
                {
                    if(arr[j] < arr[i]) // ascending
                    {
                        int temp = arr[i];
                        arr[i] = arr[j];
                        arr[j] = temp;
                    }
                }
            }
        }
};

// ===============================================
// PRINT ARRAY
// ===============================================
void printArray(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// ===============================================
// MAIN PROGRAM
// ===============================================

int main()
{
    int arr[] = {10,3,50,7,1,30};
    int n = 6;

    cout << "Original Array: ";
    printArray(arr,n);

    // ------------------------------
    // FUNCTION POINTER SORT
    //-------------------------------
    void (*fp)(int[], int);
    fp = sortDescending;
    fp(arr,n);

    cout << "Descending (Function Pointer): ";
    printArray(arr,n);

    //------------------------------------
    // VIRTUAL FUNCTION SORT
    //------------------------------------
    Sorter *ptr;
    Ascending asc;
    ptr = &asc;
    ptr->sortArray(arr,n);

    cout << "Ascending (Virtual Function): ";
    printArray(arr,n);

    return 0;
}
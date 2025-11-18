/*
Pointer arithmetic ka matlab hot hai
pointer ke address ko badhaana ya ghatana,
taaki woh memory me next ya previous element ko point kare.
Har bar increase hone par data type ke size ke hisaab se move karta hai

So, pointer expressions can include:
-Dereferencing: *p
-Address-of: &a
-Comparisons: p == q, p != q
-Arithmetic: p + 1, p - 1, p2 - p1
-Assignments: p = &a;

-arrays store elements contiguously in memory
Pointer Arithmetic means adding or subtracting integer values to/from pointers(This is used mostly with arrays).
*/

#include <iostream>
using namespace std;
//TODO:PRACTICE DONE
int main()
{
    int a = 10, b = 20;
    int *p = &a;
    int *q = &b;
    
    cout << *p; //value pointed by p
    cout << "\n";
    cout << q;  // Address stored in q
    cout << "\n";
    cout << (p == q); // Compare pointer addresses
    cout << "\n";
    cout << (p != q); // Compare pointer addresses


    cout<<"\n\n";
    int arr[5] = {10,20,30,40,50};
    int *add1 = arr; //same as &arr[0]
    

    cout <<*add1<< endl;
    cout << *(add1 + 1) << endl;
    cout << *(add1 + 2) << endl;
    cout << *(add1 + 3) << endl;
    cout << *(add1 + 4) << endl;






    //Program 9.3 Arithmetic Operations on Pointers

    cout << "\n\n";
    int num[] = {56,75,22,18,90};
    int *ptr = num; // same as &num[0]
    cout << "The array values are:\n";
    for(int i = 0; i < 5; i++){
        cout << num[i] << "\n";
    }

    // Printing the value in the array
    cout << "\nValue of ptr : " << *ptr << endl;
    ptr++;
    cout << "\nValue of ptr++: " << *ptr << endl;
    ptr--;
    cout << "\nValue of ptr--: " << *ptr << endl;
    ptr+=2;
    cout << "\nValue of ptr+=2: " << *ptr << endl;
    ptr-=1;
    cout << "\nValue of ptr-=1: " << *ptr << endl;
    ptr+=3;
    cout << "\nValue of ptr+=3: " << *ptr << endl;
    ptr-=2;
    cout << "\nValue of ptr-=2: " << *ptr << endl;


    return 0;
}

/*
Address       |   Value   |  Description
------------- | ----------| -------------
0x1000        |   10      | arr[0]
0x1004        |   20      | arr[1]
0x1008        |   30      | arr[2]
--------------|------------|--------------
arr ----------> 0x1000     (Still fixed)
ptr ----------> 0x1004     (Now points to arr[1])


arr → fixed address (acts like a constant pointer).

ptr → normal pointer variable (movable).

ptr++ moves to next element (4 bytes forward for int).

arr++ ❌ invalid — compiler error.

*/
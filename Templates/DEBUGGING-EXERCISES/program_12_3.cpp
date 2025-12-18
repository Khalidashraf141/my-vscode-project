/*Identify the error in the following program*/
#include <iostream>
using namespace std;

template <class T1, class T2>
// T1& MinMax(T1 t1, T2 t2)
T1& MinMax(T1 t1, T2 t2)
{
    return t1 > t2 ? t1 : t2;
    // cout << " ";  this line is never executed because it is written after return
}
int main()
{
    // cout << ++MinMax(2,3);
    cout << MinMax(2,3);
    /*
    You are doing:
        Incrementing a dangling reference
        That means modifying invalid memory

    */
    return 0;
}
/*A dangling reference is a reference that refers to a memory location whose lifetime has ended*/

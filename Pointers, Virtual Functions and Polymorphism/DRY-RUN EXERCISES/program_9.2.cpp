/*What will happen when the following program is run?*/
#include <iostream>
using namespace std;

int main()
{
    int arr[6] = {22,5,23,43,54,65};
    int *p,i;
    p = arr;
    i = *p++ - *p--;
    cout << i;
    return 0;
}
/*
✔️ Part 1: *p++
p++ is post-increment, so:
    1. Use current value of p
    2. Then inrement pointer after using it

So:
    - *p = 22
    - After using it, p move to arr[i]
syntax:
    Value from *p++ = 22
    !p now -> arr[i] (value 5)

✔️ Part 2: *p--
p-- is post-decrement, so:
    1. Use current value of p
    2. Then decrement pointer after using it
So:
    - *p = 5
    - After using it, p moves back to arr[0]
syntax:
    Value from *p-- = 5
    !p now -> arr[0] (value 22)


Now substitute into expression:

    i = 22 - 5
    17
    

*/
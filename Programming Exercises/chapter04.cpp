#include <iostream>
using namespace std;
//1
// int *f()
// {
//     int m = 1; //local variable
//     return (&m); // wrong!

// //m is a local variable it lives only unit function ends . after function ends, memory of m is destroyed so returning &m its address gives dangling pointer (pointer to invalid memory) if you try to use it you'll get undefined behaviour (garbage values, crash, etc).
// }


//correct way is - use static
int* f(){
    static int m = 1; // static variable - lifetime = entire program
    return &m; //safe to reutrn address
}
//2
double g(){
    double pi = 3.14765;
    return pi;
}

//3
int& k(){
   // int n = 10; //this is wrong because n is a local variable and will be destroyed returning a reference to it is unsafe.
   static int n = 10;
    return n;
}
int main(){
    cout << *f()<<" \n";
    cout << g()<<" \n";
    cout << k()<<" \n";
    return 0;
}

/*
summary-
-use static for local variables when returning pointers or references.
-Returning by value (double g()) is safe because a copy is made.
*/
/*
🔻What is a Pointer to Function?
    just like we make a pointer that stores  address of a variable,
    we can also make a pointer that stores the address of a function.

Matlab:
    A function pointer is used to call function its address instead of its name.

🔻Why use Function Pointers?
    1. To pass a function as an argument to another function
    2. To call different functions dynamically at runtime.
    3. In callbacks (used in event handling, sorting, etc).
🔻What is typedef?
    typedef is a keyword in C/C++ used to give a new name (nickname) to an existing data type.
    It makes code shorter, easier to read, and more understandable.
*/

#include <iostream>
using namespace std;

void add(int a, int b) {cout << "Sum = " << a + b << endl;}
void sub(int a, int b) {cout << "Diff = " << a - b << endl;}

void compute(void(*fptr)(int,int)){
    fptr(10,5);// call the function passed
}

int sum(int a, int b){
    return a + b;
}

typedef void (*FunPtr) (int, int);

void addition(int i, int j)
{
    cout << i << " + " << j << " = " << i + j;
}
void subtract(int i, int j)
{
    cout << i << " - " << j << " = " << i - j;
}
int main()
{
    //Example (passing function as argument):
    compute(add);
    compute(sub);
    cout<<"\n========================================\n";
    
    int (*ptr)(int,int); //function pointer declaration
    ptr = sum;      // assigning function address(no need for &)
    
    cout << ptr(5,10)<<endl;  //calling function using pointer
    //or (*ptr)(5,10)
    
    cout<<"\n========================================\n";
    //Program 9.7
    FunPtr address;
    address = addition;
    address(1,2);
    cout << endl;
    address = subtract;
    address(5,1);
    cout<<"\n========================================\n";
    return 0;

}

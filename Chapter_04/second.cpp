//the effect of a default argument can be alternatively achievved by overloading. Discuss with an example.
/*
default arguments
when you assign default values in function parameters, the compiler will automatically use them if the caller doesn't provide arguments.
*/
#include <iostream>
using namespace std;

void display (int a, int b = 10){
    cout << "a = "<< a << " b = " << b << "\n";

}
void display_01(int a);
void display_01 (int a, int b);

int main(){
    display(10); //uses default b = 10
    display(10,200); // overrides default
    display_01(10);
    display_01(100,200);
    return 0;
}

/*
function overloading 
instead of giving a default parameter, you can overload the function by defining multiple versions with different parameter lists.
*/
void display_01(int a){
    cout << a;
}
void display_01(int a , int b){
    cout << a <<' ' << b;
}
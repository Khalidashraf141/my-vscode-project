//function overloading - overloading refers to the use of the same thing for different purposes.This means that we can use the same function name to create functions that perform a variety of different tasks.This is known as function polymorpism in OOP.
#include <iostream>
using namespace std;

int add(int a, int b); //prototype 1
int add(int a, int b, int c); //prototype 2
double add (double x, double y); //prototype 3
double add (double x, int y); //prototype 4
int main(){
    cout << add(4,5)<<"\n";
    cout << add(4,5,6)<<"\n";
    cout << add(7.2,9.11)<<"\n";
    cout << add(7.2,8)<<"\n";
    return 0;
}

int add(int a, int b){
    return a + b;
}
int add (int a, int b, int c){
    return a + b + c;
}
double add (double x, double y){
    return x + y;
}
double add (double x, int y){
    return x + y;
}
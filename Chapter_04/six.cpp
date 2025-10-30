//Area of cirlce A = pi*r^2
//Area of triangle = 1/2*b*h
//1/2 treated as 0 so insted of using 1/2 use 0.5
#include <iostream>
#include <cmath>
using namespace std;

double area(int r){
    return (3.14159*pow(r,2));
}
int area (int b, int h){
    return (0.5*b*h);
}

int main(){

    cout << area(20) << "\n";
    cout << area(12,6) << "\n";
    return 0;

}
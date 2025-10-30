#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main(){
    //Practice
    cout << "Table for Y = EXP[-X]\n\n";
    cout << setw(10) << "x" << setw(15) << "y = exp(-x)\n";
    cout << "--------------------------------------------\n";

    for (double x = 0.0; x <=10.0; x+=0.1){
        double y = exp(-x);
        cout << setw(10) << fixed << setprecision(1) << x << setw (15) << setprecision(6) << y << endl;
    }
    return 0;
}
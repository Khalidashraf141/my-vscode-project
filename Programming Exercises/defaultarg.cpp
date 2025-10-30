#include <iostream>
#include <cmath>
using namespace std;
//compound intrest
float value(float principle, int period, float rate)
{
    int sum = (principle*pow(1+rate,period));
    return sum;
}

void printline(char ch, int len){
    for(int i = 1; i <=len; i++){
        cout << ch;

    }
    cout << "\n";
}
int main(){
    printline('*',40);
    cout << value(400,5,2) << '\n';
    printline('=',40);
    return 0;
}
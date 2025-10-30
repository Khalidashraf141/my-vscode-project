#include <iostream>
#include <string>
using namespace std;

int main(){
    int userInput;
    cout<< "Type a Number: ";
    cin>> userInput;
    cout<< "Your number is: "<< userInput<< endl;
    
    int x, y;
    int sum;
    cout<< "Enter the first number";
    cin>> x;
    cout<< "Enter the second number";
    cin>> y;
    sum = x + y;
    cout << "Sum is: " << sum<<endl;

    float f1 = 35e3;
    double f2 = 42e4;
    cout<< f1<< endl;
    cout<< f2<< endl;

    bool first = true; //1
    bool second = false; //0
    cout << first << endl;
    cout << second<< endl;

    return 0;
}
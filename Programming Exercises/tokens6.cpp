#include <iostream>
#include <string>
using namespace std;

int main(){
    string user_name;
    int units;
    double amount = 0;

    cout << "Enter your name: ";
    getline(cin,user_name);
    cout << "Enter the number of units consumed: ";
    cin >> units;

    if(units <= 100){
        amount = units * 0.60;
    }
    else if(units<=300){
        amount = (100*0.60)+(units-100)*0.80;
    }
    else{
        amount = (100*0.60) + (200*0.80) + (units-300)*0.90;
    }

    //Minimum charge
    if(amount<50){
        amount = 50;
    }

    //Surcharge if > 300
    if(amount>300){
        amount = amount + amount*0.15;
    }

    cout << "User: " << user_name << "\n";
    cout << "Total Charges: Rs. " << amount << "\n";

    return 0;
}
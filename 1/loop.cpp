#include <iostream>
using namespace std;

int main(){
    //While Loop
    int i = 0;
    while(i<10){
        cout << i <<endl;
        i++;
    }

    //do/while loop
    int k = 5;
    do{
        cout << k << endl;
        k++;
    }
    while(k<5);
    //countdown
    int countdown = 3;
    while(countdown>0){
        cout << countdown<<" Happy New Year" << endl;
        countdown--;
    }

    //Print even number
    int num = 0; //zero is even number.
    while(num<=10){
        cout << num << "Even"<<endl;
        num+=2;
    }

    //While loop to reverse some numbers.
    int numbers = 12345;

    int revNumbers = 0;

    while (numbers)     
    {
        revNumbers = revNumbers * 10 + numbers % 10;
        numbers/=10;
    }
    cout << "Reversed numbers: "<< revNumbers << endl;

    //For loop
    for(int i = 0; i<5; i++){
        cout << i << endl;
    }

    //Nested Loops
    for(int i = 1; i<=2; i++){
        cout << "Outer: " << i << endl;

        for(int j = 1; j<=3; j++){
            cout << " Inner: "<< j << endl;
        }
    }

    //foreach Loop
    int myNumbers[5] = {10, 20, 30, 40, 50};
    for(int i : myNumbers){
        cout << i << " ";
    }

    //counts to 100 by tens
    for(int i = 0; i<=100; i+=10){
        cout << i << endl;
    }

    //even number
    for(int i = 0; i<=10; i+=2){
        cout << i << endl;
    }

    //odd number
    for (int i = 1; i <= 10; i+=2)
    {
        cout << i << endl;
    }
    
    //print powers of 2 up to 512
    for(int i = 2; i<=512; i*=2){
        cout << i << endl;
    }

    //multiplication table

    int number = 2;
    for(int i = 1; i<=10; i++){
        cout<<number<<'X'<<i<<'='<<number*i<<endl;
    }
    return 0;
}
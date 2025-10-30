//when a parameter is passed to the function it is called an argument. so from the example above (fname) is a parameter while "Khalid" is arguments.
#include <iostream>
using namespace std;

void firstname(string fname){
    cout << fname << " Ashraf\n";
}
//Multiple parameters
void fnameAge(string fname, int age){
    cout << "Name is " << fname <<" "<< age << " years old.\n";
}
//return values
int addfive(int x){
    return x + 5;
}

//sum of two numbers
int sum(int x, int y){
    return x + y;
}
//double for loop
int doubleGame(int x){
    return x * 2;
}
void changevalue(int &num){
    num = 50;
}
void numPrint(int mynumbers[5]){
    for(int i = 0; i < 5; i++){
        cout << mynumbers[i] << "\n";
    }
}
int main(){
    firstname("Khalid");
    fnameAge("Khalid",18);
    cout << addfive(5)<<"\n";
    cout << addfive(100) << "\n";
    cout << addfive(50) << "\n";
    cout << sum(4,5) << "\n";
    for(int i = 1; i <= 5; i++){
        cout << "Double of " << i << " is " << doubleGame(i) <<"\n";
    }
    int value = 60;
    changevalue(value);
    cout << value;
    int rollnumber[5] = {10,20,30,40,50};
    numPrint(rollnumber);
    

    return 0;


}
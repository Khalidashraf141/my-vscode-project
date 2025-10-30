#include <iostream>
using namespace std;

int main(){
    int myage;
    cout<<"Enter your age: ";
    cin>>myage;
    if(myage>18){
        cout<<"You can vote";
    }
    else{
        cout<<"You can't vote";
    }
    return 0;
}

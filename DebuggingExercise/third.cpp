//identify the error in the following program segment
#include <iostream>
using namespace std;

int p;
int &display();
int main(){

    display()=5;
    cout << p;
    return 0;
}
int & display(){
    static int a = 2;
    return p;
}
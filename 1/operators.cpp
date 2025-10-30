#include <iostream>
using namespace std;

int main(){
    //Arithmetic Operators
    int num1 = 48;
    int num2 = 24;
    cout << num1 + num2<< endl;
    cout << num1 - num2<< endl;
    cout << num1 / num2<< endl;
    cout << num1 % num2<< endl;
    cout << ++num1<<endl;
    cout << --num2<<endl;
    
    //Assignment operators
    int num3 = 10;
    num3+=5;
    cout<<num3<<endl;

    num3-=1;
    cout<< num3<<endl;

    num3*=2;
    cout<<num3<<endl;

    num3/=2;
    cout<<num3<<endl;
    
    num3%=3;
    cout<< num3<<endl;

    //Comparison
    int jhon = 25;
    int jackob = 15;
    cout << (jhon>jackob)<<endl;
    cout << (jhon>=jackob)<<endl;
    cout << (jhon==jackob)<<endl;
    cout << (jhon!=jackob)<<endl;

    //Logical Operators
    int rank = 55;
    cout << (rank>10 && rank>25)<<endl; //Return true if both statements are true
    cout << (rank>5 && rank>65)<<endl;
    cout << (rank>5 || rank>95)<<endl; //Return true if one of the statements is true
    cout << !(rank>5 && rank>10); // return false if the result is true

    return 0;


}
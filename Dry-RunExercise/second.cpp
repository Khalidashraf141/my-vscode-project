#include <iostream>
using namespace std;

void fun(int count){
    if(count==0){
        cout << count;
    }
    else{
        cout << count <<"\n";
        fun(--count);
        return;
    }
}

int main(){
    fun(9);
    return 0;
}
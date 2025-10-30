//In C the global version of a variable cannnot be accessed from within the innner block.C++ resolves this problem by introducing a new operator :: called scope resolution operator. This can be used to uncover a hidden variable. It takes the followig form.

#include <iostream>
using namespace std;

int effect = 100;
    int main(){
        int effect = 200; //Local variable hides the global one
        cout <<"The value of inner block effect is =>" << effect <<"\n";
        cout <<"The value of outer block effect is =>" << ::effect;
        return 0;
    }
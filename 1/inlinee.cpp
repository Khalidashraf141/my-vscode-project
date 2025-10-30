#include <iostream>
using namespace std;
//inline keyword merely sends a request not a command to the compiler.The compiler may ignore this request if the function definition is too long or too complicated and compile the function as a normal function.
//the speed benefits of inline functions diminish as the function grows in size.
inline double cube(double a){return (a*a*a);}
int main(){
    cout << cube(12.4);
    return 0; 
}

#include <iostream>
using namespace std;

inline int large(int p, int q){
    return (p>q)?p:q;
}
int main(){
    cout << "larger of two is: " << large(4,40) << "\n";
    return 0;
}
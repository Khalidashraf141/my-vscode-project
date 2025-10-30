//identify the error in the following program segment:
#include <iostream>
using namespace std;
int show(int a){
    cout << a << "\n";
    return a;
}
float show(float a){
    cout << a;
    return a;
}
int main()
{
    int a = 2;
    float b = 2.5;
    show(a);
    show(b);
    return 0;
}
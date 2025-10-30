#include <iostream>
using namespace std;

#define LARGEST(x,y,z) ((x>y)?((x>z)?x:z):((y>z)?y:z))

//same thing with inline function
inline int max(int x, int y, int z){
    if(x>y){
        return (x > z)?x:z;
    }else{
        return (y>z)?y:z;
    }
}

int main(){
    int x,y,z;
    cout << "Enter the three numbers: ";
    cin >> x >> y >> z;

    cout << "Largest number is: " << LARGEST(x,y,z) << "\n";
    cout << "The maximum number is:" << max(x,y,z);
    return 0;
}
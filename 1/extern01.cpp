// the (extern) keyword is used to declare a varialbe or function that is defined somewhere else (usually in another file) so the compiler knows it exist but doesn't create a new copy. It's mostly used for global variables and fucntions that you want to share acroos multiple files.

//extern tells the compiler- This variable or function is already defined somewhere else, I'm just declaring it here so i can use it. - without extern, if you declare a global varialbe in multiple files you'll get a multiple definition error.
#include <iostream>
using namespace std;
extern int counter;
int main(){
    extern int counter;
    cout << counter;
    
    
    return 0;

}
//still not completed
#include <iostream>
using namespace std;

int main(){
    cout << "Hello World!";
    return 0;
}

//Omitting Namespace
//C++ programs that runs without the standard namespace library. The using namespace std line can be omitted and replaced with the std keyword, followed by the :: operator
#include <iostream>
int main(){
    std::cout<<"Hello Again!!";
    std::cout<<"Hello Again!!!";
    return 0;
}
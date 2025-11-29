/*What will happen when the following program is executed?*/
#include <iostream>

int main()
{
    // istream &in = std::cin;
    // ostream &out = std::cout;
    std::istream &in = std::cin;
    std::ostream &out = std::cout;
    

    int x;
    in>>x;
    out << x;
    return 0;
    //Error
}
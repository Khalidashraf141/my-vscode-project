/*Identify the error in the following program, if any:*/
#include <iostream>
int main()
{
    /*
    ❌Error: You cannot copy a stream object
    -std::istream and std::ostream cannot be copied.
    -They are non-copyable classes (copy constructor is deleted).
    -Attempting this gives compile-time errors
    std::istream in = std::cin;
    std::ostream out = std::cout;
    */

    //use references, because stream objects can be referenced but not copied
    std::istream& in = std::cin; //reference
    std::ostream& out = std::cout; //reference

    int x;
    
    in >> x;
    out << x;
    return 0;


}
#include <iostream>
namespace myspace
{
    std::istream &in = std::cin;
    std::ostream &out = std::cout;
}
using namespace myspace;
int main()
{
    int x;
    in>>x;
    out<<x;
    return 0;
}

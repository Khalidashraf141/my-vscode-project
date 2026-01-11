#include <iostream>
using namespace std;

int main()
{
    int m = 65;
    char ch = static_cast<char>(m);
    cout << ch << "\n";
    m*= 10;
    char ch = static_cast<char>(m);
    cout << ch << "\n";
    return 0;
}
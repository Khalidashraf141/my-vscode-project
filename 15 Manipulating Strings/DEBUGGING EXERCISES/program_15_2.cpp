#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s1("what will happen");
    s1.pop_back();
    cout << s1 << '\n';
    cout << "capacity of string:- "<< s1.capacity() << "\n";

    s1.resize(10);
    cout << "capacity of string:- "<< s1.capacity() << "\n";

    s1.shrink_to_fit();
    cout << "capacity of string:- " << s1.capacity() << "\n";
}


#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s1("ABCDE");
    cout << "capacity of string:- " << s1.capacity() << "\n";
    s1.reserve(20);
    cout << "capacity of string:- " << s1.capacity() << "\n";
    s1.resize(3);
    cout << "capacity of string:- " << s1.capacity() << "\n";
    s1.shrink_to_fit();
    cout << "capacity of string:- " << s1.capacity() << "\n";
    s1.reserve(40);
    cout << "capacity of string:- " << s1.capacity() << "\n";
    return 0;
}
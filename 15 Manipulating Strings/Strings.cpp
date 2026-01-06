#include <iostream>
#include <string>
using namespace std;

int main()
{
    string a = "Hello";
    string b = "World";
    string ab;

    //append()
    ab.append(a);
    cout << ab << "\n";

    //assign() new value (replaces old one)
    a.assign("Khalid");
    cout << a << "\n";

    //access character at given index
    cout << a.at(1) << "\n";

    //begin() returns iterator to first character
    cout << *b.begin() << "\n";

    //capacity() total allocated storage 
    cout << ab.capacity() << "\n";

    //size();
    cout << ab.size() << "\n";

    string n1 = "zxw";
    string n2 = "deg";
    cout << n1.compare(n2);
    cout << "\n";

    string em = "hello";
    if(em.empty())
        cout << "empty string";
    else
        cout << "Not empty";

    cout << "\n";
    auto it = n1.end();
    it--;
    cout << *it;

    cout << "\n";
    em.erase(1,2);
    cout << em;

    cout << "\n";
    cout << em.find("h");

    em.insert(3," New line");
    cout << em;
    cout << "\n";
    cout << em.max_size();
}
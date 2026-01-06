#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s1("12345");
    string s2("abcde");

    cout << "Original Strings are: \n";
    cout << "S1: " << s1 << "\n";
    cout << "S2: " << s2 << "\n\n";

    // Inserting a string into another
    cout << "Place S2 inside S1\n";
    s1.insert(4,s2);
    cout << "Modified S1: " << s1 << "\n\n";

    // Removing characters in a string
    cout << "Remove 5 Characters from S1\n";
    s1.erase(4,5);
    cout << "Now S1: " << s1 << "\n\n";

    // Replacing characters in a string
    cout << "Replace Middle 3 Characters in S2 with S1\n";
    s2.replace(1,3,s1);
    cout << "Now S2: " << s2 << "\n";
    return 0;
}
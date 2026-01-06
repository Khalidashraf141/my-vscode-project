#include <iostream>
#include <string>
using namespace std;

int main()
{
    // Creating string objects
    string s1;      // Empty string object
    string s2 (" New"); // Using string constant
    string s3 (" Delhi");

    // Asigning value to string objects
    s1 = s2;    // Using string object
    cout << "S1 = " << s1 << "\n";

    // Using a string constant
    s1 = "Standard C++";
    cout << "Now S1 = " << s1 << "\n";

    string s4(s1);
    cout << "S4 = " << s4 << "\n\n";

    // Reading through keyboard
    cout << "ENTER A STRING\n";
    cin >> s4;      // Delimited by blank space
    cout << "Now S4 = " << s4 << "\n\n";

    // Concatenating strings
    s1 = s2 + s3;
    cout << "S1 finally contains: " << s1 << "\n";
    return 0;
}
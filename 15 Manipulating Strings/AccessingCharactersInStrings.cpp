#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s("ONE TWO THREE FOUR");
    cout << "The string contains: \n";
    for(int i = 0; i<s.length(); i++)
        cout << s.at(i);        // Display one character
    
    cout << "\nString is shown again: \n";
    for(int j = 0; j < s.length(); j++)
        cout << s[j];

    int x1 = s.find("TWO");
    cout << "\n\n TWO is found at: " << x1 << "\n";

    int x2 = s.find_first_of('T');
    cout << "\nT is found first at: " << x2 << "\n";
    int x3 = s.find_last_of('R');
    cout << "\nR is last found at: " << x3 << "\n";

    cout << "Retrieve and print substring TWO \n";
    cout << s.substr(x1,3); /*finds the substring "TWO". The first argument x1 specifies the location of the first character of the required substring and the second argument give the length of the substring*/
    cout << "\n";

    return 0;
}
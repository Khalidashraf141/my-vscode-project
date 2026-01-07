#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
    string s1;
    char r[2];
    r[1] = '\0';
    cin >> s1;
    for(int i = 0; i < s1.length(); i++)
    {
        r[0] = toupper(s1.at(i)) == 'Z' ? 'A' : toupper(s1.at(i)) + i;
        s1.replace(i, 1, string(r));
    }
    cout << s1 << "\n";
}
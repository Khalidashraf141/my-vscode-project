#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    const char * string1 = "C++ ";
    const char * string2 = "Programming";
    int m = strlen(string1);
    int n = strlen(string2);

    for(int i = 1; i <=n; i++)
    {
        cout.write(string2,i);
        cout <<'\n';
    }

    for(int i = n; i > 0; i--)
    {
        cout.write(string2,i);
        cout <<"\n";
    }

    // concatenating strings
    cout.write(string1,m).write(string2,n);
    cout << "\n";
    // crossing the boundary
    cout.write(string1,10);
    /*
    the last line of the output indicates that the statement
        cout.write(string1,10);
    displays more characters than what is contained in string1
    it is possible to concatenate two strings using the write() function.
    */
    return 0;
}
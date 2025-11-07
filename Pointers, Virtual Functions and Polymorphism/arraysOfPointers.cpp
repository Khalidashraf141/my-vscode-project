#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    const char *ptr[10] = 
    {
        "books",
        "television",
        "computer",
        "sports"
    };

    int i = 0;
    char str[25];
    cout << "\n\n\nEnter your favorite leisure pursuit: ";
    cin >> str;
    for(i = 0; i < 4; i++)
    {
        if(!strcmp(str,ptr[i])) 
        {
            cout << "\n\nYour favorite pursuit " << " is available here" << endl;
            break;
        }
    }
    if(i==4)
    cout << "\n\nYour favorite " << " not available here" << endl;

    return 0;
};
/*
strcmp() returns 0 for equal strings, and ! changes that 0 into 1 (true), allowing the if statement to run when both strings match.
strcmp is case sensitive
_stricmp make it case in-sensitive

Meaning of ! (NOT)
It reverses the logical value of whatever comes after it.



strcmp(str, ptr[i]) → returns 0 if both strings are equal.

!0 → becomes 1 (true).

So the if condition runs only when strings are the same.
*/
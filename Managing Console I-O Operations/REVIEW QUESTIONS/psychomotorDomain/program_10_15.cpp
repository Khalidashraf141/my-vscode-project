/*
Show what the following statement does.
    cout.write(s1,m).write(s2,n)
*/
#include <iostream>
using namespace std;

int main()
{
    char s1[] = "HelloWorld";
    char s2[] = "12345";
    int m = 5;
    int n = 3;
    cout.write(s1,m).write(s2,n);
    
    return 0;
}
/*
✅ What This Statement Does
This statement uses two consecutive calls to the write() function the same stream (cout).

✔️write(s1,m)
->Writes exactly m characters starting from the address s1

✔️.write(s2,n)
->Immediately writes exactly n characters starting from the address s2.

The key point is that both write() calls happen in a single chained statement because:
    - write() returns a reference to the same output stream (ostream&)
    - This allows the next .write() to be executed on the same stream in sequence

    cout.write(s1,m);
    - writes first m characters form array/string s1
    - Does NOT stop at null characters \0
    - Does NOT check string length
    - Outputs raw characters
    .write(s2,n);
    - Continues writing from the same output stream
    - Writes n characters from array/string s2
    - Also does not stop at \0

    Together, both blocks of data are printed back-to-back


    📌 Important Properties of write()
    Property                    Meaning
    Raw output                  Prints bytes exactly as they are
    No null-termination check   \0 is treated like a normal character
    Fixed-size output           Always prints the exact count
    Good for binary data        Works with non-text files

    ⚠️ What Happens If m or n Is Too Large?
    write() will:
    - print garbage values beyond the actual string
    - possibly access invalid memory
    - lead to undefined behaviour
    Because it does not stop even if a null terminator is found early.

Raw ouput refers to output that prints data exactly as stored in memory,
without formatting conversion or stopping at null characters.
Function like write() perform raw output by writing a fixed number of bytes directly to the output stream.
*/
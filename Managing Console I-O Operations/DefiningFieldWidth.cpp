#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    cout << setw(5) << 12
         << setw(5) << 345
         << setw(5) << 6785
         << setw(5) << 123456
         <<endl;
    return 0;
}
/*
Explanation
1️⃣ setw(5) << 12
    - width = 5
    - value = "12" (2 character)
    - output: " 12"(3spaces + "12")

2️⃣setw(5) << 345
    - width = 5
    - value = "345" (3 characters)
    - output: " 345" (2 spaces + "345")

3️⃣ setw(5) << 6785
    - width = 5
    - value = "6785" (4 characters)
    - output: " 6785" (1 space + "6785")

4️⃣ The important part: setw(5) << 123456
    - width = 5
    - value = "12345" (6 characters - bigger than 5)
    - C++ expands the field
    - output: "123456" (no spaces, full value kept)

values smaller than 5 character get padded with spaces
!The last value is larger than 5 character -> NOT TRUNCATED

with right -> padding on left
with left -> padding on right

!C++ never truncates values -> C++ does not cut off or shorten your output
Even if the field width you 
specify with setw() is smaller than the value you want to print

!C++ does NOT do this:
    1234 (wrong - this would be truncation)

!C++ does this:
    123456 (correct - expands to fit)
(The entire value is shown, not just the first 4 digits)


!important
    cout << setw(10) << 123456789;
Analysis:
    - 123456789 -> 9 characters
    - width = 10 -> normally you would expect 1 space
!But C++ rules say:
    If the number fits comfortably inside the filed, pad.
    If it is close to the the width or bigger, just print it normally.

Because C++ does not try to stretch the field when the value is nearly equal to the width

example:- cout << setw(4) << 123456;
    - You requested a field width of 4
    - But the number 123456 has 6 digits
C++ expands the field to 6 spaces so it can print the whole number.
!The field became 6 characters wide, not 4 because it had to to fit the value

*/
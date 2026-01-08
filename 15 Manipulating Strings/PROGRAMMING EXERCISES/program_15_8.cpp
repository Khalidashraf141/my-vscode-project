/*
Give a string
        string s("123456789");
    Write a program that displays the following
                            1
                        2   3   2
                    3   4   5   4   3
                4   5   6   7   6   5   4
            5   6   7   8   9   8   7   6   5
*/
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s = "123456789";
    int rows = 5;

    for (int i = 1; i <= rows; i++)
    {
        // 1. Print spaces
        for (int space = 1; space <= rows - i; space++)
            cout << "    ";

        // 2. Increasing part
        for (int j = i - 1; j <= i - 1 + (i - 1); j++)
            cout << s[j] << "   ";

        // 3. Decreasing part
        for (int j = i - 2 + (i - 1); j >= i - 1; j--)
            cout << s[j] << "   ";

        cout << endl;
    }

    return 0;
}

/*
Write a program that reads the name
Martin Luther King
from the keyboard into three separate string objects and then concatenates them into a new string object using 
    (a) + operator and
    (b) append() function
*/
#include <iostream>
#include <string>
using namespace std;

int main()
{
    cout << "USING + OPERATOR" << endl;
    string first, second, third;
    cin >> first >> second >> third;

    string final = first +" "+ second+ " "+ third;
    string finalAppend;
    finalAppend.append(first).append(" ").append(second).append(" ").append(third);
    cout << "==== OUTPUT ====\n";
    cout << final << " Using + Operator\n";
    cout << finalAppend << " Using append() function";
    cout << "\n=================\n";

    return 0;
}
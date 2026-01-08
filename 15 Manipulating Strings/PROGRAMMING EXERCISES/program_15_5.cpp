/*
Write program that counts the number of occurrences of a particular character, say 'e', in a line of text
*/
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    string story;
    getline(cin,story);
    char ch;
    cout << "Enter the letter you want to count: ";
    cin >> ch;
    cout << count(story.begin(),story.end(),ch);
    return 0;
}
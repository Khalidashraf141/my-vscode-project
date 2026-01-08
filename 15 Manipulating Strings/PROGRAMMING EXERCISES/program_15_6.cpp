/*
Write a program that reads the following text and counts the number of times the word "It" appears in it.
It is new. It is singular
It is simple. It must succeed!
*/
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main()
{
    string text = "It is new. It is singular.\nIt is simple. It must succeed!";
    cout << text;
    // getline(cin, text);

    string target = "It";
    string word;
    int count = 0;

    istringstream iss(text);
    while(iss >> word)
    {
        if(word == target)
            count++;
    }
    cout << endl;
    cout << "The number of (" << target << ") in the sentence is: " << count;
    return 0;
}
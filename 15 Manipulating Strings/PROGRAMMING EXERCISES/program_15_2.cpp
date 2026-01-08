/*
Write a program using an iterator and while() construct to display the contents of a string object
*/
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string quote = "Martin Luther King";
    auto it = quote.begin();
    while(it != quote.end())
    {
        cout << *it;
        it++;
    }
    return 0;

}
/*
-Define a class String. Use overloaded == operator compare two strings.
*/
#include <iostream>
#include <cstring>
using namespace std;
class MyString
{
    char str[100]; // to store string data
public:
    MyString(const char *s = "")
    {
        strcpy(str,s);
    }

    // Overload == operator
    bool operator==(const MyString &other)
    {
        return strcmp(str,other.str) == 0; //strcmp returns 0 if equal
    }

    // Display function
    void show()
    {
        cout << str;
    }

};

int main()
{
    MyString s1("hello");
    MyString s2("world");
    MyString s3("hello");
    cout << "Comparing s1 and s2: ";
    if(s1 == s2)
    {
        cout << "Equal" << "\n";
    }else{
        cout << "Not Equal" << "\n";
    }

    cout << "Comparing s1 and s3: ";
    if(s1 == s3)
    {
        cout << "Equal" << "\n";
    }else{
        cout << "Not Equal" << "\n";
    }

    return 0;
}
//TODO:PRACTICE
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main()
{
    char str[80];

    cout <<"Enter a string: ";
    cin >> str;

    int len = strlen(str);

    fstream file;   //input and output stream
    cout << "\nOpening the 'TEXT' file and storing the string in it.\n\n";

    file.open("TEXT", ios::in | ios::out | ios::trunc);

    for(int i = 0; i <len; i++)
    {
        file.put(str[i]);    //put a character to file

    }
        file.seekg(0);      //go to the start

        char ch;
        cout << "Reading the file contents: ";
        while(file.get(ch))
        {
            cout << ch;
        }
        file.close();
        return 0;

    
}
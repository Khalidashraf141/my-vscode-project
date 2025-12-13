/*Write a program that reads a text file and creates another file that is identical expect that every sequence of consecutive blank spaces is replaced by a single space.*/

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream ini_file("original.txt");
    ofstream out_file("copy.txt");
    char ch;
    bool lastWasSpace = false;

    while(ini_file.get(ch))
    {
        if(ch == ' '){
            if(!lastWasSpace)//if it encounter second time space it will skip it
            {
                out_file << ch;
                lastWasSpace = true;
            }
        }else{
            out_file << ch;
            lastWasSpace = false;
        }
    }
    cout << "Copying is complete without consecutive space!";

    ini_file.close();
    out_file.close();
    return 0;
}

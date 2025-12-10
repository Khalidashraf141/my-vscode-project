/*What will happen when the following program is executed*/
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    fstream fout;
    // fout = (fstream)cout;
    fout << "Hello";
    return 0;
}

/*
The program will not compile.
You cannot assign cout (ostream) to an fstream object
so the statement
fout = (fstream)cout;
is illegal and produces a compilation error.

fstream internally uses a filebuf (buffer connected to a file).
cout uses a streambuf connected to the console
*/
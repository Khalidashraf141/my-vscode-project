#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    fstream fobj("Text.txt", ios::ate | ios::in);
    if(fobj.tellg() == fobj.tellp())
        cout << "same";
    else
        cout << "Not same";
    return 0;
}
/*
ios::ate does
ios::ate move both pointers to end of file immediately when opened

get pointer -> end of file
put pointer -> end of file

fstream creates both pointers internally
even if you open it with only ios::in the put pointer (tellp()) still exists - only writing operations are prohibited but the pointer is valid

ios::ate moves both pointers to the end
so they end up at the same position

iso::ate moves both read and write pointers to the end, so tellg() and tellp() become equal -> output = same

*/
#include <iostream>
#include <fstream>
using namespace std;


int main()
{
    ofstream fout;
    fout.open("test.txt"); // open file for writing

    fout << "Hello C++ File Handling!";
    fout.close();   // close file

    return 0;
}
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream fin;
    fin.open("test.txt");   // open file for reading

    string line;
    while(getline(fin,line)){
        cout << line << endl;
    }
    fin.close(); // close file

/*
• fin -> input stream (file from which we read)
• line -> string where the read line will be stored
*/

    return 0;
}
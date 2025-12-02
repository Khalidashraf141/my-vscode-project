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

    return 0;
}
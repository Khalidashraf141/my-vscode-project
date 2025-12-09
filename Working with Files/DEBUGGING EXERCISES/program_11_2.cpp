#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    char buffer[80];
    ifstream fin;

    fin.open("ch11_2.cpp");

    while(!fin.eof()){
        fin.getline(buffer,80);
        cout << buffer << endl;
        fin.seekg(0,ios::beg);
    }
    return 0;
}
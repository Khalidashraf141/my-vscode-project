/*The names contain only one word and the names and telephone numbers are separated by white spaces. Write a program to read the file and output the list in two columns. The names should be left-justified and the number right-justified*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;

int main()
{

    ifstream fout("telephoneNumber.txt");
    ofstream fin("sortedTelephoneNumber.txt");
    string name,number;

    
    while(fout >> name >> number)
    {
        fin << left << setw(20) << name
            << right << setw(15) << number << "\n";

    }
    fout.close();
    fin.close();

    return 0;


}

/*
This automatically reads:
    first word -> name
    second word -> number
Extra spaces don't matter


*/
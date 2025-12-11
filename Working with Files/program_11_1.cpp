// Creating files with constructor function
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main()
{
    ofstream outf("ITEM"); // connect ITEM file to outf

    cout << "Enter item name: ";
    char name[30];
    cin >> name; // get name from keyboard and

    outf << name << "\n"; // write to file ITEM

    cout << "Enter item cost: ";
    float cost;
    cin >> cost; // get cost from keyboard and

    outf << cost << "\n"; // write to file ITEM
    outf.close(); //disconnect item file from outf

    memset(name,0,sizeof(name));    //|
    cost = 0;                       //|clearing the variables ensures you can verify 100% that the value being printed come from the file.
    ifstream inf("ITEM");   //connect item file to inf

    inf >> name; // read name from file ITEM
    inf >> cost; // read cost from file ITEM
    cout << "\n";
    cout << "Item name: " << name << "\n";
    cout << "Item cost: " << cost << "\n";
    inf.close(); //disconnect ITEM from inf
    return 0;
}

/*
What memset(name,0,sizeof(name)) and cost = 0; really do.
1. memset(name,0,sizeof(name));
    This fills the entire name array with 0 bytes
    So the string becomes empty
    If you try to print name before reading form file, nothing will show.

2. cost = 0;
    This resets the number variable
    If you print cost before reading from the file, it will show 0.
*/
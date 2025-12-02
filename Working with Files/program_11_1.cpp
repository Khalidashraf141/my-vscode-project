// Creating files with constructor function
#include <iostream>
#include <fstream>
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

    ifstream inf("ITEM");   //connect item file to inf

    inf >> name; // read name from file ITEM
    inf >> cost; // read cost from file ITEM
    cout << "\n";
    cout << "Item name: " << name << "\n";
    cout << "Item cost: " << cost << "\n";
    inf.close(); //disconnect ITEM from inf
    return 0;
}
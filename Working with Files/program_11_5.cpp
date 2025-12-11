//  I/O Operations on Binary files
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

const char * filename = "BINARY";

int main()
{
    float height[4] = {175.5, 153.0, 167.25, 160.70};

    ofstream outfile;
    outfile.open(filename,ios::binary);
    outfile.write((char*)&height, sizeof(height));//We write (char*) because write() reads raw bytes, and a char* is the only pointer type that represents raw bytes in C++.
    outfile.close();    // close the file for reading

    for(int i = 0; i < 4; i++)  //clear array from memory (We clear the array so that we can prove infile.read() really restored the values from the binary file.)
    {
        height[i] = 0;
    }
    ifstream infile;
    infile.open(filename);
    infile.read((char*)&height, sizeof(height));

    for(int i = 0; i < 4; i++)
    {
        cout.setf(ios::showpoint);
        cout <<setw(10) <<fixed<< setprecision(2)<<height[i];
    }
    infile.close();

    return 0;
    
}
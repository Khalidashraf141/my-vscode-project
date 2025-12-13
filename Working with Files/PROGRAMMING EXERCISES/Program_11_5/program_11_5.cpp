/*Two files named 'Source1' and 'Source2' contain sorted list of integers. Write a program that reads the contents of both the file and stored the merged list in sorted form in a new file named 'Target'*/
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    string ch;
    ifstream fin1("source1.txt");
    ifstream fin2("source2.txt");
    ofstream fout("Target.txt");

    while(getline(fin1,ch))
    {
        fout << ch << "\n";
    }
    fin1.close();
    cout << "File1 writing completed" << "\n";

    while (getline(fin2,ch))
    {
        fout << ch << "\n";
    }
    fin2.close();
    cout <<"file 2 writing completed" << "\n";
    return 0;
    
}
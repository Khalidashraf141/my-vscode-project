#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main()
{
    const int SIZE = 80;
    char line[SIZE];

    ifstream fin1, fin2;    // create two input streams
    fin1.open("country");
    fin2.open("capital");

    for(int i = 1; i <= 10; i++)
    {
        if(fin1.eof()!=0)
        {
            cout << "Exit from country\n";
            return(0);
        }
        fin1.getline(line,SIZE);
        cout << "Capital of " << line << endl;

        if(fin2.eof() != 0)
        {
            cout << "Exit from capital\n";
            return(0);
        }
        fin2.getline(line,SIZE);
        cout << line <<"\n";
    }
    return 0;
}
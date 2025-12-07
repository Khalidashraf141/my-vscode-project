#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main(int argc, char *argv[])
{
    int number[9] = {11,22,33,44,55,66,77,88,99};

    if(argc != 3)
    {
        cout << "argc = " << argc << "\n";
        cout <<"Error in arguments\n";
        exit(1);
    }

    ofstream fout1, fout2;
    fout1.open(argv[1]);
    if(fout1.fail())
    {
        cout << "could not open the file"
             << argv[1] << "\n";
        exit(1);
    }

    fout2.open(argv[2]);
    if(fout2.fail())
    {
        cout << "could not open the file"
             << argv[2] << "\n";
        exit(1);
    }

    for(int i = 0; i < 9; i++)
    {
        if(number[i]%2==0)
        fout2 << number[i] << " ";
        else
        fout1 << number[i] <<" ";
    }
    fout1.close();
    fout2.close();


    ifstream fin;
    char ch;
    for(int i = 1; i < argc; i++)
    {
        fin.open(argv[i]);
        cout << "Contents fo " << argv[i] << "\n";
        do{
            fin.get(ch);
            cout << ch;
        }
        while(fin);
        cout << "\n\n";
        fin.close();
    }
    return 0;
}
/*
Like C, C++ also supports a feature that allows arguments to be supplied to the main() function. These arguments are supplied at the time of invoking the program form the command line.

Command line arguments are very useful for passing information such as the names of data files to the program.

For example, if the user types:
C> exam data result

then 'exam' is the program name, 'data' is the first argument, and 'result' is the second argument. These values are received by 

int main(int argc, char *argv[])

where argc is the number of arguments and argv is an array of character pointers storing each argument as a string.

*/
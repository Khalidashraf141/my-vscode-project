#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    // STEP 1: Create a file and write some text
    ofstream fout("demo.txt");
    fout << "HELLO WORLD! THIS IS A TEST FILE.";
    fout.close();

    // STEP 2: Open the file for reading
    ifstream fin("demo.txt");

    if(!fin){
        cout << "File not found!" << endl;
        return 1;
    }

    // STEP 3: Move the get pointer to position 10
    fin.seekg(10);

    // Print pointer position
    cout << "Pointer move to position: " << fin.tellg() << endl;

    // STEP 4: Read the character at that position
    char ch;
    fin.get(ch);

    cout << "Character at position 10 is: " << ch << endl;

    // STEP 5: Reading the rest of the file from that position
    cout << "\nRemaining file contents form position 10:\n";
    while(fin.get(ch))
    {
        cout << ch;
    }
    fin.close();

    return 0;
}
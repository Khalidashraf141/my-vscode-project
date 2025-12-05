/*
📌Specifying the Offset
When we move the file pointer using seekg() (input) or seekp() (output), we must provide two things:
    1.Offset (how much to move)
    A number (positive, negative or zero) telling how many bytes to move.

    2. Reference position (from where to move)
    One of these constants:
        • ios::beg -> from beginning of file
        • ios::cur -> from current pointer position
        • ios::end -> from end of file
    This combination is called "specifying the offset"

    seekg(offset, reference);
    seekp(offset, reference);

    1 Move to 10th byte form beginning
        infile.seekg(10, ios::beg);
    
    2 Move 5 bytes forward form current position
        infile.seekg(5, ios::cur);
    
    3 Move 3 bytes backward from current position
        infile.seekg(-3, ios::cur);
    
    4 Move 2 bytes backward from end
        infile.seekg(-2, ios::end);


!Important Points
    ✔️ Offset is measured in bytes
    Not characters (through for normal text, 1 char = 1 byte).

    ✔️ Negative offsets are allowed
    But only from ios::cur or ios::end

    if you only write:
        seekg(10);
    It automatically means:
        seekg(10,ios::beg) //default

Specifying the offset = telling the file pointer "move X bytes form Y position".


Where 
    • X = offset
    • Y = reference point (beg,cur,end)
*/

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream infile("text.txt");
    if(!infile)
    {
        cout << "File is not found!";
        return 0;
    }

    // Move to 5th byte from beginning
    infile.seekg(6, ios::beg);
    cout << "Byte 5 from beginning: " << (char)infile.get() << endl;

    // Move 3 bytes forward from current
    cout << infile.tellg()<<endl;
    infile.seekg(3, ios::cur);
    cout << "3 bytes after that: " << (char)infile.get() << endl;

    // Move 2 bytes before end
    infile.seekg(-2, ios::end);
    cout << "2nd last byte: " << (char)infile.get() << endl;


    fstream file("text.txt", ios::in | ios::out);
    if(!file)
    {
        cout << "file not found!";
        return 0;
    }

    // Move to 10th byte from beginning and overwrite
    file.seekp(10,ios::beg);
    file << "X";

    // Move 5 bytes form current and overwrite
    file.seekp(5, ios::cur);
    file << "Y";

    // Move 1 byte before end and overwrite
    file.seekp(-1, ios::end);
    file << "Z";

    //Read entire line
    infile.seekg(7, ios::beg);
    string rest;
    getline(infile,rest,'\0'); // read remaining file

    cout << rest;
    infile.close();
    return 0;
}
/*
1. Why do we need Errro Handling?
when working with files, many things can go wrong:
    • File does not exist
    • File cannot be opened
    • Error while reading
    • Error while writing
    • End-of-file (EOF) reached unexpectedly
    • File permissions not allowed
    • Disk full / no space
    • Binary data corrupted
To detect these problems, C++ provides error flags.


!Important File Error Flags in C++
Function/Flag               Meaning
fail()                      Operation failed (read/write/open)
good()                      No errors-file is working fine
eof()                       End Of File reached
bad()                       Serious error (hardware failure)
clear()                     Reset all error flags

*/

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    //Checking Before Opening a File
    ifstream file("data.txt");
    int obj;
    if(!file){
        cout << "Errro! File cannot be opened.\n";
        return 0;
    }
    //if(!file) means file opening failed.

    //Checking After Writing to File
    file.read((char*)&obj, sizeof(obj));
    if(!file){
        if(file.eof()){
            cout << "Reading End of File.\n";
        }
        else{
            cout << "Error while reading file.\n";
        }
    }
    /*
    When read fails, check:
        - was it because of EOF?
        - or some other errro?
    */


    // Checking After Writing to File
    // file.write((char*)&obj, sizeof(obj));
    if(!file){
        cout << "Errro writing to file!\n";
    }


    //Using good() to check stream status
    if(file.good())
    {
        cout << "File is ready for reading/writing.\n";
    }
    else{
        cout << "File errro occurred.\n";
    }





    /*
    When EOF happens, the files goes into fail state
    then any further operations stop working.
    */
    file.clear();
    //This resets:
        /*
            - eof flag
            - fail flag
            - bad flag
        now operations work again
        */
    
    //Checking bad() errro
    if(file.bad()){
        cout << "Fatal I/O errro occurred!\n";
    }
    /*
    This means:
        - disk erro
        - hardware problem
        - stream corruption
    
    */

}

/*
C++ file streams inherit a stream-state member from class ios.
This member uses bit fields to store error conditions related to file operations.
Possible errors include missing files, invalid filenames, insufficient disk space, invalid operations, and attemps to read past EOF.

The ios class provides member functions to test theses errro flags.
These functions are:
    1. eof()    - Returns true (non-zero value) if end-of-file is encountered while reading. Otherwise returns false(zero)

    2. fail()   returns true when an input or output operation has failed

    3. bad()    returns true if an invalid operation is attempted or any unrecoverable error
                has occurred. However, if it is false, it may be possible to recover from any other error reported, and continue operation.

    4. good()   returns true if no error has occurred. This means, all above functions are
                are false. for instance, if.good() is true, all is well with the stream file and we can proceed to perform I/O operations. When it returns false, no further operations can be carried out.


















*/
/*
✅What does "opening file mean?"
Opening a files means connecting your C++ program to a file on disk so you can read write, or both.

For this we use:
    ° ifstream → for reading
    ° ofstream → for writing
    ° fstream  → for both reading & writing

    🎯 Common File Opening Modes
    Mode                Meaning
    ios::in             Open for reading
    ios::out            Open for writing (overwrites file)
    ios::app            Append (write at end, don't erase old data)
    ios::binary         Binary file
    ios::ate            Open and move pointer to end
*/



#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    // ✔️ Using constructor method
    ifstream fin("data.txt"); // open for reading
    ofstream fout("result.txt"); // open for writing


    // ✔️ Using open() function
    ifstream fin;
    fin.open("data.txt");

    ofstream fout;
    fout.open("result.txt");


    fout.open("marks.txt",ios::app); // write at end, don't delete old data

    /*
    ! Why file opening matters
    if file doesn't open, your program cannot read/write
    */
    if(!fin){
        cout << "File not found!";
    }

    // Closing a file
    fin.close();
    fout.close();
    /*
    Closing a file:
        ° Flushes remaining data into file
        ° Disconnects file from program
        ° Release system resource
    */

    /*
    The first method is useful when we use only one file in the stream
    The second methods is used when we want to manage multiple files using one stream

    1.Constructor method
    */
    ifstream fin("data.txt");
    /*
    Why is this used for only one file?
    Because when you use the constructor, the stream is directly tied to that file
    You cannot reuse file to open another file later.
    */
    ifstream fin("data1.txt");
    fin.open("data2.txt"); //❌ NOT ALLOWED - constructor already opened the file
    /*
    so this method is good when:
        - you know the file name in advance
        - you need to open only one file with this stream
    */

    // 2. open() method
    ifstream fin;
    fin.open("data1.txt");
    fin.close();
    fin.open("data2.txt");
    /*
    Why is this good for multiple files?
    Because you can:
        - open one file
        - close it
        - then reuse the same stream to open another file
    */
   ifstream fin; // just created an empty stream
   fin.open("marks.txt"); // open file 1
   //read marks
   fin.close();

   fin.open("names.txt"); // open file 2
   //read names
   fin.close();
   //here one stream (fin) is used for multiple files.

   /*
   Constructor method -> stream is fixed to one file -> cannot change later
   open() method -> stream is reusable -> open many files one by one
   */


}
/*
Suitable name for file
A file must have a valid name according to the operating system.
Example:
    data.txt
    marks.dat
    report.csv
    student
A file name usually has two parts:
    ✔️ Primary name
    The main name
    example:
        data 
        marks
        student
    
    ✔️ Extension (optional)
    Comes after a period (.) tells the type of file
    example:
        .txt -> text file
        .dat -> data file
        .doc -> document file
        .bin -> binary file
    

        WRITE (output)
Program  --------->  outfile  --------->  results file

        READ (input)
Program  <---------  infile   <---------  data file
*/

/*
!important
Your computer (operating system) allows only a limited number of files to be open at the same time.
This limit is set by the Operating System (Windows/Linux/ect).
NOT by the C++ language or the compiler.

Example to understand
Suppose your system allows 256 files to be open simultaneously.
This means your program can open:
1 file
10 files
100 files
But NOT more than 256 at the same time.
if you try to exceed the limit, the file will fail to open

Why does this limitation exist?
    - a file descriptor
    - system memory
    - os resources
so the Operating System puts a limit to prevent the system from running out of resources.
!C++ simply uses whatever limit the system gives.
C++ compiler does not decide how many files can be opened
the limit still depends on the OS, not the compiler


*/
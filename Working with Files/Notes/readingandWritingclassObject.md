1. Why C (the old language) could NOT handle objects
In C language:
    • We have only primitive type(int,float,char..)
    • And struct, but no functions inside it
    • No concept of classes and objects
Therefore:
    ❌ C cannot write an entire object to a file in one step
    ❌ C has to write every member separately (roll, marks,etc).

2. C++ introduced classes and objects
In C++:
    • A class ≈ data + functions
    • An object ≈ memory block containing the data members
Example:
    class Student{
        int roll;
        float marks;
    };
Object memory layout:
    | roll (4 bytes) | marks (4 bytes) | <- 8 bytes total
These bytes represent the object.

3. How to save this object to a file?
You cannot save:
    • The class
    • The functions
    • The syntax
But you can save the data member values stored inside the object.

So C++ added special binary I/O functions:
    • write() -> write object bytes to file
    • read() -> read object bytes from file

4. What does write() really do?
    outfile.write((char*)&obj), sizeof(obj));
write() performs:
    "Copy this object's memory byte by byte to the file."

No conversion
No formatting
No checking
Just raw byte transfer

Example:
Object memory:
    | 0A 00 00 00 | 42 AB 00 00 |
        (roll=10)   (marks=85.5)
File will contain exactly those bytes.

5. read() does the reverse
    infile.read((char*)&obj,sizeof(obj));
read():
    "Copy bytes from file back into the object memory."
This reconstructs the object exactly.

6. Only data members are stored - not member functions
This is very important line:
    "Only data members are written to the disk file and the member functions are not."
Why?
Because:
    • Functions are not part of object memory
    • All objects share the same member functions
    • Member functions exist only once in program memory
    • Only data is unique for each object

Example:
class Student{
    int roll;
    float marks;
public:
    void getdata(); // function not stored in object
    void showdata(); // function not stored in object
};


Final Summary
✔️ C++ allows saving entire objects using binary I/O
✔️ write() copies object bytes to file
✔️ read() loads object bytes back
✔️ No conversion, no text formatting
✔️ Only data members are saved
✔️ Member functions are NOT saved (they are not part of object memory)
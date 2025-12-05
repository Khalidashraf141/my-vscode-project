#include <iostream>
#include <fstream>
using namespace std;

class Student
{
    int roll;
    float marks;
public:
    void getdata()
    {
        cout << "Enter roll and marks: ";
        cin >> roll >> marks;
    }

    void showdata()
    {
        cout << "Roll: " << roll << " Marks: " << marks << endl;
    }
};
/*
This class has 2 data members stored in memory:
    • int roll → usually 4 bytes
    • float marks → 4 bytes
    Total object size = 8 bytes(approx)
*/

int main()
{
    Student s;
    s.getdata();    //take input
    ofstream outfile("STUDENT.DAT",ios::binary);
    outfile.write((char*)&s, sizeof(s));
    outfile.close();
    /*
    ✔️ Why this works?
    • &s give the memory address of the entire object
    • sizeof(s) gives size in bytes (e.g., 8 bytes)
    • (char*)&s converts object address into a byte pointer.
    write() copies ALL bytes of the object into the file as they exist in memory.
    */

    //Reading the object back
    ifstream infile("STUDENT.DAT",ios::binary);
    infile.read((char*)&s,sizeof(s)); // read() only loads data into object memory - it does not print anything
    infile.close();
    s.showdata();
    return 0;
}

/*
⭐ Why cast (char)&s?
    • write() and read() only accept *char (byte pointer)
    • A class object has mixed data types(int,float)
    • We want to treat the whole object as raw bytes.

    (char*)&s -> "Treat this entire object as bytes no as int/float"


!important rule
    because binary writing copies only the raw bytes, not dynamic memory or pointers.
    But simple objects (only int,float,char,arrays) works perfectly.
*/
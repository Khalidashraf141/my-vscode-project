#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class emp
{
    char name[30]; // 30 bytes
    int ecode;  // 4 bytes
public:
    emp(){ }
    emp(const char *n, int c)
    {
        strcpy(name,n);
        ecode = c;
    }
};

int main()
{
    emp e[4];
    e[0] = emp("Amit",1);
    e[1] = emp("Khalid",2);
    e[2] = emp("Zero",3);
    e[3] = emp("Atlas",4);
    fstream file;
    file.open("Employee.dat",ios::in | ios::out | ios::trunc | ios::binary);

    int i;
    for(i = 0; i < 4; i++)
    {
        file.write((char*)&e[i], sizeof(e[i]));
    }
    // file.close(); don't use this after closing the file cannot give pointer positions, so tellg() return garbage.

    file.seekg(0,ios::end);
    int end = file.tellg();

    cout << "Number of objects stored in Employee.dat is:" << end/sizeof(emp);
    return 0;

}
/*
File size = 144 bytes
one object = 36 bytes
144 / 36 = 4 objects stored

*/
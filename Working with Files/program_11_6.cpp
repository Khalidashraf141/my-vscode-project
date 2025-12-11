#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

class INVENTORY
{
    char name[10];
    int code;
    float cost;
public:
    void readdata(void);
    void writedata(void);
};

void INVENTORY :: readdata(void)    //read from keyboard
{
    cout << "Enter name: "; cin >> name;
    cout << "Enter code: "; cin >> code;
    cout << "Enter cost: "; cin >> cost;
}

void INVENTORY :: writedata(void)
{
    cout << left
         << setw(10) << name
         << right
         << setw(10) << code
         <<fixed << setprecision(2)
         << right
         << setw(10) << cost
         << endl;
}

int main()
{
    INVENTORY item[3];          // Declare array of 3 objects

    fstream file;
    file.open("STOCK.DAT",ios::in | ios::out | ios::binary | ios::trunc);
    
    if(!file){
        cout << "FILE NOT OPENED! (open failed)" << endl;
    }
    else{
        cout << "FILE opened successfully!" << endl;
    }

    cout << "ENTER DETAILS FOR THREE ITEMS \n";
    for(int i = 0; i<3; i++)
    {
        item[i].readdata();
        file.write((char*)&item[i],sizeof(item[i]));
    }
    file.seekg(0);  // reset to start

    cout << "\nOUTPUT\n\n";
    for(int i = 0; i < 3; i++)
    {
        file.read((char*)&item[i],sizeof(item[i]));
        item[i].writedata();
    }
    file.close();
    return 0;
}
/*
!attention
    file.open("STOCK.DAT", ios::in | ios::out | ios::binary);
This mode does NOT create a new file unless it already exists.
so:
    • if STOCK.DAT was missing -> opening failed
    • if opening failed -> writing also failed
    • but the program still printing values (from memory), so you didn't notice
    When you added:
        iso::trunc
    so now:
        file.open("STOCK.DAT", ios::in | ios::out | ios::binary | ios::trunc);

        iso::trunc means:
         if the file does not exist -> create it
         if the file exists -> clear it completely (set size = 0)
        
         this ensures:
            file is always created
            file open successfully
            file writes and read correctly


file.open("STOCK.DAT", ios::out | ios::in | ios::binary | ios::trunc);

    file is create
    file is cleared
    file supports reading + writing
    data is stored in binary form

*/
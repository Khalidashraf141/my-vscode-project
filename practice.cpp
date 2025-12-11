#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

class Inventory
{
    char name[10];
    int code;
    float cost;
public:
    void getdata(void)
    {
        cout << "Enter name: "; cin >> name;
        cout << "Enter code: "; cin >> code;
        cout << "Enter cost: "; cin >> cost;
    }
    void putdata(void)
    {
        cout << setw(10) << name
             << setw(10) << code
             << setprecision(2) << setw(10) << cost << endl;
    }
};

int main()
{
    Inventory item;
    fstream inoutfile;

    inoutfile.open("STOCK.DAT",ios::ate | ios::in | ios::out | ios::binary);
    inoutfile.seekg(0,ios::beg);

    cout << "CURRENT CONTENTS OF STOCK" << "\n";
    while(inoutfile.read((char*)&item,sizeof(item)))
    {
        item.putdata();
    }
    inoutfile.clear();


    cout <<"\nADD AN ITEM\n";
    item.getdata();
    char ch;
    cin.get(ch);
    inoutfile.write((char*)&item,sizeof(item));
    inoutfile.seekg(0);

    cout << "CONTENTS OF APPEND FILE\n";

    while(inoutfile.read((char*)&item,sizeof(item)))
    {
        item.putdata();
    }

    inoutfile.clear();
    inoutfile.seekg(0,ios::end);
    int last = inoutfile.tellg();
    int n = last/sizeof(item);

    cout << "Number of objects = " << n << "\n";
    cout << "Total bytes in the file = " << last << "\n";

    cout << "Enter object number to be updated\n";
    int object;
    cin >> object;
    cin.get(ch);

    int location = (object-1) *sizeof(item);

    if(inoutfile.eof()){
        inoutfile.clear();
    }


}
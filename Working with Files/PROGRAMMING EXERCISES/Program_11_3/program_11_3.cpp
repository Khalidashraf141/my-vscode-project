/*Write a program that will create a data file containing the list of telephone numbers given in Exercise 11.2. Use a class object to store each set of data*/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;

class Telephone
{
    string name;
    string number;
public:
    void getdata()
    {
        cout << "Enter name: ";
        cin >> name;

        cout << "Enter phone number: ";
        cin >> number;
    }
    void writeToFile(fstream &fout)
    {
        fout << left << setw(15) << name << right << setw(10) << number << endl;
    }
};

int main()
{
    fstream fout;
    fout.open("telephone.txt",ios::out | ios::app);
    if(!fout)
    {
        cout << "Error creating file.\n";
        return 0;
    }

    int n;
    cout << "Enter the number of records: ";
    cin >> n;

    Telephone t;

    for(int i = 0; i < n; i++)
    {
        cout << "\nRecord " << i + 1 << endl;
        t.getdata();
        t.writeToFile(fout);
    }

    fout.close();

    cout << "\nData file 'telephone.txt' created successfully\n";
    return 0;
}
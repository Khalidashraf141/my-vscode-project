#include <iostream>
#include <vector>
#include <cstring>
#define NAMESIZE 40
using namespace std;

class EmployeeMaster
{
private:
    char name[NAMESIZE];
    int id;

public:
    EmployeeMaster()
    {
        strcpy(name, "");
        id = 0;
    }

    EmployeeMaster(const char n[], int id) : id(id)
    {
        strcpy(name, n);
    }

    void getValuesFromUser()
    {
        cout << "Enter user name: ";
        cin >> name;
        cout << "Enter user ID: ";
        cin >> id;
    }

    void displayRecord() const
    {
        cout << "\nName: " << name;
        cout << "\nID: " << id << endl;
    }
};

int main()
{
    vector<EmployeeMaster> emp;

    EmployeeMaster e1;
    e1.getValuesFromUser();
    emp.push_back(e1);

    emp[0].displayRecord();

    EmployeeMaster e2("AlanKay", 3);
    emp.push_back(e2);

    emp[1].displayRecord();

    return 0;
}

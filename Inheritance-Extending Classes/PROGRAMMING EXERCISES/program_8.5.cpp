/*
8.5 Question-> Consider a class network of Fig. 8.15. The class master derives information form both account and admin classes which in turn derive information form the class person. Define all the four classes and write a program to create, update and display the information contained in master objects
*/

#include <iostream>
#include <cstring>
using namespace std;

class Person
{
protected:
    string name;
    int code;
public:
    void get_person_data(void)
    {
        cout << "Enter name: ";
        getline(cin,name);
        cout << "Enter code: ";
        cin >> code;
        cin.ignore();
    }

    void show_person_data(void)
    {
        cout << "Name: " << name << endl;
        cout << "Code: " << code << endl;
    }
};

// Derived class from Person: account
class Account : virtual public Person
{
protected:
    float pay;

public:
    void get_account_data()
    {
        cout << "Enter pay: ";
        cin >> pay;
        cin.ignore();
    }

    void show_account_data()
    {
        cout << "Pay: " << pay << endl;
    }
};


class Admin: virtual public Person
{
protected:
    int experience;
public:
    void get_admin_data()
    {
        cout << "Enter experience (in years): ";
        cin >> experience;
        cin.ignore();
    }

    void show_admin_data()
    {
        cout << "Experience: " << experience << " years" << endl;
    }
};

//Derived from Account and Admin: Master
class Master : public Account, public Admin
{
public:
    void create()
    {
        cout << "\n--- Enter Master Record ---\n";
        get_person_data();
        get_account_data();
        get_admin_data();
    }

    void update()
    {
        cout << "\n--- Update Master Record ---\n";
        cout << "Enter new pay: ";
        cin >> pay;
        cout << "Enter new experience: ";
        cin >> experience;
        cin.ignore();
    }

    void display()
    {
        cout << "\n--- Displaying Master Record ---\n";
        show_person_data();
        show_account_data();
        show_admin_data();
    }
};

int main()
{
    Master m1;
    m1.create();
    m1.display();

    return 0;
}
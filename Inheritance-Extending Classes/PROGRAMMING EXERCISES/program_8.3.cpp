/*
8.3 Question -> An educational institution whishes to maintain a database of its employees. The database is divided into a member of classes whose hierarchical relationships are show in fig. 8.14. The figure also shows the minimum information required for each class. Specify all the classes and define functions to create the database and retrieve individual information as and when required.
*/

#include <iostream>
#include <cstring>
using namespace std;

// Base class
class Staff
{
    protected:
    int code;
    string name;
public:
    void getdata()
    {
        cout << "Enter code: ";
        cin >> code;
        cin.ignore(); //to ignore new line
        cout << "Enter name: ";
        getline(cin,name);
    }

    void display()const
    {
        cout << "Code: " << code << endl;
        cout << "Name: " << name << endl;
    }
};

// Derived class : Teacher
class Teacher : public Staff
{
    string subject;
    string publication;
public:
    void getdata()
    {
        Staff::getdata();
        cout << "Enter subject: ";
        getline(cin,subject);
        cout <<"Enter publication: ";
        getline(cin,publication);
    }

    void display()const{
        Staff::display();
        cout << "Subject: " << subject << endl;
        cout << "Publication: " << publication << endl;
    }
};

// Derived class: officer
class officer : public Staff
{
    string grade;
public:
    void getdata()
    {
        Staff::getdata();
        cout << "Enter grade: ";
        getline(cin,grade);
    }

    void display()const
    {
        Staff::display();
        cout << "Grade: " << grade << endl;
    }
};

// Derived class: Typist
class Typist : public Staff
{
    float speed; //typing speed
public:
    void getdata()
    {
        Staff::getdata();
        cout << "Enter typing speed (words per minute): ";
        cin >> speed;
    }

    void display()const{
        Staff::display();
        cout << "Typing Speed: " << speed << " wpm" << endl;
    }
};

// Subclass of Typist: Casual
class Casual : public Typist
{
    float daily_wages;
public:
    void getdata()
    {
        cout << "\n---- Enter Casual Typist Details ---\n";
        Typist::getdata();
        cout << "Enter daily wages: ";
        cin >> daily_wages;
    }

    void display()const{
        cout << "\n--- Casual Typist Details ---\n";
        Typist::display();
        cout << "Daily Wages: " << daily_wages << endl;
    }
};

// Subclass of Typist: Regular
class Regular: public Typist
{
    public:
        void getdata()
        {
            cout << "\n--- Enter Regular Typist Details ---\n";
            Typist::getdata();
        }

        void display()const{
            cout <<"\n--- Regular Typist Details ---\n";
            Typist::display();
        }
};

int main()
{
    Teacher t;
    officer o;
    Regular r;
    Casual c;

    cout << "\nEnter Teacher Details:\n";
    t.getdata();
    cout <<"\nEnter Officer Details:\n";
    o.getdata();
    r.getdata();
    c.getdata();

    cout <<"\n==============================\n";
    cout << "\nTeacher Details:\n";
    t.display();
    cout << "\nOfficer Details:\n";
    o.display();
    r.display();
    c.display();

    return 0;
}
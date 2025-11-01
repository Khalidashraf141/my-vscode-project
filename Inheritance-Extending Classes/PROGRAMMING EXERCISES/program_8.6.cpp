/*
8.6 Question-> In exercise 8.3, the classes teacher, officer, and typist are derived from the class staff. As we know, we can use container classes in place of inheritance in some situations. Redesign the program of Exercise 8.3 such that the classes teacher, officer, and typist contain the objects of staff.
*/

#include <iostream>
#include <cstring>
using namespace std;

// Base class : Staff
class Staff
{
    int code;
    string name;
public:
    void getdata()
    {
        cout << "Enter code: ";
        cin >> code;
        cin.ignore();
        cout << "Enter name: ";
        getline(cin,name);
    }

    void display()const{
        cout << "Code: " << code << endl;
        cout << "Name: " << name << endl;
    }
};

// education class
class education
{
    string general_qualification;
    string professional_qualification;
public:
    void getedu()
    {
        cout << "Enter highest general qualification: ";
        getline(cin,general_qualification);
        cout << "Enter professional qualification: ";
        getline(cin,professional_qualification);

    }

    void displayedu()const{
        cout << "General Qualification: " << general_qualification << endl;
        cout << "Professional Qualification " << professional_qualification << endl;
    }
};

// Derived-like class using containment
class Teacher
{
    education e;
    Staff s; // Contained Staff object
    string subject;
    string publication;
public:
    void getdata(void)
    {
        cout << "\n--- Enter Teacher Details ---\n";
        s.getdata(); // access Staff info
        cout << "Enter subject: ";
        getline(cin,subject);
        cout << "Enter publication: ";
        getline(cin,publication);
        e.getedu();
    }

    void display()const{
        cout << "\n--- Teacher Details ---\n";
        s.display();
        cout << "Subject: " << subject << endl;
        cout << "Publication: " << publication << endl;
        e.displayedu();
    }

};


class Officer
{
    education e;
    Staff s; // Contained Staff object
    string grade;
public:
    void getdata()
    {
        cout << "\n--- Enter Officer Details ---\n";
        s.getdata();
        cout << "Enter grade: ";
        getline(cin,grade);
        e.getedu();
    }

    void display()const{
        cout << "\n--- Officer Details ---\n";
        s.display();
        cout << "Grade: " << grade << endl;
        e.displayedu();

    }
};


class Typist
{
    Staff s;
    float speed;
public:
    void getdata()
    {
        cout << "\n--- Enter Typist Details ---\n";
        s.getdata();
        cout << "Enter typing speed (wpm): ";
        cin >> speed;
    }

    void display()const{
        cout << "\n--- Typist Details ---\n";
        s.display();
        cout << "Typing Speed: "<< speed << " wpm" << endl;
    }
};


class regular
{
    Typist t;
public:
    void getdata()
    {
        cout << "\n--- Enter Regular Typist Details --\n";
        t.getdata();
    }
    void display()const{
        cout << "\n--- Regular Typist Details ---\n";
        t.display();
    }

};


class casual
{
    Typist t;
    float daily_wages;
public:
    void getdata()
    {
        cout << "\n--- Enter Casual Typist Details ---\n";
        t.getdata();
        cout << "Enter daily wages: ";
        cin >> daily_wages;
    }

    void display()const{
        cout << "\n--- Casual Typist Details ---\n";
        t.display();
        cout << "Daily wages: " << daily_wages << endl;
    }
};


int main()
{
    Teacher t;
    t.getdata();
    t.display();

    return 0;
}

//Todo: all invalid input show error not crash the code
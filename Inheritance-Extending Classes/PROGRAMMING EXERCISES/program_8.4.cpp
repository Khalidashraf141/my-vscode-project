/*
8.4 Question -> The database created in Exercises 8.3 does not include educational information of the staff. It has been decided to add this information to teachers and officers (and not for typists) which will help the help the management in decision making with regard to training, promotion etc. Add another data class called education the holds two pieces of education information, namely, highest qualification in general education in and highest professional qualification. This class should be inherited by the class teacher and officer. Modify the program of Exercise 8.19 to incorporate additions.
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
    void getdata(void)
    {
        cout <<"Enter Code: ";
        cin >> code;
        cin.ignore();
        cout <<"Enter Name: ";
        getline(cin,name);
    }

    void display()
    {
        cout << "Code: " << code << endl;
        cout << "Name: " << name << endl;
    }
};

//education class
class education
{
protected:
    string general_qualification;
    string professional_qualification;
public:
    void getedu()
    {
        cout << "Enter highest general qualification: ";
        getline(cin,general_qualification);
        cout << "Enter highest professional qualification: ";
        getline(cin,professional_qualification);
    }

    void displayedu()const{
        cout <<"General Qualification: " << general_qualification << endl;
        cout <<"Professional Qualification: " << professional_qualification << endl;
    }
};

//Derived class Teacher
class Teacher : public Staff , public education
{
protected:
    string subject;
    string publication;
public:
    void getdata(void)
    {
        Staff::getdata();
        cout << "Enter subject: ";
        getline(cin,subject);
        cout << "Enter publication: ";
        getline(cin,publication);
        education::getedu();
    }

    void display(void)
    {
        Staff::display();
        cout << "Subject: " << subject << endl;
        cout << "Publication: " << publication << endl;
        education::displayedu();
    }
};


//Derived Class Officer
class officer : public Staff , public education
{
protected:
    string grade;
public:
    void getdata(void)
    {
        Staff::getdata();
        cout << "Enter grade: ";
        getline(cin,grade);
        education::getedu();
    }

    void display(void)
    {
        cout << "================================";
        cout << "\n----- Officer Details -----\n";
        Staff::display();
        cout <<"Grade: " << grade << endl;
        education::displayedu();
        cout << "================================";
    }
};


//Derived class
class typist : public Staff
{
protected:
    float speed;
public:
    void getdata(void)
    {
        Staff::getdata();
        cout << "Enter typing speed (words per minute): ";
        cin >> speed;
    }

    void display(void)
    {
        Staff::display();
        cout << "Typing speed: " << speed << " wpm" << endl;
    }

};


class casual : public typist
{
protected:
    float daily_wages;
public:
    void getdata(void)
    {
        cout << "\n--- Enter Casual Typist Details ---\n";
        typist::getdata();
        cout <<"Enter daily wages: ";
        cin >> daily_wages;
    }

    void display(void)
    {
        cout << "\n--- Casual Typist Details ---\n";
        typist::display();
        cout << "Daily wages: " << daily_wages << endl;
    }

};

//regular derived class
class regular : public typist
{
    public:
        void getdata(void)
        {
            cout << "\n--- Enter Regular typist Details ---\n";
            typist::getdata();
        }

        void display(void)
        {
            cout << "\n--- Regular typist Details ---\n";
            typist::display();
        }
};

int main()
{
    Teacher t;
    officer o;
    regular r;
    casual c;

    cout << "\nEnter teacher details\n";
    t.getdata();
    cout << "\nEnter officer details\n";
    o.getdata();
    r.getdata();
    c.getdata();
    cout << "\n\n";

    cout << "\n==========================\n";
    cout << "--- Teacher Details ---\n";
    t.display();
    cout << "\n--- Officer Details ---\n";
    o.display();
    r.display();
    c.display();

    return 0;

}
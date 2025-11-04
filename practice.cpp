#include <iostream>
#include <cstring>
#include <sstream>
using namespace std;

// Generic function for integer input with validation
int getValidatedInt(const string &prompt)
{
    string input;
    double value;

    while(true){
        cout << prompt;
        getline(cin,input);
        stringstream ss(input);

        if(ss >> value &&  ss.eof()){
            return value;
        }else{
            cout << "Invalid input! Please enter a valid integer.\n";
        }


    }
}



class staff
{
    protected:
        int code;
        string name;
    public:
        void getdata()
        {
            code = getValidatedInt("Enter code: ");
            cout << "Enter name: ";
            getline(cin,name);
        }

        void display(void)const
        {
            cout << "Code: " << code << endl;
            cout << "Name: " << name << endl;
        }
};

class Teacher: public staff
{
    string subject;
    string publication;
public:
    void getdata()
    {
        staff::getdata();
        cout<<"Enter subject: ";
        getline(cin,subject);
        cout<<"Enter publication: ";
        getline(cin,publication);
    }
    void display()const{
        staff::display();
        cout<<"Subject: " <<subject <<endl;
        cout<<"Publication: " << publication << endl;
    }
};

class officer : public staff
{
    string grade;
public:
    void getdata()
    {
        staff::getdata();
        cout << "Enter grade: ";
        getline(cin,grade);
    }
    void display(void)const{
        staff::display();
        cout << "Grade: " << grade << endl;
    }
};

class typist : public staff
{
    float speed; 
public:
    void getdata()
    {
        staff::getdata();
        cout << "Enter typing speed (words per minute): " ;
        cin >> speed;
    }

    void display(void)const{
        staff::display();
        cout << "Typing Speed: " << speed << " wpm" << endl;
    }
};

class Casual : public typist
{
    float daily_wages;
public:
    void getdata()
    {
        cout << "\n----- Enter Casual Typist Details ----\n";
        typist::getdata();
        cout << "Enter daily wages: ";
        cin >> daily_wages;
    }

    void display()const{
        cout << "\n--- Casual Typist Details ---\n";
        typist::display();
        cout <<"Daily Wages: " << daily_wages << endl;
    }
};

class Regular : public typist
{
    public:
        void getdata()
        {
            cout << "\n---- Enter Regular Typist Details ---\n";
            typist::getdata();
        }

        void display()const{
            cout << "\n--- Regular Typist Details ---\n";
            typist::display();
        }
};


int main()
{
    Teacher t;

    cout << "\nEnter Teacher Details: \n";
    t.getdata();
    cout << "\n\nTeacher Details: \n";
    t.display();

    return 0;
}
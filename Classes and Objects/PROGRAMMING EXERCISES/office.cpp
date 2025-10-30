//Write a program to take the input to faculty details (ID, name, post, qualification, address) and display it.
#include <iostream>
#include <string>
using namespace std;

class Office
{
    int ID;
    string name, post, qualification, address;
    public:
        void input()
        {
            cout << "Enter your name: ";
            getline(cin,name);
            cout << "Enter your Post: ";
            getline(cin, post);
            cout << "Enter your Qualification: ";
            getline(cin,qualification);
            cout << "Enter your address: ";
            getline(cin,address);
        }
        void display()
        {
            cout << "\nName: " << name << "\n";
            cout << "Post: " << post << "\n";
            cout << "Qualification: " << qualification << "\n";
            cout << "Address: " << address << "\n";
        }
    
};

int main()
{
    Office emp_1;
    emp_1.input();
    emp_1.display();
    return 0;
}
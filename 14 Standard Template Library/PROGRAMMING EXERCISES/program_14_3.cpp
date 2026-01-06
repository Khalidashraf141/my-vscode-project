/*
Create a student class that includes a a student's first name and his roll_number. Create five objects of this class and store them in a list thus creating a phone_list. Write a program using this list to display the student name if the roll_number is given and vice versa.
*/

#include <iostream>
#include <list>
#include <string>
using namespace std;

class Student
{
private:
    string first_name;
    int roll_number;
public:
    Student(string name, int roll)
    {
        first_name = name;
        roll_number = roll;
    }
    string getName()const{
        return first_name;
    }
    int getRoll()const{
        return roll_number;
    }
};

int main()
{
    list<Student>phone_list;
    phone_list.push_back(Student("Aman",101));
    phone_list.push_back(Student("Ravi",102));
    phone_list.push_back(Student("Neha",103));
    phone_list.push_back(Student("Sita",104));
    phone_list.push_back(Student("Rahul",105));
    
    int roll;
    cout << "Enter roll number: ";
    cin >> roll;

    for(const auto &s: phone_list)
    {
        if(s.getRoll() == roll)
        {
            cout << "Student Name: " << s.getName() << endl;
        }
    }

    string name;
    cout << "Enter student name: ";
    cin >> name;

    for(const auto& s : phone_list)
    {

        try{
            if(s.getName() == name)
            {
                cout << "Roll Number: " << s.getRoll();
            }
            throw 10;
        }catch(int)
        {
            cout << "\nInvalid Name";
            break;
        }
        
    }
    

    return 0;
    
}
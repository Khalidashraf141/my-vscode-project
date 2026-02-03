#include <iostream>
#include <string>
using namespace std;

class Student{
    private:
        string studentName,bookName;
        int rollNumber, noOfDays ;
    public:
        void showAllBooks(){}
        void findBook(){
            cout << "Enter book name : ";
            getline(cin,bookName);
        }
        
};
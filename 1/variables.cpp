#include <iostream>
using namespace std;

int main(){
    int myage = 18;
    char word = 'A';
    string myname = "Khalid";
    bool myBoolean = true;
    double myNum = 16.5;
    int x = 5, y = 6, z = 50;
    const int minutesPerHour = 60;
    
    cout<< minutesPerHour<<endl;
    cout << x + y + z<< endl;
    cout<< "My age is: "<< myage<< endl;
    cout<< word<< endl;
    cout<< myname<< endl;
    cout<< myBoolean<< endl;
    cout<< myNum<< endl;

    //Student data
    int studentID = 15;
    int studentAge = 23;
    float studentFee = 75.25;
    char studentGrade = 'B';

    cout<< "Student ID: " << studentID << endl;
    cout<< "Student Age: " << studentAge << endl;
    cout<< "Student Fee: " << studentFee << endl;
    cout << "Student Grade " << studentGrade << endl;

    //Calculate the Area of a Rectangle
    int length = 4;
    int width = 6;

    int area = length * width;

    cout<< "Length is: "<< length << endl;
    cout<< "Width is: "<< width << endl;
    cout<< "Are of the rectangle is: "<< area << endl;

    return 0;
}
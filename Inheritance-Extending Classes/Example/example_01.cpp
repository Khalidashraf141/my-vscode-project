// 1. Single Inheritance -> One base class and one derived class
#include <iostream>
using namespace std;

class Parent
{
    public:
        void display(){
            cout << "This is Parent class." << "\n";
        }
};

class Child : public Parent{
    public:
        void show(){
            cout << "This is Child class." <<"\n";
        }
};

int main()
{
    Child obj;
    obj.display();
    obj.show();
    return 0;
}
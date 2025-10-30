//Multilevel Inheritance -> One class inherits from another derived class (like a chain)
#include <iostream>
using namespace std;

class Grandparent{
    public:
        void legacy(){
            cout << "Grandparent's legacy." << "\n";
        }
};

class Parent : public Grandparent{
    public:
        void care(){
            cout << "Parent's care." << "\n";
        }
};

class Child : public Parent{
    public:
        void dream(){
            cout << "Child's dream." << "\n";
        }
};

int main()
{
    Child obj;
    obj.legacy();
    obj.care();
    obj.dream();

    return 0;
}
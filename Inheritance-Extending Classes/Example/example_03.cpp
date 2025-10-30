// Hierarchical Inheritance -> Multiple classes inherit from the same base class
#include <iostream>
using namespace std;

class Parent{
    public:
        void property(){
            cout << "Parent's property." << "\n";
        }
};

class Son : public Parent{
    public:
        void SonFeature(){
            cout << "Son's feature." << "\n";
        }
};

class Daughter : public Parent{
    public:
        void daughterFeature(){
            cout << "Daughter's feature." << "\n";
        }
};

int main()
{
    Son s1;
    Daughter d1;

    s1.property();
    d1.property();
    s1.SonFeature();
    d1.daughterFeature();
    return 0;
}
// Multiple Inheritance -> One class derived from two or more base classes.
#include <iostream>
using namespace std;

class Father{
    public:
        void fatherFeature(){
            cout << "Feature from Father." << "\n";
        }
};

class Mother{
    public:
        void motherFeature(){
            cout << "Feature from Mother." << "\n";
        }
};

class Child: public Father, public Mother{
    public:
        void ownFeature(){
            cout << "Feature of Child." << "\n";
        }
};

int main()
{
    Child obj;
    obj.fatherFeature();
    obj.motherFeature();
    obj.ownFeature();

    return 0;
}
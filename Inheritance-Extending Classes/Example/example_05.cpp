// Hybrid Inheritance -> Combination of two or more types of inheritance

#include <iostream>
using namespace std;

class A{
    public:
        void msgA(){
            cout << "Class A" << "\n";
        }
};

class B: public A{
    public:
        void msgB(){
            cout << "Class B inherits from A" << "\n";
        }
};

class C{
public:
    void msgC(){
        cout << "Class C" << "\n";
    }
};


class D: public B, public C{
    public:
        void msgD(){
            cout << "Class D inherits from B and C" << "\n";
        }
};

int main()
{
    D obj;
    obj.msgA();
    obj.msgB();
    obj.msgC();
    obj.msgD();

    return 0;
}




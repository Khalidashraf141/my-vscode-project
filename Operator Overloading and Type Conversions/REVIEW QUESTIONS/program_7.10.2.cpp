//Option 2: Conversion Function in Y
// Y knows how to convert itself into X
#include <iostream>
using namespace std;

class X
{
    int value;
public:
        X(){}
        X(int v){value = v;}
        void display()
        {
            cout << "Value in X: " << value << "\n";
        }
};

class Y
{
    int data;
public: 
    Y(int d){data = d;}

    // conversion function: converts Y -> X
    operator X()
    {
        return X(data);
    }
};

int main()
{
    Y b(10);
    X a;

    a = b; // works because Y can convert itself into X

    a.display();

    return 0;
}

//TODO:PRACTICE AND UNDERSTAND


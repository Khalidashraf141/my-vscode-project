#include <iostream>
using namespace std;

class P
{
    public:
        P(){
            cout << "Inside the constructor\n";
            try{
                throw "m";
            }
            catch(...){
                cout << "What is this?\n";
            }
            cout << "still inside the constructor\n";
        }
        ~P(){
            cout << "Inside the destructor\n";
        }
};

int main()
{
    try{
        P var;
        throw "Q";
    }
    catch(...)
    {
        cout << "Exception: Ends \n";
    }
    cout << "Exit point\n";
    return 0;
}

/*
output:
    Inside the constructor
    What is this?
    still inside the constructor
    Inside the destructor
    Exception: Ends
    Exit point
*/
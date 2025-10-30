//Debugging Exercise -- all of the data was private member functions and variable so we make the function add and int p q r s private and other and make other function public...
#include <iostream>
using namespace std;

class addition
{
    int p,q,r,s;                                                      
    int add(void)
    {
        s = p+q+r;
        return (s);          //here is good good encapsulation (hiding internal details, exposing only required interfaces)
    }
    public:
    void input(void)
    {
        cout << "Enter the three number: ";
        cin >> p >> q >> r;
    }
    void show(void)
    {
        cout << "the addition of three numbers is :" << add() << "\n";
    }
};



int main()
{
    addition x;
    x.input();
    x.show();
    return 0;
}
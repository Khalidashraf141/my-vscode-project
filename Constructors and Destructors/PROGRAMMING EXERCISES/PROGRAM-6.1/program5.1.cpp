#include <iostream>
using namespace std;

class item
{
    int number;
    float cost;
    public:
        item(int a = 0, float b = 0.0) //constructor with default values
        {
            number = a;
            cost = b;
        }
        //Function defined inside class
        void putdata(void)
        {
            cout << "number :" << number << "\n";
            cout << "cost   :" << cost   << "\n";
        }
};



//................Main Program...............................
int main()
{
    item x(100,20.7);
    cout << "Implementing Constructor\n";

    cout << "\nobject x " << "\n";
    x.putdata();

    item y(400,78.2);
    cout << "\nobject y" << "\n";
    y.putdata();

    return 0;
}
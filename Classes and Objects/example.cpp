#include <iostream>
using namespace std;

class item
{
    int number;
    float cost;
    public:
        void getdata(int a, float b)
        {
            number = a;
            cost = b;
        }
        void putdata(void)
        {
            cout << "number :" << number << "\n";
            cout << "cost :" << cost << "\n";
        }
};

int main()
{
    item x;
    cout << "\nObject x" << "\n";
    x.getdata(17,7.8);
    x.putdata();

    item y;
    cout << "\nObject y" << "\n";
    y.getdata(8,9.5);
    y.putdata();
    
    return 0;
}
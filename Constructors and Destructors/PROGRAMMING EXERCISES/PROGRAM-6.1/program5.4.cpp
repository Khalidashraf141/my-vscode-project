#include <iostream>
using namespace std;

class item
{
    static int count;
    int number;
    public:
        item(){ }  //default constructor
        item(int a) //one parameterised constructor
        {
            number = a;
            count++;
        }

        void getcount(void)
        {
            cout << "count: ";
            cout << count << "\n";
        }
};

int item :: count;

int main()
{
    item a, b, c;
    a.getcount();
    b.getcount();
    c.getcount();

    item z(20), q(30), r(50);


    cout << "After reading data" << "\n";

    z.getcount();
    q.getcount();
    r.getcount();

    return 0;
}
//FIXME:DONE 
//ERROR: Practice default constructor
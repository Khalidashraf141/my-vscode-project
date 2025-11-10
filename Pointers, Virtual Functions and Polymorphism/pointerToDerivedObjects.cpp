#include <iostream>
using namespace std;

class BC
{
    public:
        int b;
        void show()
        {
            cout << "b = " << b << "\n";
        }
};

class DC : public BC
{
    public:
        int d;
        void show()
        {
            cout <<"b = " << b << "\n"
                 <<"d = " << d << "\n";
        }
};

int main()
{
    BC *bptr;           //base pointer
    BC base;
    bptr = &base;       //base address

    bptr->b = 100;    //access BC via base pointer
    cout << "bptr points to base object \n";
    bptr->show();


    //Derived class
    DC derived;
    bptr = &derived;    //access of derived object
    bptr->b = 200;      //access DC via base pointer

    /* bptr->d = 300; */ //won't work
    cout << "bptr now points to derived object \n";
    bptr->show();   //bptr now points to derived object

    /*accessing d using a pointer of type derived class DC */
    DC *dptr;
    dptr = &derived;
    dptr->d = 300;

    cout << "dptr is derived type pointer\n";
    dptr->show();


    cout<< "using ((DC *)bptr)\n";
    ((DC *)bptr)->d= 400;
    ((DC *)bptr)->show();
    return 0;


}
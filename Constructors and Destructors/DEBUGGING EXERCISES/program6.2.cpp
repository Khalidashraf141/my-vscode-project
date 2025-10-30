#include <iostream>
using namespace std;
class dynamic
{
    int *p;
    public:
    dynamic()
    {
        p = new int;
        *p = 10;
    }
    dynamic(int v)
    {
        p = new int; //error was without allocating memory how can we store something
        *p  = v;
    }
    int display()
    {
        return (*p);
    }
    ~dynamic()
    {
        cout << "\nDestructor Msg: Freeing memory....";
        delete p;
    }
};

int main()
{
    dynamic p1, p2(9);
    cout << "object p1 is:";
    cout << p1.display();
    cout << "\nobject p2 is:" << p2.display()<<"\n";
    return 0;

}
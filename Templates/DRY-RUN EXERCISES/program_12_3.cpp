#include <iostream>
using namespace std;

template<class T = float>
class A
{
    T x;
public:
    A(){x = 25;}
    A(T y) {x = y;}
    void display()
    {
        cout << x << endl;
    }
};

int main()
{
    A<>obj1;
    A<int>obj2;
    A<int>obj3(35);
    A<>obj4(55.0);

    obj1.display();
    obj2.display();
    obj3.display();
    obj4.display();
    return 0;
}
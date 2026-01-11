#include <iostream>
using namespace std;

template<typename T>
class demo1
{
    T x;
    public:
        demo1(T d){x = d;}
        void display()
        {
            cout << x << "\n";
        }
};

template<class T>
class demo
{
    T x;
    public:
        demo (T d){x = d;}
        void display()
        {
            cout << x << "\n";
        }
};

int main()
{
    demo1<int>obj1(20);
    obj1.display();
    demo<int>obj2(20);
    obj2.display();
    return 0;
}
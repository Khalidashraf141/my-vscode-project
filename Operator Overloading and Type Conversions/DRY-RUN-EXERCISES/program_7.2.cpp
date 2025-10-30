#include <iostream>
using namespace std;

class demo
{
    int data;
public:
    demo(int d)
    {
        data = d;
    }
    void show()
    {
        cout << "\nValue = " << data;
    }
    friend void operator-(demo d);
};

void operator-(demo d) //its make a copy on member variable you have to pass by reference then it will work
{
    d.data = -d.data; //funciton end copy will destroyed and also it will not make changes in the orignianl member variable
}

int main()
{
    demo ob(10);
    ob.show();

    -ob;
    ob.show();

    return 0;
}
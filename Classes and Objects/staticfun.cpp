#include <iostream>
using namespace std;

class test
{
    int code;
    static int count;
    public:
    void setcode(void)
    {
        code = ++count;
    }

    void showcode(void)
    {
        cout << "object number: " << code << "\n";
    }

    static void showcount(void)
    {
        cout << "count: " << count << "\n";
    }
};

int test :: count;

int main()
{
    test t1, t2;
    t1.setcode();
    t2.setcode();

    test :: showcount();

    test t3;
    t3.setcode();

    test :: showcount();

    t1.showcode();
    t2.showcode();
    t3.showcode();
    return 0;
}

/*
code = ++count;
is executed whenever setcode() function is invoked and the current value of count is assigned to code. Since each object has its own copy of code, the value contained in code represents a unique number of its object.
*/
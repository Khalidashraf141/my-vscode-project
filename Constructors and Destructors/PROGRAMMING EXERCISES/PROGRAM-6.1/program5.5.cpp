#include <iostream>
using namespace std;

class test
{
    int code;
    static int count;
    public:
    test(void)  //constructor
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

int test:: count;
int main()
{
    test t1, t2;

   

    test :: showcount();

    test t3;


    test :: showcount();

    t1.showcode();
    t2.showcode();
    t3.showcode();

    return 0;
}
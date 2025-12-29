/*Write a main program that calls a deeply nested function containing an exception. Incorporate necessary exception handling mechanism*/
#include <iostream>
using namespace std;

void level3()
{
    cout << "Inside level3()" << endl;
    throw runtime_error("Exception throw in level3");
}

void level2()
{
    cout << "Inside level2()" << endl;
    level3();
}

void level1()
{
    cout << "Inside level1()" << endl;
    level2();
}

int main()
{
    cout << "Program started" << endl;

    try{
        level1();
    }
    catch(const runtime_error &e)
    {
        cout << "Exception caught in main(): " << e.what() << endl;
    }
    catch(...)
    {
        cout << "Unknown exception caught" << endl;
    }

    cout << "Program continues after exception handling" << endl;
    return 0;
}
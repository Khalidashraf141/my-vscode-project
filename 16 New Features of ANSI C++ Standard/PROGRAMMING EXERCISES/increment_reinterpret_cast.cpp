/*
Write a program in which increment in pointer should demonstrate increment in integer using reinterpret_cast operator
*/
#include <iostream>
using namespace std;

int main()
{
    int x = 10;

    // Original integer pointer
    int* p = &x;

    // Reinterpret int pointer as char pointer
    char* cp = reinterpret_cast<char*>(p);

    // Reinterpret back to int pointer
    int* ip = reinterpret_cast<int*>(cp);

    //Increment integer through reinterpreted pointer
    (*ip)++;
    cout << "Value of x after increment: " << x << endl;

    return 0;
}
#include <iostream>
#include <chrono>
#include <thread>
using namespace std;

int main()
{
    cout << "Loading..."; //stays in buffer
    this_thread::sleep_for(chrono::seconds(3));
    cout << "\nDone";
    return 0;
}
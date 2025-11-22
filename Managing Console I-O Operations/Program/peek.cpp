#include <iostream>
using namespace std;

int main()
{
    cout << "Enter input: ";
    char c = cin.peek();

    cout << "Peeked char = " << c << endl;

    return 0;
}
/*
Output:-
    Enter input: Khalid
    Peeked char = K
*/
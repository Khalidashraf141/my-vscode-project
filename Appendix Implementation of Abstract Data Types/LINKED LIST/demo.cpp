#include <iostream>
#include "linkedlist.h"
using namespace std;

int main()
{
    List ll;

    ll.push_front(10);
    ll.printLL();
    cout << ll.search(10);
    
    return 0;
}
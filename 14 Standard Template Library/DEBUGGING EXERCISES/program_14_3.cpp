#include <iostream>
#include <list>
int main()
{
    std::list<int>l1;
    l1.push_front(10);
    l1.push_back(20);
    l1.push_front(30);
    l1.push_front(40);
    l1.push_back(10);
    l1.pop_front();

    l1.reverse();
    l1.unique();    // removes consecutive duplicates only
    for(int x : l1)
        std::cout << x << " ";
    return 0;

}
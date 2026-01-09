#include <iostream>
using namespace std;
class demo
{
    mutable int count;
    int y;
public:
    explicit demo(int d)
    {
        count = 0;
        y = 20;
    }
    void display() const{
        count++;
        cout << count << " " << y << "\n";
    }
};

int main()
{
    demo a(10);
    a.display();
    a.display();
    a.display();
    return 0;
}
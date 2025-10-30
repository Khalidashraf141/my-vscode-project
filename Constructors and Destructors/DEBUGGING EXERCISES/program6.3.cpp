#include <iostream>
using namespace std;

class des
{
    public:
    des(int x)
    {
        cout << "start value " << x << "\n";
    }

    ~des() //FIXME: Destructor never take parameters
    {
        cout << "hi";
    }
};

int main()
{
    des d1(10);
    return 0;
}
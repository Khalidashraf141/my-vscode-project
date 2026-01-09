#include <iostream>
using namespace std;

class ABC
{
    private:
        mutable int m;      // mutable member
    public:
        explicit ABC(int x = 0)
        {
            m = x;
        }
        void change()const{
            m = m + 10;
        }
        int display()const{
            return m;
            
        }
};

int main()
{
    const ABC abc(100); //const object
    cout << "abc contains: " << abc.display();

    abc.change();
    cout << "\nabc now contains: " << abc.display();

    cout << "\n";
    return 0;
}
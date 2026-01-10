#include <iostream>
using namespace std;

namespace Classes
{
    class Test
    {
        private:
            int m;
        public:
            Test(int a)
            {
                m = a;
            }
            void display()
            {
                cout << "m = " << m << "\n";
            }
    };
}

int main()
{
    //using scope resolution
    Classes::Test T1(200);
    T1.display();

    //using directive
    using namespace Classes;
    Test T2(400);
    T2.display();
    return 0;
}
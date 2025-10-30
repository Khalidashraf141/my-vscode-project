#include <iostream>
using namespace std;

class item
{
    int coustmerid;
    float cost;
    public:
        void getdata(int a, float b);
        void putdata(void)
        {
            cout << "Coustmer id: " << coustmerid << "\n";
            cout << "Total cost is: " << cost << "\n";
        }
};
void item::getdata(int a, float b)
{
    coustmerid = a;
    cost = b;
}
int main()
{
    item coustmer_01;
    cout << "\nCoustmer 01\n";
    coustmer_01.getdata(23421,7554.98);
    coustmer_01.putdata();

    item coustmer_02;
    cout <<"\nCoustmer 02\n";
    coustmer_02.getdata(45333,8985.76);
    coustmer_02.putdata();
    return 0;
}
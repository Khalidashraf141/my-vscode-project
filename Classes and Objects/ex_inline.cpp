#include <iostream> //khalid esme input loo user se in terminal s
using namespace std;

class item 
{
    string customerName;
    int customerId;
    float totalcost;
    public:
        void getdata(string a, int b, float c);
        void putdata(void)
        {
            cout << "Customer Name is: " << customerName << "\n";
            cout << "Customer Id is: " << customerId << "\n";
            cout << "The total cost is: " << totalcost << "\n";
        }
};

inline void item::getdata(string a, int b, float c)
{
    customerName = a;
    customerId = b;
    totalcost = c;
}

int main()
{
    item customer_01;
    cout << "\nCustomer 01\n";
    customer_01.getdata("Khalid Ashraf",121,876.9);
    customer_01.putdata();

    return 0;
}
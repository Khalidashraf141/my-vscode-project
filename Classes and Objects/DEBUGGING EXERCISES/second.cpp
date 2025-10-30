#include <iostream>
using namespace std;

class weight
{
    int liter,ML;
    public:
    void getdata(void);
    void putdata(void);
    void sum_of_weight(weight,weight);
};

void weight :: getdata(void)
{
    cout << "in liter:";
    cin >> liter;
    cout << "in ML:";
    cin >> ML;
}

void weight :: putdata(void)
{
    cout << liter << " Liter " << ML << " ML ";
}

void weight :: sum_of_weight(weight w1, weight w2)
{
    ML = w1.ML + w2.ML;
    liter = ML/1000;
    ML = ML%1000;
    liter+= w1.liter + w2.liter;
}

int main()
{
    weight w1, w2, w3;
    cout << "Enter weight in Letter and ML\n";
    cout << "Enter the weight 1 ";
    w1.getdata();
    cout << "Enter the weight 2 ";
    w2.getdata();
    w3.sum_of_weight(w1,w2); //error was sum_of_weight is a class member function we can't directly call it
    cout << "Total weight: ";
    w3.putdata();
    return 0;
}
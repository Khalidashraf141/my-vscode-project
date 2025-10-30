#include <iostream>
#include <vector>
using namespace std;

class MyVector
{
    vector<float> values; // holds float values

    public:
    //Create vector of given size and initial value
        void create(int size, float initialValue = 0.0f)
        {
            values.resize(size, initialValue);
        }
    
    //Modify the value at a given index
        void modify(int index, float newValue)
        {
            if(index >= 0 && index < values.size())
            {
                values[index] = newValue;
            }
            else
            {
                cout << "Error: Index out of range!\n";
            }
        }
    
    // Multiply the vector by a scalar
        void multiply(float scalar)
        {
            for(int i = 0; i < values.size(); i++)
            {
                values[i] *=scalar;
            }
        }
    
    // Display vector in form (10,20,30)
        void display()
        {
            cout << "(";
            for(int i = 0; i < values.size(); i++)
            {
                cout << values[i];
                if(i< values.size() - 1)
                {
                    cout << ",";
                }
            }
            cout << ")\n";
        }


};

int main()
{
    MyVector v;

    v.create(3);
    v.modify(0,10.0f);
    v.modify(1,20.0f);
    v.modify(2,70.0f);

    v.display();
    return 0;
}
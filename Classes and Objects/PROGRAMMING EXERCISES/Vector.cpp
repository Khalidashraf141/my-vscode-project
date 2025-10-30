#include <iostream>
#include <vector>
using namespace std;

class Vector
{
    vector<float> values;
    vector<float> result;
    public:
    //Create
        void create(int size, float initialValues = 0.0f)
        {
            values.resize(size,initialValues);
        }
    //Modify
        void modify(int index, float newValue)
        {
            if(index >= 0 && index < values.size())
            {
                values[index] = newValue;
            }
        }
    //Multiply
        void multiply(int scalar)
        {
            for(int i = 0; i < values.size(); i++)
            {
                values[i] *= scalar;
            }
        }
    //addVector
        Vector add(const Vector &other)
        {
            Vector result;
            int n = values.size();
            if(other.values.size() != n)
            {
                cout << "Error Vector sizes do not match!";
                return result;
            }
            result.create(n);
            for(int i = 0; i < n; i++)
            {
                result.values[i] = values[i] + other.values[i];
            }
            return result;
        }
    //Display
        void display()
        {   
            cout << "(";
            for(int i = 0; i < values.size(); i++)
            {
                cout << values[i];
                if(i<values.size() - 1)
                {
                    cout << ',';
                }
            }
            cout << ")\n";
        }

};

int main()
{
    Vector v1, v2, v3;
    v1.create(3);
    v1.modify(0,10.0f);
    v1.modify(1,20.0f);
    v1.modify(2,40.0f);
    v1.display();

    v2.create(3);
    v2.modify(0,10.0f);
    v2.modify(1,20.0f);
    v2.modify(2,30.0f);

    v3 = v1.add(v2);
    v3.display();

    
    return 0;
}
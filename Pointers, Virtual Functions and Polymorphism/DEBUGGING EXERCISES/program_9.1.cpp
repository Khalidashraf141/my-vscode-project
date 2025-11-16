                                        /*DEBUGGING EXERCISES*/
#include <iostream>
using namespace std;

// GST class to store price and tax percent
class GST
{
    float price;
    float percent;
public:
    // Function to store input values
    void input(float a, float b)
    {
        price = a;
        percent = b;
    }
    // Function to print stored values
    void print()
    {
        cout << "price: " << price <<endl;
        cout << "percent: " << percent << endl;
    }
    ~GST()
    {
        cout << "Destructor of GST object executed.\n";
    }
};

int main()
{
    GST *p[3];  // Array of pointers to GST objects
    // GST *q = p; This code is wrong for storing pointer address you should use pointer to pointer data types

    GST **q = p; // this work fine (q points to the first element of array p)
    double final; //Final amount after adding GST
    float s,t,f;   // s = price, t = percent, f = calculated GST amount
    for(int i = 0; i < 3; i++)
    {
        // Allocated memory for each object
        q[i] = new GST;

        cout << "Provide the price and percent" << "\n";
        cin >> s >> t;
        // Store the values in object
        // q->input(s,t) this is wrong here we are not clarify which index on pointer to access
        q[i]->input(s,t);

        cout << "you have entered" << "\n";
        q[i]->print();
        // Calculate GST amount
        // f = s*t; this is also wrong according to math for gst we also have to include 100 in denominator
        f = s*(t/100); // here is right code first t/100
        
        // Calculate final price
        final = f + s;
        cout << "GST Amount: "  << f << "\n";
        cout << "Final Price after GST: " << final << "\n";
        cout << "-------------------------------\n";
    }

    //We should free memory 
    for(int i = 0; i < 3; i++)
    {
        cout << "Destructor is working.....\n";
        delete q[i];
    }
    return 0;

}
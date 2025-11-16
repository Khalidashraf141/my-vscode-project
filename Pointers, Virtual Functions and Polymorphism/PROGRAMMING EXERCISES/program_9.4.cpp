/*
Using the concept of pointers write a function write a function that swaps the private data values of two objects of the same class type.
*/
#include <iostream>
using namespace std;

class Sample
{
    private:
        int value;
    public:
        void setValue(int v){
            value = v;
        }
        /*
        !You can do this without member function 
        void swapInside(Sample &other){ //member function also other is reference
            int temp = value;               //! allowed same class -> can access private data
            value = other.value;
            other.value = temp;
        }

        */

        void show(){
            cout << "("<<value << ","<<")";
        }

        // Friend function to access private members
        friend void swapData(Sample *a, Sample *b);
};

//Function that swaps private data of two objects using pointers
void swapData(Sample *a, Sample *b)
{
    int temp = a->value;
    a->value = b->value;
    b->value = temp;
}

int main()
{
    Sample obj1, obj2;
    cout << "Before swap: " << endl;
    obj1.setValue(10);
    obj1.show();
    obj2.setValue(200);
    obj2.show();

    swapData(&obj1, &obj2); // Passing pointers

    cout << "\nAfter swap: " << endl;
    obj1.show();
    obj2.show();

    return 0;

    
}
//open this for deep explanation related to pointer
//file:///C:/Users/zeros/Downloads/pointer_swap_explanation.pdf



// TOPIC: Overloading [] operator In C++ (Array Subscript Operator)

// POINTS:
// 1. Array Subscript Operator can be used to check out of bound cases.
// 2. Array Subscript Operator can not be friend function and others too (->,(),=).

#include <iostream>
using namespace std;

class Point
{
    int arr[2];
public:
    Point(int x = 0, int y = 0)
    {
        arr[0] = x;
        arr[1] = y;
    }
    void print(void)
    {
        cout << "x " << arr[0] << " y " << arr[1] << "\n";
    }
    int& operator [] (int pos)
    {
        if(pos == 0)
        {
            return arr[0];
        }else if(pos == 1)
        {
            return arr[1];
        }else{
            cout << "Out of bound case." << "\n";
            exit(0);
        }
    }
};


int main()
{
    Point p1(3,4);
    p1.print();
    p1[0] = 7;
    p1[1] = 8;
    p1.print();
    return 0;
}
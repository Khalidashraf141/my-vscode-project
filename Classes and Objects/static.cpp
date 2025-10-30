/*
Static data members in C++
-Declared inside a class using static but memory is not allocated there.
-Must be defined outside the class to allocate storage
-Only one copy exists for the entire class, shared by all objects
-Default initialized to 0 if not explicitly initialized
*/
#include <iostream>
using namespace std;

class item
{
    static int count;
    int number;
    public:
    void getdata(int a)
    {
        number = a;
        count++;
    }
    void getcount(void)
    {
        cout << "count: ";
        cout << count << "\n";
    }
};
int item :: count; 

int main(){
    item a, b, c;
    a.getcount();
    b.getcount();
    c.getcount();

    a.getdata(100); //first time use hua to count++ hua 1
    a.getdata(200); // second time use hua to count++ hua 2
    a.getdata(300); // third time use hua to count++ hua 3
    
    cout << "After reading data" << "\n";

    a.getcount();  
    b.getcount();
    b.getcount();
    return 0;
}
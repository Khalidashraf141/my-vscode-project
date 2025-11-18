/*
When a base class pointer is used to access members of a derived class object, it can only access those members that are inherited from the base class, not the members that are unique to the derived class.
    *If the derived class defines a member with the same name as one in the base class, then any access through the base class pointer will always refer to the base class version of that member - not the derived one.
*/
//TODO:PRACTICE DONE
//Example:-
#include <iostream>
using namespace std;

class Base
{
    public:
        int x = 10;
        void show(){cout << "Base class show()" << endl;}
    
};

class Derived : public Base
{
    public:
        int y = 20;
        void show(){cout << "Derived class show"<< endl;}
};


int main()
{
    Base* cptr;
    Derived d;

    cptr = &d; // Base class pointer points to Derived object

    cout << cptr->x << endl; // ✅ Accessible (inherited from Base)
    // cout << cptr->y << endl; // ❌ Error: y is not a Base

    cptr->show(); // Calls Base::show() (because show() is not virtual)
    
    
    
    //To Access Derived Members
    ((Derived*)cptr)->y;    // Now you can access y
    ((Derived*)cptr)->show(); //Calls Derived::show()
    


    //another version To Access Derived Members
    Derived* dptr = &d;
    dptr->y; //Works normally
    dptr->show();   //Calls Derived::show()
    return 0;

}

/*
🧠 Explanation:
1. cptr is a pointer of type Base*, so it only knows about members that exist in Base
2. Even though cptr is pointing to a Derived object, it cannot access members that are specific to Derived like (y).
3. if both Base and Derived have a function or variable with the same name (like show() or x), then cptr->show() will always call Base version unless the function is declared (virtual)
*/
//!From here virtual function fixes this problem 
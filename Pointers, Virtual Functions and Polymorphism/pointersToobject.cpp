/*
🧠 Topic: Pointers to Objects
    1. What is it?
    -Object pointers are variables that store the address of an object.
    They are useful when:
        - You want to create objects dynamically (at runtime).
        - You want to access object members (function or variables) using a pointer.
    
    2. Creating and using an object pointer
        Item x;
        Item *ptr = &x;

        -x   -> is an object of class Item.
        -ptr -> is a pointer that stores the address of x.
        so now ptr points to x.

    There are two ways to access members of the class:
        1. dot operator
        2. arrow operator
    
        💡The arrow operator -> combines both *(dereference) and .(dot).
            So, ptr->show() means (*ptr).show();
            
        if you use dereferencing manually you must write: (*ptr).show();
            because . has higher precedence than *
            without parentheses *ptr.show() would mean something else (invalid).

    !important
    if your class has a constructor with parameters (not an empty one), then you must supply arguments when creating the object dynamically.
    
    Item *ptr = new Item(10,20.5);
    (otherwise, the compiler will give an error because it doesn't know which constructor to call)


    !important
    In C++ the dot operator(.) has higher precedence than the dereference operator(*).


    !attention
    so if you write this:
    *ptr.show();

    -the compiler reads it as:
    *(ptr.show());

    that means it thinks you're trying to call show() on ptr which is a pointer
    and then dereference the result❌

    but what we actually mane is:
    Dereference the pointer first(get the object) then call show().
    (*ptr).show();

    This tells the compiler:
        First, go the object that ptr points to (*ptr),
        then call its member function show().

    Shortcut:
        to avoid writing parentheses every time we use the arrow operator(->), 
        which does both steps automatically:
        ptr->show(); //same as (*ptr).show();
    

    !when you write (item *ptr = new item;)
    What it actually does
        1. new item
         - The new operator asks the system (heap memory) to allocate enough memory to hold
            one complete object of class item. 
            the arrSize depends on how many and what type of data member the class has
        example
        class item{

            int code; // 4 bytes
            float price; // 4 bytes

        };
        the new item will allocate 8 bytes (so slightly more)-enough to store both members.
        the (new) operator returns the starting address of that object in memory.
        ptr which is of type item* stores the address of the newly created object.
*/
//TODO:PRACTICE DONE
#include <iostream>
using namespace std;

class Item
{
    int code;
    float price;
public:
    void getdata(int a, float b)
    {
        code = a;
        price = b;
    }
    void show(void)
    {
        cout << "Code : " << code << "\n"
             << "Price: " << price << "\n\n";
    }
};

class newItem
{
    int code;
    float price;
public:
    void initialize(int a, float b)
    {
        code = a;
        price = b;
    }
    void display(void)
    {
        cout << "Code  : " << code << "\n"
             << "Price : " << price << "\n\n";
    }
};
const int arrSize = 2;
int main()
{
    Item x;
    Item *ptr = &x;
    ptr->getdata(10,78.5);
    ptr->show();

    newItem *a = new newItem[arrSize];
    newItem *p = a;
    int z, i;
    float y;

    for(i = 0; i < arrSize; i++)
    {
        cout << "Input code and price for item" << i+1;
        cin >> z >> y;
        a->initialize(z,y);
        a++;
    }
    /*
        a is no longer pointing to the beginning of the array. it's pointing past the last element(to invalid memory).
    */

    for(i = 0; i < arrSize; i++)
    {
        cout << "Item: " << i+1 << "\n";
        p->display();
        p++;
    }
    //this was done so that p always keeps the original starting address.
    //This works correctly because p starts from the first element, and moves forward across valid objects
    return 0;
}
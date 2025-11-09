// this pointer in C++
//!Definition:- this is a pointer that points to the object for which this function was called.
// NOTES:
// 0. this pointer is used to hold the address of current object (using which we have called particular member function).
// 1. this pointer is a const pointer.
// 2. this pointer is passed as a hidden argument to non-static member function.
// 3. Compiler automatically changes all data member access with this pointer.
// 4. It is not passed in static member functions.


#include <iostream>
#include <cstring>
using namespace std;

class person
{
    char name[20];
    float age;
public:
    person(const char *s, float a)
    {
        strcpy(name,s);
        age = a;
    }
    person &greater(person  &x)
    {
        if(x.age>=age)
            return x;//these| both return obj
        else
            return *this; //so return this -> return p1 or current object | return obj obj ke andar ka data fir display se display ho raha hai
    }
    void display(void)
    {
        cout << "Name : " << name << "\n"
             << "Age  : " << age << "\n";
    }
};

int main()
{
    person p1("John",37.50),p2("Ahmed",29.0),p3("Hebber",40.25);

    person p = p1.greater(p3); //p1 is current p2 is other obj

    cout << "Elder person is: \n";
    p.display();

    p = p1.greater(p2);
    cout <<"Elder person is: \n";
    p.display();

    return 0;

}

/*
                                                               ---------------------------------------------
                                                                          Concept of 'this' Pointer
                                                               ---------------------------------------------
                                                               
                                                               class Person
                                                               {
                                                                   string name;
                                                                   int age;
                                                               
                                                               public:
                                                                   void display()
                                                                   {
                                                                       cout << "Name: " << this->name 
                                                                            << ", Age: " << this->age << endl;
                                                                   }
                                                               };
                                                               
                                                               ---------------------------------------------
                                                                          Memory and Pointer Flow
                                                               ---------------------------------------------
                                                               
                                                                    +-------------+             +-------------+
                                                                    |   Object p1 |             |   Object p2 |
                                                                    |-------------|             |-------------|
                                                                    | name: "Ali" |             | name: "John"|
                                                                    | age : 18    |             | age : 20    |
                                                                    +-------------+             +-------------+
                                                               
                                                                        ↑                            ↑
                                                                        |                            |
                                                                  this → p1                    this → p2
                                                               (when p1.display() is called)  (when p2.display() is called)
                                                               
                                                               ---------------------------------------------
                                                                          Internal Working
                                                               ---------------------------------------------
                                                               
                                                               When you call:
                                                                   p1.show();
                                                               
                                                               C++ secretly converts it to something like:
                                                                   show(&p1);   // compiler automatically passes address of p1
                                                               
                                                               That means — inside the show() function —
                                                               there’s an invisible pointer called 'this',
                                                               which points to the object that called the function.
                                                               
                                                               So in this case:
                                                                   this == &p1
                                                               
                                                               If we call:
                                                                   p2.show();
                                                               
                                                               Then:
                                                                   this == &p2
                                                               
                                                               ---------------------------------------------
                                                                Explanation:
                                                               ---------------------------------------------
                                                               • Each object (p1, p2) has its own memory for data members.
                                                               • When you call p1.display(), the compiler secretly passes 
                                                                 the address of p1 to the function using 'this'.
                                                               • So inside display(), 'this' points to p1.
                                                               • Similarly, when p2.display() is called, 'this' points to p2.
                                                               • 'this' is an implicit pointer available in all non-static
                                                                 member functions, referring to the calling object.
                                                               ---------------------------------------------


*/
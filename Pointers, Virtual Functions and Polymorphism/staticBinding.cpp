//Static binding -> (also called early binding) in C++ means that the function to be called is decided at compile time not at runtime.


//Example of Static Binding
#include <iostream>
using namespace std;

class Animal
{
    public:
        void sound(){ //non-virtual function
            cout << "Animal makes a sound" << endl;
        }
};

class Dog : public Animal
{
    public:
        void sound(){
            cout << "Dog barks" << endl;
        }
};

//Example of Dynamic Binding
class Animals
{
    public:
        virtual void sound(){
            cout << "Animal makes a sound" << endl;
        }
};

class lion : public Animals
{
    public:
        void sound(){
            cout << "Lion roar" << endl;
        }
};


int main()
{
    //Static binding
    Animal a; // object of base class
    Dog d;    // object of derived class

    a.sound();  // calls Animal::sound()
    d.sound();  //class Dog::sound()

    Animal *ptr;
    ptr = &d;
    ptr->sound(); //still calls Animal::sound (static binding)
    cout << "\n\n";
    /*
    🧠 Explanation 
        -Even though ptr points to Dog object the function sound() of Animal is called 
        that's because the function is not virtual so compiler binds it statically
    */

    //Dynamic binding
    Animals *add;
    lion l;
    add = &l;
    add->sound(); // Now it calls Lion::sound() (Dynamic Binding)

    return 0;
    

}
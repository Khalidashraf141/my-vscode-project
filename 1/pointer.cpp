#include <iostream>
using namespace std;

int main(){
/*
Create  a pointer variable with the name ptr, that points to a string variable, by using the asterisk sign * (string *ptr).
Use the & operator to store the memory address of the variable called food, and assign it to the pointer 
Now, ptr holds the value of food memory address.
       Tip: Thre ae three ways to declare pointer variables but the first way is preferred:
       1. string* ptr; // Preferred
       2. string * ptr;
       3. string  *ptr;
& this is called reference operator
* this is called dereference operator
*/



    string name = "Khalid Asrhaf";
    string *ptr = &name;
    cout << name << endl;
    cout << &name << endl;
    cout << ptr << endl;

    string car = "Audi"; //Variable declaration
    string* add = &car;  // Pointer declaration
    cout << car << endl;

//Reference: Output the memory address of food with the pointer
    cout << add << endl;

//Dereference: Output the value of food with the pointer (Audi)
//Ye us memory address pe jo value store hai usko print karta hai (Audi) tha to audi ko print kar diya hai...
    cout <<*add << endl;

/*
Note that the * sign can be confusing here, as it does two different things in our code:    
        -When used in declaration (string* ptr), it creates a pointer variable.
        -When not used in declaration, it act as a dereferecne operator.
*/

      //Modify the pointer value
      string junkFood = "Pizza";
      string *locat = &junkFood;

      cout << junkFood << endl;
      cout << &junkFood << endl;

      cout << *locat << endl;

      *locat = "Hamburgur\n"; //Modify the pointer value
      cout << *locat << endl;
    return 0;
}
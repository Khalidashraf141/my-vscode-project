#include <iostream>
using namespace std;

int main(){
    /*
    A reference variable is a "reference" to an existing variable, and it is created with & operator:
    */
   string food = "Pizza";
   string &meal = food;

   cout << food << endl;
   cout << meal << endl;

   /*
   & operator is also used for get the memory address of a variable; which is the location of where the variable is stored on the computer.

   note: The memory address is in hexadecimal form (0x..)


  => And why is it useful to know the memory address?
   -References and Pointers are important in C++ because they give you the ability to manipulate the data in computer's memory - which can reduce the code and improve the performance 
   */
    string newFood = "Apple";
    cout << &newFood; // varialbe address in memory

}
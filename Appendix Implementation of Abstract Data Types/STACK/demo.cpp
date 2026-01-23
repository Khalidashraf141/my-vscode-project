#include <iostream>
#include "mystack.h" //includes the class definition of MyStack
using namespace std;

int main()
{
    MyStack<char>s1; //declaration of char type stack of size 100

    s1.push('A'); // push the character 'A' into stack
    cout << s1.pop() << endl; // pop 'A' and display it

    MyStack<>s2(5); //declaration of default int type stack of size 5
    s2.push(20);
    s2.push(30);
    s2.push(40);
    s2.push(50);
    s2.push(60);
    s2.push(70); //try to push 70, will result in a Stack overflow message

    cout << s2.pop() << " " << s2.pop() << " " << s2.pop() << " " << s2.pop() << " " <<s2.pop() << endl; // perform 5 consecutive pop operations
    cout << s2.pop();  //try to perform a 6th pop, will result in Stack underflow message
    return 0;
}


/*
The output after s2.pop() is not displayed because the program terminates earlier during the execution of the push() function

In the push() function, when an attempt is made to insert an element beyond the stack size (stack overflow), an exception is thrown and caught. Inside the catch block, a message "The Stack is full" is printed, and exit(1) is executed. The exit(1) statement immediately terminates the program.

Due to this forced termination, the control never reaches the subsequent in main(), such as the s2.pop() operations. Therefore, no further output is produced.

Hence, the absence of output from s2.pop() is not due to an error in the pop() function itself, but because the program ends during the overflow condition in the push() function


------------------------------------------------------------------
top-- moves the stack pointer down
this is the element is considered removed

Index:   0   1   2   3
Values: 10  20  30  40
top = 3

-40 is logically removed from the stack
-Physically memory still exists but is ignored
*/
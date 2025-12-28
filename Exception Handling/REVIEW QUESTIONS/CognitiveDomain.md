13.1 Explain exception

ans-> An exception is an unexpected error or abnormal condition that occurs while a program is running, which interrupts the normal flow of execution.

When a program is running and something goes wrong at runtime (not during compilation), that problem is called an exception.

Examples of such problems:
    • Divide a number by zero
    • Trying to open a file that does not exist
    • Accessing memory that is not allowed
    • Running out of memory
Why exceptions are needed
without exceptions:
    • The program may crash suddenly
    • Or produce wrong output
    • Or terminate abnormally
With exceptions
    • The error detected
    • The program gets a chance to handle the problem safely
    • The program can continue or terminate gracefully
In C++, an exception is handled using three keywords:
    1. try -> place the code that may cause an error
    2. throw -> signal that an error has occurred
    3. catch -> handle the error

13.2 Explain exception handling in C++

ans-> Exception handling in C++ is a mechanism that allows a program to detect runtime errors (exceptions) and handle them gracefully without abnormal termination.

It separates error-handling code from normal program logic, making programs robust and reliable.

Why Exception Handling is Needed
    • Prevents program crash
    • Handles unexpected runtime errors
    • Improves program stability
    • Makes debugging and maintenance easier

Keywords Used in Exception Handling
1. try
    • Contains code that may generate an exception
    • Must be followed by one or more catch blocks
2. throw
    • Used to signal an exception
    • Transfer control from try to catch
3. catch
    • Handles the exception
    • Executed only when a matching exception is thrown

Syntax:
    try{
        // code that may cause an exception
        throw exception;
    }
    catch(type arg){
        // exception handling code
    }


13.3 Express the advantages of using exception handling mechanism in a program.

Advantages of Using Exception Handling Mechanism in a Program
The exception handling mechanism provides a systematic way to detect and handle runtime errors, thereby improving the quality and reliability of a program.

Main Advantages:
    1. Prevents abnormal program termination
       Exception handling avoids sudden program crashes by allowing errors to be handled gracefully.
    2. Separates error-handling code from normal code
       The main program logic remains clean and readable, while error-handling code is written separately in catch blocks.
    3. Improves program reliability and robustness
       Programs can recover from unexpected runtime errors and continue execution safely.
    4. Simplifies debugging and maintenance
       Errors are handled at specific points, making programs easier to debug and maintain.
    5. Supports handling of multiple error types
       Different catch blocks can be used to handle different kinds of exceptions.
    6. Provides automatic error propagation
       Exceptions can be passed from one function to another until they are properly handled.
    7. Enhances program clarity and structure
       The flow of execution during error conditions becomes clear and well-defined.

13.4 Predict a program that throws an exception under some circumstance.

Circumstance When Exception is Thrown
    • If the user enters 0 as the second number (b)
    • The statement throw b; is executed
    • Control immediately transfers to the catch block

1. Program takes two integers from the user
2. Inside the try block:
    • It checks if b == 0
    • If true, an exception is thrown using throw b
3. The catch (int x) block catches the exception
4. An error message is displayed
5. Program does not crash and continues execution

Sample Output
Enter two numbers: 10 0
Exception caught: Division by zero is not allowed.
Program continues normally.


13.5 Recall when a catch(...) handler is used.

A catch(...) handler is used to catch any type of exception, regardless of its data type.

Key Points to Recall
    • catch(...) is called a catch-all handler
    • It catches all exceptions:
        • Built-in types (int, double, char, etc)
        • Objects
        • User-defined exceptions
    • It is used when:
        • The type of exception is unknown
        • You want to prevent program termination
        • You want a default safety handler

Important Rule 
    catch(...) must be the LAST catch block
If place earlier, it will catch everything and other catch blocks will never execute.


13.6 Class types can be thrown as exceptions. Explain with the help of an example.

objects of class types can be thrown as exceptions
This is useful because a class object can carry multiple data members and detailed error information, unlike simple data types.

Why Use Class Types as Exceptions?
    To pass more information about the error
    To group error code + error message together
    Common in real-world and professional C++ programs

#include <iostream>
using namespace std;

class Error
{
    int code;
    string message;
public:
    Error(int c, string m)
    {
        code = c;
        message = m;
    }
    void display()
    {
        cout << "Error Code: " << code << endl;
        cout << "Message   : " << message << endl;
    }
};

int main()
{
    int x;
    cout << "Enter a number";
    cin >> x;

    try
    {
        if(x < 0)
        {
            throw Error(101, "Negative number not allowed");
        }
        cout << "Valid number entered: " << x << endl;
    }
    catch(Error e)
    {
        cout << "Exception caught!" << endl;
        e.display();
    }
    return 0;
}

Output(When Exception Occurs)
Enter a number: -5
Exception caught!
Error code: 101
Message   : Negative number not allowed

1. A class Error is defined with:
    Error code
    Error message
2. An object of class Error is created inside throw
3. The object is thrown using:
    throw Error(101,"Negative number not allowed");
4. The catch(Error e) block catches the class object
5. The error details are accessed using member functions.


13.7 Illustrate an exception specification and its uses.

An exception specification tells which type of exceptions a function may throw.
It is written after the function declaration.

Syntax
return_type function_name(parameter_list) throw(type1, type2, ....)
    type1, type2, ... -> allowed exception types
    If a function throws any other type, terminate() is called

Example: Function with Exception Specification
#include <iostream>
using namespace std;

void divide(int a, int b) throw(int)
{
    if(b == 0)
        throw b;        // allowed: int exception
    cout << "Result = " << a / b << endl;
}

int main()
{
    try
    {
        divide(10,0);
    }
    catch(int)
    {
        cout << "Exception caught: Division by zero" << endl;
    }
    return 0;
}

Explanation
    throw(int) specifies that:
        The function may throw only int type exceptions
    If any other type is throw:
        Program will call terminate() -> abnormal termination
    The caller knows what to expect and what to catch

Uses of Exception Specification
1. Improves Program Reliability
    Restricts unexpected exceptions
2. Helps the Programmer
    Caller knows which exceptions to handle
3. Documentation Purpose
    Acts as formal documentation of function behavior
4. Used in Large Projects
    Important in library design and APIs

Modern C++ 
void func() noexcept;
    Means: function will not throw any exception
    Preferred in modern C++


13.8 Demonstrate what should be placed inside a catch block

A catch block contains the exception-handling code, i.e., the statements that are executed when an exception is caught.
Its main purpose is to handle the error safely and allow the program to continue.


catch (type parameter)
{
    //exception-handling code
}

What you can Place inside a catch block

1. Error Message/Notification
inform the user about the error
    cout << "Error: Division by zero" << endl;


2. Access the Exception Object
Use the caught parameter to get error details
    catch(int x)
    {
        cout << "Invalid value: " << x << endl;
    }

3. Corrective/Recovery Action
Fix the problem or use a safe value
    catch(int)
    {
        cout << "Using default value 1" << endl;
        b = 1;
    }

4. Resource Cleanup
Close files, free memory, release locks.
    catch(...)
    {
        file.close()
        delete ptr;
    }


13.9 Explain when to use multiple catch handler

Multiple catch handlers are used when a single tyr block may throw different types of exceptions, and each exception requires a different handling action.

Why Multiple catch Blocks are Needed
Use Multiple catch handlers when:
    1. Different exception types can occur
    2. Each exception needs a specific response
    3. You want clear, type-safe error handling
    4. You want to avoid using a generic catch(...) for everything

Important Rules
    Catch blocks must be ordered from specific to general
    catch(...) must always be the last handler
    Only one catch block executes per exception


13.10 Explain under what circumstances the following statements would be used:
    (a) throw;
    (b) void fun1(float x) throw()
    (c) catch(...)

(a) throw;
When it is used
    Used inside a catch block
    Used to rethrow the currently caught exception
    Passes the exception to an outer try-catch handler
    Preserves the original exception type

(b) void fun1(float x) throw()
When it is used
    Old-style exception specification
    Means the function will not throw any exception
    If an exception occurs -> terminate() is called
    Deprecated in C++ 11, removed in C++ 17


(c) catch(...)
When it is used
    To catch all types of exceptions
    Used when exception type is unknown
    Acts as a default/ fallback handler
    Must always be the last catch block


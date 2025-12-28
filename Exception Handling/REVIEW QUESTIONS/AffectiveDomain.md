Defend the correctness of the following statements:
    (a) An exception is thrown outside a try block
-> An exception can be thrown outside a try block because the throw statement is not restricted to appear only inside a try block. A function or statement may throw an exception, and that exception can be caught by a try-catch block in the calling function.

If an exception is thrown outside all try blocks, the program will terminate abnormally.

    (b) No catch handler matches the type of exception thrown
-> An exception is thrown, but none of the available catch blocks have a parameter type that matches the thrown exception's type.

As a result, the exception is not handled.
What happens in this situation?
    The exception is not caught
    C++ looks for a matching catch block
    If none is found:
        std::terminate() is called
        Program terminates abnormally


    (c) Several handlers match the type of exception thrown
-> This situation occurs when more than one catch handler is capable of handling the thrown exception.
In such case, C++ selects and executes only the first matching catch handler, checking from top to bottom.

Why can several handlers match?
    Due to inheritance (derived class object can match base class handler)
    Due to general handlers like catch(...)
    Because handlers are checked sequentially

    (d) A catch handler throws an exception
-> A catch block itself can throw an exception, either the same exception or a new/different exception, while handling an error.
This is allowed in C++ and is used when the current handler cannot fully handle the problem.

When does this situation occur?
    A catch handler throws an exception when:
        The error is too serious to handle locally
        Only partial handling is done
        The exception must be propagated to a higher-level handler
        A different more meaningful exception needs to be generated

    
    (e) A function throws an exception of type not specified in the specification list.

-> A function has an exception specification (old-style) but during execution it throws an exception whose type is NOT listed in that specification.
This situation is not allowed.

What happens in this case?
    The exception violates the exception specification
    C++ immediately calls std::unexpected()
    This usually leads to std::terminate()
    The program terminates abnormally
    The exception is not caught, even if a matching catch exists

    (f) catch(...) is the first of cluster of catch handlers

-> This statement is incorrect
The catch(...) handler must always be the last handler in a cluster of catch blocks.
If it is placed, it will catch all exceptions, making the remaining catch handlers unreachable.

Why is this incorrect?
    catch(...) matches any type of exception
    Catch handlers are checked top to bottom
    if catch(...) appears first:
        it catches everything
        Other handlers will never execute
    Compilers usually issue a warning or error


    (g) Placing throw() in a function header line
-> Placing throw() in a function header means:
    the function guarantees that it will not throw any exception.
It is an old-style exception specification used in earlier versions of C++

Explanation:
    throw() specifies that the function does not allow any exception
    If an exception is thrown from such a function:
        C++ calls std::unexpected()
        Which usually leads to std::terminate()
        The program terminates abnormally
        The program terminates abnormally


    (h) An exception rethrow within a catch block
-> An exception that has already been caught is thrown again from inside the catch block so that it can be handled by an outer try-catch block.
This is called exception rethrowing

When is rethrowing used?
    When the current catch block can only partially handle the exception
    When the exception must be reported or logged, then passed upward
    In layered or modular programs

Correct syntax for rethrowing
    throw; // rethrows the current exception

    throw; must be used inside a catch block
    It preserves the original exception type
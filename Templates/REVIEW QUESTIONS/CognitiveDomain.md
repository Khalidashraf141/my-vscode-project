12.1 Rewrite about generic programming and its implementation in C++.

->Generic programming is a software development approach that focuses on designing algorithms and data structures so they can work with any data type without being rewritten for each one.

Instead of writing specific code for an int, and string or a custom object, you write the logic once using placeholder types.

Core Concept: Abstraction over Types
In traditional programming code often "type-dependent" if you write a function to swap two integers, it won't work for two doubles. Generic programming removes this barrier by focusing on the behavior ("moving data from A to B") rather than the data format.

Implementation in C++: Templates
In C++, generic programming is primarily achieved through Templates. When you use a template, you aren't writing a single function; you are writing a blueprint than the compiler uses to generate specific code when needed.

1. Function Templates
These allow a single function to handle different types.

template<typename T>
T add(T a, T b){
    return a + b;
}
When you call add(5,10), the compiler generates an int version. when you call add(2.5,3.1)
it generates a double version. This is known as instantiation.

2. Class Templates
Class templates allow you to create generic containers The most famous example is the Standard Template Library (STL).

Why Use It?
    • Code Reusability: Write once, use for any data type that supports the required operations.

    • Type Safety: Unlike generic programming in some older language (which used void* pointers), C++ templates are checked at compile-time. If you try to "add" two types that don't support the + operator, the code won't compile.

    • Performance: Because the compiler generates specific code for each type, there is no "runtime overhead" or "boxing/unboxing" penalty. It is often as fast as hand-written, type-specific code.


12.2 Explain with help of an example the requirement of templates in programming.

The Problem: Redundancy
Imagine you want a simple function that finds the larger of two values. Without templates, your code would look like this:

C++
int max(int a, int b){
    return (a > b)? a: b;
}
double max(double a, double b){
    return (a > b) ? a : b;
}

char max(char a, char b){
    return (a > b) ? a : b;
}

Even though the logic (the comparison) is identical, you are forced to repeat yourself because the types are different. This makes the code harder to maintain - if you find a bug in the logic, you to fix it three different places.

The Solution: The Template Requirement
Templates allow you to define the function using a placeholder (usually denoted as T). You tell the compiler: "I don't known the type yet, but whenever it is , compare them like this."

Example Implementation
template <typename T>
T myMax(T a, T  b){
    return (a > b)? a : b;
}
Now, when you call myMax(10,20), the compiler sees you are using integers and automatically generates the int version of the function for you.

The Core Requirements of Templates
For a template to work successfully in C++, two main requirements must be met:

1. Semantic Requirements (The "Contract")
The data type you pass in to the template must support the operations used inside the template.
    • in the myMax example above, the template uses the > operator.
    • If you try to pass a custom User object into myMax, but you haven't defined what "greater than" means for a user, the code will fail to compile.

2. Compile-Time Availability
Unlike regular functions where the code is compiled into a library and linked later, the source code of a template must usually be available in the header file. This is because the compiler need the "blueprint" to generate the specific version of the function the moment it sees you using a new type.


12.3 A template can be considered as a kind of macro. Distinguish the difference between them.

While both templates and macros achieve "code generation" they operate in fundamentally different ways. A macro is a "dumb" text replacer, while a template is a "smart" code generator integrated into the C++ language.

1. Preprocessor vs. Compiler

    • Macros (#define): These are handled by the Preprocessor before the actual compiler even sees your code. It is a blind search-and-replace of text strings.

    • Templates: These are handled by the Compiler. The compiler understands the structure of the language, scopes, and types, allowing it to generate actual C++ functions or classes.


2. Type Safety
This is the most critical advantages of templates
    • Macros: They have no concept of types. If you pass a string to a macro meant for math, the preprocessor will happily replace the text, and you will get a confusing error much later in the compilation process (or even worse, a runtime crash).

    • Templates: They are type-safe. the compiler checks the types of the arguments you pass. if they don't match the logic inside the template, you get a precise error message.


3. Scoping and Namespaces
    • Macros: They are global. Once a macro is defined it stays active until the end of the file (or until #undef). it ignores namespaces, which can lead to "name collisions" Where a macro accidentally replaces a variable or function name in a completely different part of your program.

    • Templates: They respect namespaces and classes. You can have a MyLib::sort<T> that doesn't conflict with std::sort<T>.

In modern C++, the general rule is: if you can use a template (or constexpr), avoid a macro. Use macro only for things templates cannot do, like stringification (#) or conditional compilation (#ifdef).


12.4 Distinguish between overloaded functions and function templates.

In C++, both mechanism allow for Polymorphism- using the same interface (function name) for different data types. However, their implementation and intent are quite different.

1. Conceptual Distinction 
    •   Overloading: Focuses on variety. You provide multiple distinct definitions of a
        function where the logic might change depending on the input types
    
    • Templates: Focuses on uniformity. You provide a single blueprint for a function where
      the logic remains identical regardless of the input types.

2. Comparison Table
Feature                 Overloaded Functions                    Functions Templates
Logic/Behavior          Can be different for every type.        Must be the same for all types.

Manual Effort           You must write every version by hand.   You write it once; compiler generates the rest.

Maintenance             High: Changes must be applied to all    Low: Change the template once.
                        versions.                               

Data types              Limited to the types you explicitly     Works with any type that supports the operations.
                        defined                                    

Compilation             Functions are compiled as written.      Code is generated (instantiated) only when used.



3. Practical Examples

Overloading: Different Logic
Use overloading where the steps to perform the action change based on the type. For example, a print function might need to add special formatting for a Date object that it doesn't need for a standard int.


C++
// Overload for integers
void printData(int i)
{
    std::cout << "Integer: " << i << std::endl;
}

// Overload for strings
void printData(std::string s){
    std::cout << "String: " << s.length() << " chars long" << std::endl;

}

Templates: Identical Logic
Use templates when the steps are the same. For example, the mathematical logic to swap two variables doesn't change whether they are integers or floating-point number.

template<typename T>
void swapValues(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

4. How the Compiler Decides
If both an overloaded function and a template exist for the same type, C++ follows a specific hierarchy:
    1. Exact Match (Non-template): The compiler prefers a regular overloaded function over a template.
    2. Template Match: If no specific overload exists, the compiler generates a function from the template.
    3. Promotion/Conversion: if neither exists, it tires to convert types (e.g., char to int) to fit an existing overload.



12.5 Distinguish between the terms class template and template class.

While these two terms are often used interchangeably in casual conversation, in formal C++ technical terms, they refer to different stages of the code's "life cycle."

The easiest way to remember the difference is: a Class Template is the blueprint, while a Template Class is the actual house build from that blueprint.

1. Class Template (The "Blueprint")
A Class Template is a template used to generate classes. It is the generic definition you write using the template keyword. At this stage, it doesn't occupy any memory because the compiler doesn't know what data types it will be handling yet.

Characteristics:
    • It is a "parameterized description" of a family of classes.
    • You cannot create an object directly from a class template without specifying types.
    • Example: template <class T> class Box{....};

2. Template Class (The "Instantiation")
A Template Class is a specific class that has been generated (instantiated) from a class template.
Once you provide the specific data types(like int or string), the compiler creates a real, concrete class in the background.

Characteristics:
    • It is a specific instance of a class template
    • It is  real class that the compiler uses to allocate memory and create objects.
    • Example: Box<int> is a template class.

Modern Context: The Standard's view
it is worth noting that the official C++ Standard primarily uses the term class Template. The term "Template Class" is technically considered older jargon or a "linguistic" way to describe a 
Specialization.

    • Class Template: The primary template definition
    • Class Template Specialization: What people usually mean when they say "Template Class"(e.g., std::vector<int>).


12.6 A class (or function) template is known as a parameterized class (or function). Justify the correctness
of this statement?

The statement is correct because a template cannot exist as executable code without first receiving its type parameters. The parameters act as the necessary "instructions" for the compiler to generate the actual class or function



12.7 Choose the definitions that are illegal.

    (a) template <class T>
        class city
        {.....};
    ✅ Legal 
    single template parameter - perfectly valid
    
    (b) template <class P,R,class S>
        class city
        {.....};
    ❌ Illegal
    ❌ R has no keyword (class or typename) before it.

✔ Correct form:
    template <class P, class R, class S>

    
    (c) template <class T,typename S>
        class city
        {.....};
    ✅ Legal
    ✔ class and typename are interchangeable.

    (d) template <class T, typename S>
        class city
        {.....};
    ✅ Legal
    
    (e) class <class T, int size = 10>
        class list
        {.....};
    ❌ Illegal
    ❌ class <class T, int size> is wrong syntax.
✔ Must be:
    template <class T, int size = 10>
    class list { };

    (f) class <class T=int, int size>
        class list
        {.....};
    ❌illegal
    ❌Same syntax error as (e)
    ❌Also non-type parameter size has no default but follows one that does.

12.8 Choose the function template definitions that are illegal
    (a) template<class A, B>
        void fun(A, B)
        {.....};
    ❌illegal
    ❌B has no class or typename keyword
    (b) template<class A, class A>
        void fun(A,A)
        {.....};
    ❌illegal
    ❌Duplicate template parameter name A
    
    (c) template<class A>
        void fun(A,A)
        {.....};
    ✅Legal
    Both parameters are of the same template type.
    
    (d) template<class T, typename R>
        T fun(T,R)
        {.....};
    ✅Legal
    Multiple template parameters with return type T.


    (e) template <class A>
        A fun(int *A)
        {.....};
    ❌ illegal
    ❌ A used both as type and variable name-> name conflict
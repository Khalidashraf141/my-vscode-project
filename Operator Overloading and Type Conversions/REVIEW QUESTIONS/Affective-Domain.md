### 7.11 — Defend the correctness of the following statements

1. (a) *Using the operator overloading concept, we can change the meaning of an operator.*  
    **Answer: True.** You can redefine an operator’s behavior for user-defined types (classes/enums). You cannot change precedence, associativity, or built-in type behavior.

2. (b) *Operator overloading works when applied to class objects only.*  
    **Answer: False.** At least one operand must be a user-defined type, but the other operand(s) may be built-in. Operators can be implemented as non-member functions too.

3. (c) *Friend functions cannot be used to overload operators.*  
    **Answer: False.** Friend (non-member) functions are commonly used when operator implementations need access to private members (e.g., symmetric binary ops).

4. (d) *When using an overloaded binary operator the left operand is implicitly passed to the member function.*  
    **Answer: True (for member overloads).** In member overloads the left operand is `*this`; in non-member overloads both operands are explicit parameters.

5. (e) *The overloaded operator must have at least one operand that is a user-defined type.*  
    **Answer: True.** C++ requires at least one operand to be a user-defined type to avoid changing built-in type behavior.

6. (f) *Operator functions never return a value.*  
    **Answer: False.** Operator functions can return values—e.g., `operator+` returns a new value; `operator=` typically returns `*this` (often by reference).

7. (g) *Through operator overloading, a class type data can be converted to a basic type data.*  
    **Answer: True.** Define a conversion operator like `operator T()` (implicit or `explicit`) to convert a class to another type.

8. (h) *A constructor can be used to convert a basic type to a class type data.*  
    **Answer: True.** A single-argument constructor enables conversion from the argument type to the class; mark it `explicit` to forbid implicit conversions.
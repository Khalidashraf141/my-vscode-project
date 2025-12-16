# Templates in C++

Templates enable writing a single function or class that works with different data types, facilitating generic programming in C++.

## What is Generic Programming?

Generic programming is a technique where functions and classes are written without specifying a particular data type, allowing the same code to work with multiple data types.

In C++, generic programming is implemented using **Templates**. This approach allows you to write code once and use it for various data types like `int`, `float`, `double`, etc.

---

## Templates vs Macros

While templates can be considered similar to macros in generating multiple versions of code from a single definition, templates are far superior.

### Similarities Between Templates and Macros:
- Both avoid code repetition.
- Both generate multiple forms of code.
- Both work on the idea of substitution.

### Differences Between Templates and Macros:

| **Aspect**          | **Macro**                     | **Template**                 |
|----------------------|-------------------------------|------------------------------|
| **Mechanism**        | Simple text substitution      | Type-based code generation   |
| **Type Checking**    | No type checking              | Type-safe                    |
| **Error Detection**  | Errors appear at runtime      | Errors caught at compile time|
| **Feature**          | Preprocessor feature          | Compiler feature             |

---

## Examples

### Macro Example
```cpp
#define max(a, b) ((a > b) ? a : b)
```

### Template Example
```cpp
template <class T>
T max(T a, T b) {
    return (a > b) ? a : b;
}
```

Templates provide type safety, better error detection, and are a more robust solution compared to macros.


Templates are powerful but compiler-dependent, hence portability issues may arise.

MSYS2 is not a C++ compiler; it is a development environment that includes modern C++ compilers like GCC and Clang.



Simple Analogy
MSYS2 = Kitchen 🍳

GCC / Clang = Stove 🔥 (actual cooking happens here)

You don’t cook on the kitchen — you cook on the stove.
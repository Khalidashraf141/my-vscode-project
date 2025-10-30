# **6.11 Defend the correctness of the following statements**

---

### **(a) Constructor, like other member function, can be declared anywhere in the class**

**Ans:**

* True. In C++, constructors are **member functions**, so they can be declared in any **access specifier section** (`public`, `private`, or `protected`) of the class.
* However, constructors are **usually declared public** so that objects can be created outside the class.

**Example:**

```cpp
class Demo {
private:
    Demo() { } // Constructor declared in private section
};
```

---

### **(b) Constructor do not return any values**

**Ans:**

* Correct. Constructors **do not have a return type**, not even `void`.
* They are used only for **initialization**, not for returning values.

**Example:**

```cpp
class Test {
    int x;
public:
    Test() { x = 10; } // No return type
};
```

---

### **(c) A constructor that accepts no parameter is known as the default constructor**

**Ans:**

* True. A **default constructor** is a constructor with **no parameters**.
* If no constructor is provided, the compiler supplies a **default constructor** automatically.

**Example:**

```cpp
class Student {
public:
    Student() { } // Default constructor
};
```

---

### **(d) A class should have at least one constructor**

**Ans:**

* True in the sense that a class **always has a constructor**.
* If you do not define any constructor, the **compiler provides a default constructor**.
* So, every class has **at least one constructor** either **user-defined or compiler-provided**.

---

### **(e) Destructor never take any argument**

**Ans:**

* Correct. Destructors **cannot take arguments** and **do not return any value**.
* Destructor syntax: `~ClassName() { }`
* Used only for **cleanup** when object is destroyed.

**Example:**

```cpp
class Test {
public:
    ~Test() { /* cleanup */ }
};
```

---

### **(f) The objects are always destroyed in the reverse order of their creation**

**Ans:**

* True. In C++, **local objects** are destroyed in **reverse order** of their creation (Last-In, First-Out).
* This ensures that dependencies between objects are handled correctly.

**Example:**

```cpp
#include <iostream>
using namespace std;

class Demo {
public:
    Demo(string n) { cout << n << " created\n"; }
    ~Demo() { cout << "Object destroyed\n"; }
};

int main() {
    Demo d1("First");
    Demo d2("Second");
    return 0;
}
```

**Output:**

```
First created
Second created
Object destroyed   // d2 destroyed first
Object destroyed   // d1 destroyed next
```

---

**✅ All statements defended with explanation and examples.**

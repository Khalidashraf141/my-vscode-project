### 8.15 — Implications of the two class definitions

### Definition (a): `class A : public B, public C { // ... };`

In this definition, class **A** is derived publicly from classes **B** and **C** in that specific order.

```cpp
class A : public B, public C {
    // ...
};
```

The **order of inheritance** determines the sequence of constructor and destructor calls, as well as the memory layout of the derived class.

---

### 🧩 Constructor Call Order

When an object of class `A` is created:

* The constructor of **B** is called **first**,
* then the constructor of **C**,
* and finally the constructor of **A**.

This order is **exactly as written** in the inheritance list, not according to the initializer list in the constructor.

✅ **Example:**

```cpp
#include <iostream>
using namespace std;

class B {
public:
    B() { cout << "B constructor\n"; }
};

class C {
public:
    C() { cout << "C constructor\n"; }
};

class A : public B, public C {
public:
    A() { cout << "A constructor\n"; }
};

int main() {
    A obj;
}
```

**Output:**

```
B constructor
C constructor
A constructor
```

---

### 🧩 Destructor Call Order

When the object of `A` is destroyed:

* The destructor of `A` runs first,
* then **C**'s destructor,
* and finally **B**'s destructor.

Thus, destructors are called in the **reverse order** of construction.

---

### 🧩 Memory Layout

The memory layout of the derived class `A` is arranged such that:

* Members of class **B** appear first,
* followed by members of class **C**,
* and finally the members of **A**.

This can influence memory organization and pointer conversions in low-level programming.

---

### 🧩 Ambiguity in Multiple Inheritance

If both base classes `B` and `C` define a member or function with the same name, the derived class `A` will face ambiguity when accessing it.

Example:

```cpp
class B { public: void show() { cout << "B\n"; } };
class C { public: void show() { cout << "C\n"; } };
class A : public B, public C {};

int main() {
    A obj;
    // obj.show(); ❌ Ambiguous
    obj.B::show(); ✅  // Calls B’s version
    obj.C::show(); ✅  // Calls C’s version
}
```

The compiler does **not** resolve this ambiguity based on inheritance order — you must explicitly specify the base class using the **scope resolution operator**.

---

### ✅ Summary

| Aspect                 | Behavior in `class A : public B, public C`       |
| ---------------------- | ------------------------------------------------ |
| Constructor call order | B → C → A                                        |
| Destructor call order  | A → C → B                                        |
| Memory layout          | B’s members first, then C’s                      |
| Ambiguity              | Must be resolved manually using scope resolution |

---

In short, when the order is `public B, public C`, class `B` is constructed and laid out **before** class `C`. This order impacts **construction, destruction, and memory arrangement** of the derived class.

 -----------------

### Definition (b): `class A : public C, public B { // ... };`

In this definition, class **A** is derived publicly from classes **C** and **B** in that specific order.

```cpp
class A : public C, public B {
    // ...
};
```

The **order of inheritance** plays an important role in determining how constructors, destructors, and memory layout behave.

---

### 🧩 Constructor Call Order

When an object of class `A` is created:

* The constructor of **C** is called **first**,
* then the constructor of **B**,
* and finally the constructor of **A** itself.

This order follows **exactly as written** in the inheritance list, not the order in the initializer list.

✅ **Example:**

```cpp
#include <iostream>
using namespace std;

class C {
public:
    C() { cout << "C constructor\n"; }
};

class B {
public:
    B() { cout << "B constructor\n"; }
};

class A : public C, public B {
public:
    A() { cout << "A constructor\n"; }
};

int main() {
    A obj;
}
```

**Output:**

```
C constructor
B constructor
A constructor
```

---

### 🧩 Destructor Call Order

When the object of `A` is destroyed:

* The destructor of `A` runs first,
* then **B**'s destructor,
* and finally **C**'s destructor.

So, the destruction order is the **reverse** of the construction order.

---

### 🧩 Memory Layout

The memory of the derived class `A` will be arranged such that:

* Members of class **C** come first,
* followed by members of class **B**,
* then members of class **A**.

This can matter in low-level memory operations, object slicing, or pointer conversions.

---

### 🧩 Ambiguity in Multiple Inheritance

If both `B` and `C` have a function or variable with the same name, class `A` will face ambiguity when trying to access it.

Example:

```cpp
class C { public: void show() { cout << "C\n"; } };
class B { public: void show() { cout << "B\n"; } };
class A : public C, public B {};

int main() {
    A obj;
    // obj.show(); ❌ Ambiguous
    obj.C::show(); ✅  // Calls C’s version
    obj.B::show(); ✅  // Calls B’s version
}
```

The **order of inheritance** does not automatically resolve such ambiguities; you must explicitly specify which base class’s function to call.

---

### ✅ Summary

| Aspect                 | Behavior in `class A : public C, public B`       |
| ---------------------- | ------------------------------------------------ |
| Constructor call order | C → B → A                                        |
| Destructor call order  | A → B → C                                        |
| Memory layout          | C’s members first, then B’s                      |
| Ambiguity              | Must be resolved manually using scope resolution |

---

In short, when the order is `public C, public B`, class `C` is constructed and laid out **before** class `B`. This order affects **initialization, destruction, and memory arrangement** of the derived class.



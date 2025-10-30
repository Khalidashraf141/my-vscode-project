### 8.1 — What is inheritance in C++?
Inheritance is the mechanism of creating a new class (derived) from an existing class (base) so the derived class reuses and extends the base class's members.

---

### 8.2 — Forms of inheritance (with examples)
C++ supports several forms of inheritance. Below are brief descriptions and small, correct examples for each.

1. Single inheritance  
    One base class → one derived class.
    ```cpp
    #include <iostream>
    using namespace std;

    class Animal {
    public:
         void eat() { cout << "Eating...\n"; }
    };

    class Dog : public Animal {
    public:
         void bark() { cout << "Barking...\n"; }
    };

    int main() {
         Dog d;
         d.eat();  // from Animal
         d.bark(); // from Dog
         return 0;
    }
    ```

2. Multiple inheritance  
    One derived class inherits from multiple base classes.
    ```cpp
    #include <iostream>
    using namespace std;

    class Teacher {
    public:
         void teach() { cout << "Teaching...\n"; }
    };

    class Researcher {
    public:
         void research() { cout << "Researching...\n"; }
    };

    class Professor : public Teacher, public Researcher {
    public:
         void guide() { cout << "Guiding students...\n"; }
    };

    int main() {
         Professor p;
         p.teach();
         p.research();
         p.guide();
         return 0;
    }
    ```

3. Multilevel inheritance  
    A chain of inheritance: base → derived → more-derived.
    ```cpp
    #include <iostream>
    using namespace std;

    class LivingThing {
    public:
         void breathe() { cout << "Breathing...\n"; }
    };

    class Animal : public LivingThing {
    public:
         void move() { cout << "Moving...\n"; }
    };

    class Bird : public Animal {
    public:
         void fly() { cout << "Flying...\n"; }
    };

    int main() {
         Bird b;
         b.breathe();
         b.move();
         b.fly();
         return 0;
    }
    ```

4. Hierarchical inheritance  
    One base class → multiple derived classes.
    ```cpp
    #include <iostream>
    using namespace std;

    class Vehicle {
    public:
         void start() { cout << "Starting vehicle...\n"; }
    };

    class Car : public Vehicle {
    public:
         void drive() { cout << "Driving car...\n"; }
    };

    class Bike : public Vehicle {
    public:
         void ride() { cout << "Riding bike...\n"; }
    };

    int main() {
         Car c;
         Bike b;
         c.start(); c.drive();
         b.start(); b.ride();
         return 0;
    }
    ```

5. Hybrid inheritance  
    A combination of two or more types (e.g., multiple + multilevel). Virtual inheritance can be used to avoid ambiguity (the diamond problem).
    ```cpp
    #include <iostream>
    using namespace std;

    class Person {
    public:
         void info() { cout << "Person info\n"; }
    };

    class Student : virtual public Person {
    public:
         void study() { cout << "Studying...\n"; }
    };

    class Employee : virtual public Person {
    public:
         void work() { cout << "Working...\n"; }
    };

    // Hybrid: multiple + multilevel
    class WorkingStudent : public Student, public Employee {
    public:
         void manageTime() { cout << "Managing study and work...\n"; }
    };

    int main() {
         WorkingStudent ws;
         ws.info();       // single shared Person
         ws.study();
         ws.work();
         ws.manageTime();
         return 0;
    }
    ```

Notes:
- Use virtual inheritance when multiple paths to the same base class can cause ambiguity.
- Keep access specifiers (public/protected/private) in mind when designing class hierarchies.
- Prefer composition over inheritance when "has-a" is more appropriate than "is-a".

    --

### 8.3 - Describe the syntax of single inheritance in C++.

# 🧠 Single Inheritance in C++

## 📘 Meaning

In **single inheritance**, **one base class** gives its properties and functions to **one derived class**.  
It is the simplest and most commonly used form of inheritance.

---

## ⚙️ Syntax

```cpp
class DerivedClassName : access-specifier BaseClassName
{
    // members of the derived class
};
```

---

### 🧩 Explanation of Each Part

| Part | Meaning |
|------|----------|
| `class DerivedClassName` | Defines the new class (child class) |
| `:` | Indicates inheritance |
| `access-specifier` | Defines how base class members are accessible (public/private/protected) |
| `BaseClassName` | The class being inherited from (parent class) |

---

## 🔹 Access Specifiers in Inheritance

| Access Specifier | Meaning |
|------------------|----------|
| `public` | Public and protected members of the base class remain accessible (public → public, protected → protected). |
| `protected` | Public and protected members of the base class become protected in the derived class. |
| `private` | All public and protected members of the base class become private in the derived class. |

---

## 💡 Example: Single Inheritance

```cpp
#include <iostream>
using namespace std;

class Animal       // Base class
{
public:
    void eat()
    {
        cout << "Eating..." << endl;
    }
};

class Dog : public Animal   // Derived class (single inheritance)
{
public:
    void bark()
    {
        cout << "Barking..." << endl;
    }
};

int main()
{
    Dog d;
    d.eat();   // Inherited from Animal
    d.bark();  // Defined in Dog
    return 0;
}
```

---

### 🖥️ Output

```
Eating...
Barking...
```

---

### 🧩 Explanation

- `Dog` is derived from `Animal`.  
- `Dog` can use all **public members** of `Animal`.  
- This is an example of **single inheritance**, since there’s only **one base** and **one derived** class.

---

### ✅ In Simple Words

> Single inheritance = one base class → one derived class.  
> It allows the derived class to reuse the code of the base class.




### 8.4 - We know that **private members of a base class are not inheritable**. However, objects of a derived class can still access them indirectly using the following methods — without modifying the base class.

---

## 🔹 1. Using Public or Protected Member Functions of the Base Class

If the base class already provides public or protected member functions (like getters and setters) that access its private members, then the derived class can call these functions to access those members indirectly.

### Example:
```cpp
#include <iostream>
using namespace std;

class Base {
private:
    int x = 10; // Private member

public:
    int getX() {  // Public function to access private data
        return x;
    }
};

class Derived : public Base {
public:
    void show() {
        cout << "Value of x: " << getX() << endl; // Access via base class function
    }
};

int main() {
    Derived obj;
    obj.show();
    return 0;
}
```

✅ **Explanation:**  
Here, `x` is private in `Base` and cannot be directly accessed by `Derived`. However, since `getX()` is public, it acts as a **bridge** to access `x` indirectly.

---

## 🔹 2. Using a Friend Function or Friend Class (if already defined in Base)

If the base class has declared a friend function or class, then that friend can access its private members — even from derived class objects.

### Example:
```cpp
#include <iostream>
using namespace std;

class Base {
private:
    int secret = 42;

    // Friend function
    friend void showSecret(Base b);
};

void showSecret(Base b) {
    cout << "Secret value: " << b.secret << endl;
}

class Derived : public Base {};

int main() {
    Derived d;
    showSecret(d); // Accesses private member via friend
    return 0;
}
```

✅ **Explanation:**  
The friend function `showSecret()` can access private data of `Base`, even when called with an object of the derived class.

---

## 🔹 3. Accessing via Pointer or Reference to Base

Although the derived class cannot access private members directly, you can use a pointer or reference to the base class and call its public member functions to access the private data.

### Example:
```cpp
#include <iostream>
using namespace std;

class Base {
private:
    int x = 99;

public:
    int getX() { return x; }
};

class Derived : public Base {
public:
    void access(Base* b) {
        cout << "Accessing base private member via pointer: " << b->getX() << endl;
    }
};

int main() {
    Derived d;
    d.access(&d);
    return 0;
}
```

✅ **Explanation:**  
The derived class uses a **base class pointer** to call `getX()`, which internally accesses the private member.

---

## 🧠 Conclusion

Although private members are **not directly inherited**, they can still be **accessed indirectly** using:

1. Public or protected member functions of the base class  
2. Friend functions or friend classes (if already defined)  
3. Pointers or references to the base class

These methods respect encapsulation and do **not require modifying the base class**.


### 8.5 - Differentiate between the properties of the following two derived classes:
          (a) class D1 : private B { ... };
          (b) class D2:public  B{//...};

## Class Definitions
```cpp
class D1 : private B {
    // private inheritance
};

class D2 : public B {
    // public inheritance
};
```

---

## 🔹 1. Accessibility of Base Class Members

| Base Class Member Type | In `D1 : private B` | In `D2 : public B` |
|------------------------|---------------------|--------------------|
| `public` members       | Become **private**  | Remain **public**  |
| `protected` members    | Become **private**  | Remain **protected** |
| `private` members      | **Not inherited**   | **Not inherited**  |

---

## 🔹 2. Accessibility to Objects of Derived Class

| Access Type | D1 Object | D2 Object |
|--------------|------------|-----------|
| Can access base class members directly? | ❌ No | ✅ Yes (if public) |
| Example | `d1.baseFunc()` ❌ | `d2.baseFunc()` ✅ |

<sub>Legend: ✅ = Yes, ❌ = No</sub>

---

## 🔹 3. Further Inheritance

| Can be used as base for another class | ✅ Yes, but base class members become private | ✅ Yes, base class members retain visibility |
|-----------|----|----|
| Can be used as base for another class | ✅ Yes, but **base class members become private**, so not accessible further | ✅ Yes, and **base class members retain visibility** |

---

## 🔹 4. Example

```cpp
#include <iostream>
using namespace std;

class Base {
public:
    void show() { cout << "Base class function\n"; }
};

class D1 : private Base {
    // private inheritance
public:
    void display() {
        show();  // accessible within derived class
    }
};

class D2 : public Base {
    // public inheritance
};

int main() {
    D1 obj1;
    obj1.display();  // ✅ works
    // The following line will cause a compilation error because 'show()' becomes private in D1 due to private inheritance:
    // obj1.show();  ❌ Error: show() is private in D1

    D2 obj2;
    obj2.show();     // ✅ works (publicly inherited)
}
```

---

## ✅ Summary

| Feature | `D1 : private B` | `D2 : public B` |
|----------|------------------|----------------|
| Public base members become | Private | Public |
| Protected base members become | Private | Protected |
| Private base members become | Not inherited | Not inherited |
| Accessibility to base class members by object | No | Yes |
| Usability for further inheritance | Limited | Full |

---

**Conclusion:**  
➡ Use **public inheritance** when you want to model an “is-a” relationship.  
➡ Use **private inheritance** when you want to use features of the base class **internally**, not publicly expose them.


### 8.6 - Point out when to use the protected visibility specifier to a class member.

## 🔹 What is `protected`?

The `protected` access specifier in C++ allows class members to be **accessible within the class itself** and **by derived classes**, but **not by outside functions or objects**.

It acts as a middle ground between `private` and `public`.

---

## 🔹 Syntax

```cpp
class Base {
protected:
    int data;   // protected member
};
```

---

## 🔹 When to Use `protected`

| Situation | Description | Example |
|------------|-------------|----------|
| **1. You want derived classes to access certain data of the base class directly** | Use `protected` when the data should not be accessible to the outside world, but you still want subclasses to modify or use it. | A derived class that needs to reuse or update internal base class data. |
| **2. You are designing a class meant for inheritance** | Helps subclasses extend functionality without exposing data publicly. | When making a base class like `Shape`, `Vehicle`, or `Account`. |
| **3. You want to prevent direct object access but allow inheritance-based modification** | Keeps data safe from the user but usable by child classes. | For example, making `balance` protected in a `BankAccount` class. |

---

## 🔹 Example

```cpp
#include <iostream>
using namespace std;

class Account {
protected:
    double balance;  // accessible to derived classes
public:
    Account(double bal) : balance(bal) {}
};

class Savings : public Account {
public:
    Savings(double bal) : Account(bal) {}
    void addInterest() {
        balance += balance * 0.05;  // access to protected member
    }
    void showBalance() {
        cout << "Balance: " << balance << endl;
    }
};

int main() {
    Savings s(1000);
    s.addInterest();
    s.showBalance();   // ✅ works
    // s.balance = 500; ❌ error: 'balance' is protected
}
```

---

## ✅ Summary

| Access Specifier | Accessible in Same Class | Accessible in Derived Class | Accessible Outside Class |
|------------------|--------------------------|-----------------------------|---------------------------|
| `public` | ✅ Yes | ✅ Yes | ✅ Yes |
| `protected` | ✅ Yes | ✅ Yes | ❌ No |
| `private` | ✅ Yes | ❌ No | ❌ No |

---

## 💡 Use `protected` When:
- You want **controlled inheritance access**.  
- You want to **allow derived classes to reuse or modify** base class members.  
- You want to **hide implementation details** from external code.

---

### 8.7 - Describe the syntax of multiple inheritance; also briefly state the usability such an inheritance.

## 🔹 Definition

**Multiple Inheritance** is a feature in C++ where a derived class can **inherit from more than one base class**.  
This allows the derived class to combine and use features (data and functions) from multiple base classes.

---

## 🔹 Syntax

```cpp
class Derived : visibility Base1, visibility Base2, ... {
    // body of derived class
};
```

### Example:
```cpp
#include <iostream>
using namespace std;

class A {
public:
    void displayA() {
        cout << "Class A function" << endl;
    }
};

class B {
public:
    void displayB() {
        cout << "Class B function" << endl;
    }
};

// Derived class inherits from both A and B
class C : public A, public B {
public:
    void displayC() {
        cout << "Class C function" << endl;
    }
};

int main() {
    C obj;
    obj.displayA();   // from class A
    obj.displayB();   // from class B
    obj.displayC();   // from class C
    return 0;
}
```

---

## 🔹 Usability of Multiple Inheritance

| Situation | Description | Example |
|------------|-------------|----------|
| **1. When a class requires functionalities of multiple base classes** | Allows combining behavior from two or more unrelated classes. | Example: `SmartPhone` class inheriting from both `Camera` and `Phone`. |
| **2. For modular and reusable design** | Each base class can represent an independent feature, and the derived class can reuse those features. | Example: `Student` inheriting from `Person` and `AcademicRecord`. |
| **3. For real-world modeling** | Real-world entities often share characteristics of multiple parents. | Example: `AmphibiousVehicle` inheriting from both `Car` and `Boat`. |

---

## ⚠️ Note on Ambiguity

- If two base classes have a function with the **same name**, the derived class must **explicitly specify** which base class function to use:
  
  ```cpp
  obj.A::show();
  obj.B::show();
  ```

- This helps avoid ambiguity in function calls.

---

## ✅ Summary

| Feature | Description |
|----------|--------------|
| **Definition** | Inheriting from more than one base class |
| **Syntax** | `class Derived : public Base1, public Base2 { };` |
| **Advantage** | Combines features of multiple classes |
| **Drawback** | Can cause ambiguity if same members exist in base classes |
| **Common Use** | For hybrid designs or feature-combined classes |

---

**Conclusion:**  
Multiple inheritance is powerful but should be used carefully to avoid **ambiguity and complexity**.  
It’s most effective when combining independent functionalities from multiple sources.


### 8.8 - Express a virtual base class.

## 🔹 Definition

A **virtual base class** is used in C++ to **avoid multiple copies of a base class** when using **multiple inheritance**.  
It helps solve the **“Diamond Problem”** — a situation where a derived class inherits the same base class through multiple paths.

---

## 🔹 Syntax

```cpp
class A { ... };

class B : virtual public A { ... };
class C : virtual public A { ... };

class D : public B, public C { ... };
```

Here, `A` is made a **virtual base class** of both `B` and `C`.  
When `D` inherits from both `B` and `C`, only **one copy of `A`** is shared.

---

## 🔹 Example: Without Virtual Base Class

```cpp
#include <iostream>
using namespace std;

class A {
public:
    int x;
};

class B : public A {};
class C : public A {};

class D : public B, public C {};

int main() {
    D obj;
    // obj.x = 10; ❌ Error: Ambiguity (two copies of A exist)
    obj.B::x = 10;
    obj.C::x = 20;

    cout << "B::x = " << obj.B::x << endl;
    cout << "C::x = " << obj.C::x << endl;
}
```

### Output:
```
B::x = 10
C::x = 20
```

There are **two copies of `A`**, one via `B` and one via `C`.

---

## 🔹 Example: With Virtual Base Class

```cpp
#include <iostream>
using namespace std;

class A {
public:
    int x;
};

class B : virtual public A {};
class C : virtual public A {};

class D : public B, public C {};

int main() {
    D obj;
    obj.x = 100;   // ✅ Only one shared copy of A

    cout << "x = " << obj.x << endl;
}
```

### Output:
```
x = 100
```

✅ Now there is **only one copy of `A`**, shared by `B` and `C`.

---

## 🔹 Why Use Virtual Base Classes?

| Problem | Solution via Virtual Base Class |
|----------|--------------------------------|
| Duplicate copies of base class data | Shared single copy |
| Ambiguity in member access | Eliminates confusion |
| Inefficient memory usage | Saves memory by keeping one base instance |

---

## ✅ Summary

| Feature | Description |
|----------|-------------|
| **Purpose** | Avoids multiple copies of a base class in multiple inheritance |
| **Keyword** | `virtual` |
| **Used in** | Diamond-shaped inheritance hierarchies |
| **Advantage** | Removes ambiguity and redundancy |
| **Example Syntax** | `class B : virtual public A { };` |

---

**Conclusion:**  
A **virtual base class** ensures that only **one common instance** of the base class exists when it is inherited through multiple paths, preventing **ambiguity and redundancy** in inheritance.


### 8.9 - Explain when to make a class virtual.

## 🧩 Explanation

A **virtual base class** is used in **multiple inheritance** to **avoid ambiguity** and **duplicate copies** of the base class when it appears more than once in the inheritance hierarchy.

You should make a class **virtual** when it is **inherited by multiple derived classes**, and those derived classes are **further inherited by another class**.

This situation is commonly known as the **“Diamond Problem.”**

---

## 💡 Example

```cpp
#include <iostream>
using namespace std;

class Base {
public:
    void show() {
        cout << "Base class function" << endl;
    }
};

class Derived1 : virtual public Base {};
class Derived2 : virtual public Base {};

class Final : public Derived1, public Derived2 {};

int main() {
    Final obj;
    obj.show();  // No ambiguity
    return 0;
}
```

---

## 📘 Without Virtual Keyword
If we remove the keyword `virtual` from the above code, then:
- `Final` class will inherit **two copies** of the `Base` class — one through `Derived1` and another through `Derived2`.
- Calling `obj.show()` will cause an **ambiguity error**.

---

## ✅ When to Use `virtual`
Use **virtual inheritance** when:
1. The **same base class** is inherited **multiple times** indirectly.
2. You want to **avoid duplicate copies** of base class members.
3. You want a **single shared instance** of the base class.


### 8.10 - Discuss about abstract class.

# 🧩 Abstract Classes in C++

## 🔹 Definition
An **abstract class** is a class that **cannot be instantiated directly**.  
It serves as a **base class** for other classes and is meant to provide a **common interface** for all derived classes.

An abstract class contains at least one **pure virtual function**.

A **pure virtual function** is declared using this syntax:
```cpp
virtual void functionName() = 0;
```

---

## 🔹 Purpose of Abstract Classes
Abstract classes are used to:

- Define a **common interface** for all derived classes.  
- Enforce that **certain functions must be implemented** by all derived classes.  
- Promote **code reusability**, **polymorphism**, and **structured design**.

---

## 🔹 Syntax
```cpp
#include <iostream>
using namespace std;

class Shape {
public:
    virtual void area() = 0;  // Pure virtual function
};
```

Here, `Shape` is an abstract class because it contains a **pure virtual function** `area()`.

---

## 🔹 Example
```cpp
#include <iostream>
using namespace std;

class Shape {
public:
    virtual void area() = 0; // Pure virtual function
};

class Circle : public Shape {
    float radius;
public:
    Circle(float r) { radius = r; }
    void area() {
        cout << "Area of Circle: " << 3.14 * radius * radius << endl;
    }
};

int main() {
    // Shape s; ❌ Error: Cannot create object of abstract class
    Circle c(5);
    c.area(); // ✅ Works fine
    return 0;
}
```

---

## 🔹 Key Points
1. You **cannot create objects** of an abstract class.  
2. You **can create pointers or references** of an abstract class type.  
3. If a derived class **does not override** all pure virtual functions, it also becomes **abstract**.  
4. Abstract classes are mainly used to achieve **runtime polymorphism**.

---

## 🔹 Real-Life Example
Imagine an abstract class `Payment` that defines a common rule for all payment methods:
```cpp
class Payment {
public:
    virtual void processPayment() = 0; // pure virtual function
};
```

Derived classes can define their own implementations:
```cpp
class CreditCardPayment : public Payment {
public:
    void processPayment() {
        cout << "Processing Credit Card Payment" << endl;
    }
};

class PayPalPayment : public Payment {
public:
    void processPayment() {
        cout << "Processing PayPal Payment" << endl;
    }
};

int main() {
    Payment* p1 = new CreditCardPayment();
    Payment* p2 = new PayPalPayment();

    p1->processPayment();
    p2->processPayment();

    delete p1;
    delete p2;

    return 0;
}
```

---

## ✅ **Summary**
| Concept | Description |
|----------|--------------|
| **Abstract Class** | A class with at least one pure virtual function. |
| **Pure Virtual Function** | Declared as `virtual void func() = 0;` |
| **Instantiation** | Not possible for abstract classes. |
| **Usage** | Provides a common interface for derived classes. |
| **Example** | `Shape`, `Payment`, etc. |

---

⭐ **In short:**  
Abstract classes in C++ define a **template or blueprint** for other classes to follow, ensuring **consistency** and **polymorphism** in object-oriented design.


### 8.11 - Break down the order in which the class constructors are called when a derived class object is created.

# 🧩 Order of Constructor Calls in Inheritance (C++)

## 🔹 Introduction
When a **derived class object** is created, multiple constructors are called — starting from the **base class** and moving toward the **derived class**.

This ensures that **base class members** are properly initialized **before** the derived class tries to use them.

---

## 🔹 Order of Constructor Execution

When an object of a derived class is created:
1. **Base class constructor** is called first.  
2. Then, the **derived class constructor** is called.

If there are **multiple base classes**, the order of constructor calls follows the **order of inheritance declaration** in the derived class definition.

---

## 🔹 Example 1 — Single Inheritance
```cpp
#include <iostream>
using namespace std;

class Base {
public:
    Base() {
        cout << "Base constructor called" << endl;
    }
};

class Derived : public Base {
public:
    Derived() {
        cout << "Derived constructor called" << endl;
    }
};

int main() {
    Derived obj;
    return 0;
}
```

### 🧠 **Output:**
```
Base constructor called
Derived constructor called
```

✅ **Explanation:**
- When `obj` is created, C++ first calls the **Base constructor**, then the **Derived constructor**.

---

## 🔹 Example 2 — Multiple Inheritance
```cpp
#include <iostream>
using namespace std;

class A {
public:
    A() { cout << "A constructor called" << endl; }
};

class B {
public:
    B() { cout << "B constructor called" << endl; }
};

class C : public B, public A {
public:
    C() { cout << "C constructor called" << endl; }
};

int main() {
    C obj;
    return 0;
}
```

### 🧠 **Output:**
```
B constructor called
A constructor called
C constructor called
```

✅ **Explanation:**
- Constructors are called in the **order of inheritance declaration**, not the order of appearance in the program.
- Since `C` is derived as `class C : public B, public A`,  
  → `B()` is called first, then `A()`, and finally `C()`.

---

## 🔹 Example 3 — Multilevel Inheritance
```cpp
#include <iostream>
using namespace std;

class A {
public:
    A() { cout << "A constructor called" << endl; }
};

class B : public A {
public:
    B() { cout << "B constructor called" << endl; }
};

class C : public B {
public:
    C() { cout << "C constructor called" << endl; }
};

int main() {
    C obj;
    return 0;
}
```

### 🧠 **Output:**
```
A constructor called
B constructor called
C constructor called
```

✅ **Explanation:**
- Constructors are called from **top to bottom** in the inheritance hierarchy.

---

## 🔹 Example 4 — Virtual Base Class
When **virtual base classes** are used, their constructors are called **before** all other base classes.

```cpp
#include <iostream>
using namespace std;

class A {
public:
    A() { cout << "A constructor called" << endl; }
};

class B : virtual public A {
public:
    B() { cout << "B constructor called" << endl; }
};

class C : virtual public A {
public:
    C() { cout << "C constructor called" << endl; }
};

class D : public B, public C {
public:
    D() { cout << "D constructor called" << endl; }
};

int main() {
    D obj;
    return 0;
}
```

### 🧠 **Output:**
```
A constructor called
B constructor called
C constructor called
D constructor called
```

✅ **Explanation:**
- Virtual base class constructors (`A`) are called **only once**, even if inherited multiple times.
- After that, constructors for `B`, `C`, and finally `D` are executed.

---

## 🔹 Summary Table

| Inheritance Type | Constructor Call Order |
|------------------|------------------------|
| **Single** | Base → Derived |
| **Multiple** | In order of inheritance declaration |
| **Multilevel** | Top → Bottom in hierarchy |
| **Virtual Base** | Virtual Base → Other Bases → Derived |

---

⭐ **In short:**  
When a derived class object is created, **constructors execute in the order of inheritance** — starting from **base classes first**, then moving to **derived classes**.


### 8.13 - Outline containership and distinguish it with inheritance.

# Containership vs Inheritance

## Containership (Composition)
Containership means **creating objects of one class inside another class**.  
It is also called **“has-a” relationship**.  

### Example:
```cpp
class Engine {
public:
    void start() {
        cout << "Engine started!" << endl;
    }
};

class Car {
    Engine e;  // Car has an Engine
public:
    void drive() {
        e.start();
        cout << "Car is moving!" << endl;
    }
};
```

👉 Here, `Car` **contains** an object of `Engine`.  
This means **Car has an Engine**, not **Car is an Engine**.

---

## Inheritance
Inheritance means **deriving a new class from an existing one**.  
It is called **“is-a” relationship**.  

### Example:
```cpp
class Vehicle {
public:
    void move() {
        cout << "Vehicle is moving!" << endl;
    }
};

class Car : public Vehicle {
public:
    void honk() {
        cout << "Car horn!" << endl;
    }
};
```

👉 Here, `Car` **inherits** from `Vehicle`, so **Car is a Vehicle**.

---

## Difference Between Containership and Inheritance

| **Basis** | **Containership (Composition)** | **Inheritance** |
|------------|--------------------------------|----------------|
| **Relationship Type** | "Has-a" relationship | "Is-a" relationship |
| **Implementation** | One class has another class as a data member | One class derives from another class |
| **Dependency** | Loosely coupled (less dependent) | Strongly coupled (tightly linked hierarchy) |
| **Reusability** | Reuses class functionality via object creation | Reuses class functionality via inheritance |
| **Example** | Car **has** an Engine | Car **is** a Vehicle |

---

✅ **In short:**  
- Use **containership** when one class uses another as a part or component.  
- Use **inheritance** when one class is a specialized form of another.


### 8.14 - Demonstrate the creation of an object of a class that contains objects of other classes.

In **C++**, one class can contain objects of other classes. This concept is known as **containership** or **composition**.  
It represents a **"has-a" relationship** between classes.

---

## Example Code

```cpp
#include <iostream>
using namespace std;

class Engine {
public:
    Engine() {
        cout << "Engine started." << endl;
    }
};

class Car {
    Engine e; // Car has an Engine object
public:
    Car() {
        cout << "Car constructed." << endl;
    }
};

int main() {
    Car c1; // When Car object is created, Engine object is also created automatically
    return 0;
}
```

---

## Explanation

1. The `Car` class contains an object of the `Engine` class.  
   This means every `Car` **has an Engine**.

2. When the object `c1` of class `Car` is created:
   - The **constructor of `Engine`** is called **first**.
   - Then the **constructor of `Car`** is executed.

3. Similarly, during destruction:
   - The **destructor of `Car`** is called first.
   - Then the **destructor of `Engine`** is called.

---

## Output

```
Engine started.
Car constructed.
```

---

## Key Point

- Containership models real-world relationships, e.g.,  
  - A **Car has an Engine**  
  - A **Human has a Heart**  
  - A **Computer has a CPU**  
- The contained object (like `Engine`) automatically gets created and destroyed with the container object (like `Car`).


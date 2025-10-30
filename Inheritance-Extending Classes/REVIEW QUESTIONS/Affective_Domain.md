# Affective Domain

## 1. Inheritance helps in making a general class into a more specific class.
**Answer:**  
True. Inheritance allows a programmer to create a new class (derived class) from an existing one (base class).  
The derived class can add new features or modify existing ones, making it more specific while reusing the general properties of the base class.

---

## 2. Inheritance aids data hiding.
**Answer:**  
Partly true. Inheritance allows controlled access to base class members using access specifiers (`private`, `protected`, `public`).  
Private members of the base class are not inherited, which helps in data hiding. However, inheritance itself doesn’t ensure hiding; it supports it through access control.

---

## 3. One of the advantages of inheritance is that it provides a conceptual framework.
**Answer:**  
True. Inheritance provides a logical structure in programming that reflects real-world relationships.  
It supports reusability, modularity, and helps organize code by showing “is-a” relationships among classes.

---

## 4. Inheritance facilitates the creation of class libraries.
**Answer:**  
True. With inheritance, base classes can define general-purpose code that can be reused by derived classes.  
This allows programmers to build class libraries containing reusable and extendable code components.

---

## 5. Defining a derived class requires some changes in the base class.
**Answer:**  
False. A derived class can be defined without changing the base class.  
Inheritance is designed to extend functionality without modifying the original base class, ensuring reusability and encapsulation.

---

## 6. A base class is never used to create objects.
**Answer:**  
False. A base class can be used to create objects unless it is an **abstract class** (i.e., contains at least one pure virtual function).  
Ordinary base classes can have objects; abstract ones cannot.

---

## 7. It is legal to have an object of one class as a member of another class.
**Answer:**  
True. This is known as **containership** or **composition**.  
It allows one class to contain an object of another class as a data member.

**Example:**
```cpp
class Engine {
public:
    void start() { cout << "Engine started!"; }
};

class Car {
    Engine e;
public:
    void drive() {
        e.start();
        cout << "Car is moving!";
    }
};
```
Here, the `Car` class contains an `Engine` object — a valid and common concept in C++.

---

## 8. We can prevent the inheritance of all members of the base class by making the base class virtual in the definition of the derived class.
**Answer:**  
False. Virtual inheritance does not prevent inheritance; it only prevents **duplication** of base class members in multiple inheritance.

**Example:**
```cpp
class A {};
class B : virtual public A {};
class C : virtual public A {};
class D : public B, public C {};  // Only one copy of A exists in D
```
Here, `A` is still inherited, but only once. To truly prevent inheritance, we can declare the base class as `final` or make its constructors private.

---

**✅ Final Summary:**  
Virtual inheritance avoids duplication, not inheritance.  
Access specifiers (`private`, `protected`, `public`) control visibility, and abstract classes restrict object creation.
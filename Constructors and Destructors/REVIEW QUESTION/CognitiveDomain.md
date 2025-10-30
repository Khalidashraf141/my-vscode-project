# **Constructors and Destructors in C++**

---

### **Q1. Illustrate about constructor; also relate whether it is mandatory to use constructor in a class.**

**Ans:**
A **constructor** is a **special member function** of a class which is **automatically invoked** when an object of that class is created.
It is mainly used to **initialize the data members** of the class.

**Key Points:**

* Same name as the class.
* No return type, not even `void`.
* Types of constructors: **Default**, **Parameterized**, **Copy**.
* **Not mandatory** to use a constructor; if none is defined, the compiler provides a default constructor.
* Useful to **initialize objects with specific values** at creation.

---

### **Q2. Devise invoking of constructor function.**

**Ans:**

* A **constructor is automatically invoked** whenever an object of the class is created.
* You **do not call it explicitly**.
* Example:

```cpp
#include <iostream>
using namespace std;

class Demo {
public:
    Demo() {
        cout << "Constructor called automatically!\n";
    }
};

int main() {
    Demo obj; // Constructor invoked here
    return 0;
}
```

---

### **Q3. List some of the special properties of the constructor functions.**

**Ans:**

1. **Same name as the class:** Matches exactly.
2. **No return type:** Not even `void`.
3. **Automatic invocation:** Called when object is created.
4. **Used for initialization:** Sets initial values of data members.
5. **Can be overloaded:** Multiple constructors with different parameter lists are allowed.
6. **Cannot be inherited** but can be called by derived class.
7. **Cannot be virtual.**

---

### **Q4. Illustrate parameterized constructor.**

**Ans:**
A **parameterized constructor** accepts one or more arguments and **initializes objects with specific values**.

```cpp
#include <iostream>
using namespace std;

class Student {
    string name;
    int age;
public:
    Student(string n, int a) { // Parameterized constructor
        name = n;
        age = a;
    }
    void display() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

int main() {
    Student s1("Khalid", 18);
    Student s2("Danish", 16);
    s1.display();
    s2.display();
    return 0;
}
```

---

### **Q5. More than one constructors are possible in a class. Justify the correctness of the statement; also assess the need for such a situation.**

**Ans:**

* Yes, multiple constructors are allowed (**constructor overloading**) with **different parameter lists**.
* The **correct constructor** is called automatically depending on the arguments passed.

**Need for Multiple Constructors:**

1. Initialize objects in **different ways**.
2. Provide **flexibility** for default or specific values.
3. Make object creation **convenient**.

---

### **Q6. Interpret dynamic initialization of object and its need.**

**Ans:**

* **Dynamic initialization** means **assigning values to objects at runtime**, not at compile time.
* Done using **parameterized constructors** or **user input**.

**Need:**

1. When values are **not known in advance**.
2. To allow **runtime input or calculations**.
3. Makes programs **flexible and interactive**.

---

### **Q7. Demonstrate the dynamic initialization of objects.**

```cpp
#include <iostream>
using namespace std;

class Student {
    string name;
    int age;
public:
    Student(string n, int a) { // Parameterized constructor
        name = n;
        age = a;
    }
    void display() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

int main() {
    string sname;
    int sage;
    cout << "Enter student name: ";
    cin >> sname;
    cout << "Enter student age: ";
    cin >> sage;

    Student s1(sname, sage); // Dynamic initialization
    s1.display();
    return 0;
}
```

---

### **Q8. Rewrite the function of default constructor.**

```cpp
#include <iostream>
using namespace std;

class Student {
    string name;
    int age;
public:
    Student() { // Default constructor
        name = "Unknown";
        age = 0;
    }
    void display() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

int main() {
    Student s1; // Default constructor called
    s1.display();
    return 0;
}
```

**Important Points:**

* Called automatically.
* No parameters.
* Sets **default values**.

---

### **Q9. Distinguish between the following two statements:**

```
time t2(T1);
time t2 = t1;
```

| Statement       | Meaning                   | Notes                                                                      |
| --------------- | ------------------------- | -------------------------------------------------------------------------- |
| `time t2(T1);`  | **Direct initialization** | Calls copy constructor explicitly                                          |
| `time t2 = t1;` | **Copy initialization**   | Also calls copy constructor; looks like assignment but happens at creation |

**Important:** Both invoke **copy constructor** automatically.

---

### **Q10. Describe the importance of destructor. Explain its use with help of an example.**

**Ans:**
A **destructor** is a special member function called automatically when an object **goes out of scope**.

**Importance:**

1. Frees **dynamically allocated memory**.
2. Cleans up **resources** (files, database, network).
3. Prevents **memory leaks**.

**Syntax:**

```cpp
~ClassName() {
    // cleanup code
}
```

**Example:**

```cpp
#include <iostream>
using namespace std;

class Test {
    int *ptr;
public:
    Test(int size) { 
        ptr = new int[size]; 
        cout << "Constructor: Memory allocated for array of size " << size << endl;
    }
    void show() {
        cout << "Array at memory location: " << ptr << endl;
    }
    ~Test() {
        delete[] ptr; // Free memory
        cout << "Destructor: Memory freed" << endl;
    }
};

int main() {
    Test t1(5); // Constructor called
    t1.show();
    return 0;   // Destructor called automatically
}
```

**Output:**

```
Constructor: Memory allocated for array of size 5
Array at memory location: 0x5622f1...
Destructor: Memory freed
```

**Important Points:**

* Name of destructor = `~ClassName`.
* No parameters, no return type.
* Automatically called **when object goes out of scope**.
* Must use `delete[]` for arrays allocated with `new[]`.

---

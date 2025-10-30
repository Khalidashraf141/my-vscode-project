## 🧩 Debugging Example: Diamond Inheritance Error in C++

### 🧠 Problem Statement

When multiple classes inherit from the same base class and a derived class inherits from them both, a **diamond inheritance** pattern is formed. This often causes **ambiguity errors** because multiple copies of the base class exist.

---

### ❌ Original (Incorrect) Code

```cpp
#include <iostream>
using namespace std;

class p {
public:
    int i;
};

class q : virtual public p {
public:
    int j;
};

class r : virtual public q {
public:
    int k;
};

class s : public p, public q, public r {
public:
    int mul;
};

int main() {
    s obj1;
    obj1.i = 1;
    obj1.j = 20;
    obj1.k = 30;
    obj1.mul = obj1.i * obj1.j * obj1.k;
    cout << "Mul is : " << obj1.mul << "\n";
    return 0;
}
```

### 🐞 Error Explanation

This code fails because:

* Class `q` virtually inherits `p`, and class `r` virtually inherits `q`.
* Class `s` inherits from `p`, `q`, and `r`, creating **multiple paths** to `p`.
* The compiler doesn’t know which copy of `p` (and hence `i`) to use.

📛 Error: *'p' is an ambiguous base of 's'*.

---

### ✅ Corrected Code (Fixed Diamond Inheritance)

```cpp
#include <iostream>
using namespace std;

class p {
public:
    int i;
};

class q : virtual public p {   // Virtual inheritance of p
public:
    int j;
};

class r : virtual public p {   // Also virtual inheritance of p
public:
    int k;
};

class s : public q, public r { // s inherits q and r, not p directly
public:
    int mul;
};

int main() {
    s obj1;
    obj1.i = 1;
    obj1.j = 20;
    obj1.k = 30;
    obj1.mul = obj1.i * obj1.j * obj1.k;
    cout << "Mul is : " << obj1.mul << "\n";
    return 0;
}
```

### ✅ Output

```
Mul is : 600
```

---

### 🧩 Concept: The Diamond Problem

Without virtual inheritance, the structure looks like this:

```
      p
     / \
    q   r
     \ /
      s
```

Each branch brings its own copy of `p`, leading to *duplicate base objects*.

With virtual inheritance:

```
      p
     / \
  (virtual)
    q   r
     \ /
      s
```

Now there’s only **one shared `p`**, solving the ambiguity.

---

### ⚙️ Key Takeaways

1. Use **virtual inheritance** when multiple classes share a common base.
2. The most-derived class (like `s`) should not directly inherit the top base (`p`).
3. This avoids memory duplication and compiler confusion.

---

**Final Note:**
The Diamond Problem is common in C++ multiple inheritance. Understanding *virtual inheritance* is essential to handle such class relationships safely and efficiently.

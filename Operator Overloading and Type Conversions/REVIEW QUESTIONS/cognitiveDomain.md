# C++ Operator Overloading: Complete Guide

---

## 1. Type Conversion Usability

**Definition:**  
Type conversion in operator overloading enables operators to work with different data types by converting one type to another.

**Benefits:**
- Allows operations between custom objects and built-in types
- Provides automatic type conversion during operations
- Improves code flexibility and intuitiveness

**Example:**
```cpp
#include <iostream>
using namespace std;

class Distance {
    double meters;
public:
    Distance(double m = 0) : meters(m) {}
    Distance operator+(double d) { return Distance(meters + d); }
    void display() { cout << meters << " meters\n"; }
};

int main() {
    Distance d(5.5);
    d = d + 3.2;  // 3.2 (double) works with Distance
    d.display();  // Output: 8.7 meters
}
```
*The constructor acts as an implicit type converter.*

---

## 2. Operator Overloading Expression

**Definition:**  
Operator overloading lets you redefine operators (`+`, `-`, `*`, `/`, `++`, `--`, etc.) for user-defined types.

**Purpose:**
- Makes custom types behave like built-in types
- Enables intuitive syntax for operations
- Supports natural mathematical expressions

**Example:**
```cpp
#include <iostream>
using namespace std;

class Complex {
    double real, imag;
public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}
    Complex operator+(const Complex& c) { return Complex(real + c.real, imag + c.imag); }
    Complex operator++() { real++; imag++; return *this; }
    void display() { cout << real << " + " << imag << "i\n"; }
};

int main() {
    Complex c1(3, 4), c2(1, 2);
    Complex c3 = c1 + c2;
    c3.display();  // 4 + 6i
    ++c3;
    c3.display();  // 5 + 7i
}
```

---

## 3. Necessity to Overload Operators

**When is Operator Overloading Needed?**
- For intuitive syntax (`matrix1 + matrix2` vs. `matrix1.add(matrix2)`)
- Improves code readability
- Essential for mathematical objects (Complex, Vector, Matrix)
- Integrates with STL algorithms/containers
- Enhances maintainability

**Example:**
```cpp
#include <iostream>
using namespace std;

class Vector2D {
    double x, y;
public:
    Vector2D(double x = 0, double y = 0) : x(x), y(y) {}
    Vector2D operator+(const Vector2D& v) { return Vector2D(x + v.x, y + v.y); }
    Vector2D operator*(double scalar) { return Vector2D(x * scalar, y * scalar); }
    void display() { cout << "(" << x << ", " << y << ")\n"; }
};

int main() {
    Vector2D v1(1, 2), v2(3, 4);
    Vector2D v3 = v1 + v2;
    v3.display();  // (4, 6)
    Vector2D v4 = v1 * 2;
    v4.display();  // (2, 4)
}
```

---

## 4. Operators That Cannot Be Overloaded in C++

| Operator | Name                | Reason                        |
|----------|---------------------|-------------------------------|
| `::`     | Scope Resolution    | Fundamental to language       |
| `.`      | Member Access       | Direct member access          |
| `.*`     | Pointer to Member   | Member pointer operations     |
| `?:`     | Ternary Conditional | Control flow                  |
| `sizeof` | Size Of             | Compile-time operator         |

*These are intrinsic to C++ and cannot be overloaded.*

---

## 5. Operator Function Syntax

**Member Function Syntax:**
```cpp
return_type operator@(parameter_list) { /* ... */ }
```
**Friend Function Syntax:**
```cpp
friend return_type operator@(parameter_list) { /* ... */ }
```
Where `@` is the operator symbol.

**Example:**
```cpp
#include <iostream>
using namespace std;

class Number {
    int value;
public:
    Number(int v = 0) : value(v) {}
    Number operator+(const Number& n) { return Number(value + n.value); }
    Number operator-() { return Number(-value); }
    friend Number operator-(const Number& a, const Number& b);
    friend ostream& operator<<(ostream& out, const Number& n);
    void display() { cout << value << endl; }
};

Number operator-(const Number& a, const Number& b) { return Number(a.value - b.value); }
ostream& operator<<(ostream& out, const Number& n) { out << n.value; return out; }

int main() {
    Number n1(10), n2(5);
    Number n3 = n1 + n2;
    n3.display();  // 15
    Number n4 = -n1;
    n4.display();  // -10
    Number n5 = n1 - n2;
    n5.display();  // 5
    cout << "n1 = " << n1 << endl;
}
```
*Member functions use implicit `this`; friend functions use explicit parameters.*

---

## 6. Arguments in Unary Operator Definition

| Type   | Syntax                | Arguments | Implicit Access |
|--------|-----------------------|-----------|-----------------|
| Member | `operator++()`        | 0         | `this` pointer  |
| Friend | `operator++(Type&)`   | 1         | None            |

**Example:**
```cpp
#include <iostream>
using namespace std;

class Counter {
    int count;
public:
    Counter(int c = 0) : count(c) {}
    Counter operator++() { count++; return *this; }
    friend Counter operator--(Counter& c);
    void display() { cout << "Count: " << count << endl; }
};

Counter operator--(Counter& c) { c.count--; return c; }

int main() {
    Counter cnt(5);
    ++cnt;
    cnt.display();  // 6
    --cnt;
    cnt.display();  // 5
}
```

---

## 7. Friend Function Cannot Overload Assignment Operator

**Assignment operator (`=`) must be a member function.**

**Why?**
- Needs access to `this` for self-assignment check
- Only member functions can guarantee correct semantics
- C++ forbids friend assignment operator overloading

**Example:**
```cpp
#include <iostream>
#include <cstring>
using namespace std;

class MyString {
    char* str;
    int len;
public:
    MyString(const char* s = "") {
        len = strlen(s);
        str = new char[len + 1];
        strcpy(str, s);
    }
    MyString(const MyString& other) {
        len = other.len;
        str = new char[len + 1];
        strcpy(str, other.str);
    }
    MyString& operator=(const MyString& other) {
        if(this != &other) {
            delete[] str;
            len = other.len;
            str = new char[len + 1];
            strcpy(str, other.str);
        }
        return *this;
    }
    void display() { cout << "String: " << str << endl; }
    ~MyString() { delete[] str; }
};

int main() {
    MyString s1("Hello"), s2("World");
    s1 = s2;
    s1.display();  // World
    s1 = s1;
    s1.display();  // World
    MyString s3("C++");
    s3 = s2 = s1;
    s3.display();  // World
}
```

---

## 8. When Friend Function Is Compulsory

**Scenarios:**

### 1. Stream Insertion/Extraction (`<<`, `>>`)
*LHS is built-in type (ostream/istream).*
```cpp
#include <iostream>
using namespace std;

class Point {
    int x, y;
public:
    Point(int a = 0, int b = 0) : x(a), y(b) {}
    friend ostream& operator<<(ostream& out, const Point& p);
    friend istream& operator>>(istream& in, Point& p);
};

ostream& operator<<(ostream& out, const Point& p) {
    out << "(" << p.x << ", " << p.y << ")";
    return out;
}
istream& operator>>(istream& in, Point& p) {
    in >> p.x >> p.y;
    return in;
}
```

### 2. Commutative Operators with Type Mismatch
*LHS is a different type than the class.*
```cpp
#include <iostream>
using namespace std;

class Complex {
    double real, imag;
public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}
    Complex operator*(int n) { return Complex(real * n, imag * n); }
    friend Complex operator*(int n, const Complex& c);
};

Complex operator*(int n, const Complex& c) { return Complex(n * c.real, n * c.imag); }
```

### 3. Binary Operators Needing Symmetric Access
*Both operands need equal treatment.*
```cpp
#include <iostream>
using namespace std;

class Fraction {
    int numerator, denominator;
public:
    Fraction(int n = 0, int d = 1) : numerator(n), denominator(d) {}
    friend bool operator==(const Fraction& f1, const Fraction& f2);
    friend bool operator<(const Fraction& f1, const Fraction& f2);
};

bool operator==(const Fraction& f1, const Fraction& f2) {
    return (f1.numerator * f2.denominator == f2.numerator * f1.denominator);
}
bool operator<(const Fraction& f1, const Fraction& f2) {
    return (f1.numerator * f2.denominator < f2.numerator * f1.denominator);
}
```

---

## Summary Table: When to Use What

| Situation                | Use    | Reason                        |
|--------------------------|--------|-------------------------------|
| Assignment `=`           | Member | Needs `this`                  |
| Unary `++`, `--`         | Member | Implicit `this` pointer       |
| Binary arithmetic `+/-`  | Member | Object is natural LHS         |
| Stream `<<`, `>>`        | Friend | LHS is built-in type          |
| Type-mismatched binary   | Friend | LHS can be different type     |
| Comparison `==`, `<`     | Friend | Symmetric access preferred    |

---

## Key Takeaways

1. Type conversion enables seamless operations between types
2. Operator overloading makes custom types behave like built-in types
3. Essential for readable, maintainable code
4. Some operators cannot be overloaded (`::`, `.`, `.*`, `?:`, `sizeof`)
5. Member functions use implicit `this`; friend functions use explicit parameters
6. Unary operator: member = 0 arguments, friend = 1 argument
7. Assignment operator must be member function
8. Friend functions are compulsory for stream operators, type-mismatched operations, and symmetric access

---

**End of Notes**

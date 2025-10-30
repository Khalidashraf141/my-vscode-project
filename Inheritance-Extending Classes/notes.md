# Accessing Private Members in Inheritance

By default, private members of a base class are not inherited directly by the derived class, meaning the derived class cannot access them. However, there are ways to make private data usable indirectly in derived classes.

## 1. Using Protected Instead of Private

If you declare the member as protected, it behaves like private for the outside world, but the derived class can access it.

```cpp
#include <iostream>
using namespace std;

class Base {
protected:
    int data; // can be inherited and accessed by derived class
};

class Derived : public Base {
public:
    void setData(int d) {
        data = d; // allowed because data is protected
    }
    void show() {
        cout << "Data = " << data << "\n";
    }
};

int main() {
    Derived obj;
    obj.setData(10);
    obj.show();
    return 0;
}
```

Here, `data` acts like a private variable for the outside world but is accessible inside derived classes.

## 2. Using Protected Getter and Setter Functions

If the base class must keep its data private, you can provide access functions:

```cpp
class Base {
private:
    int data;
protected:
    void setData(int d) { data = d; } // protected setter
    int getData() { return data; } // protected getter
};

class Derived : public Base {
public:
    void updateData(int d) {
        setData(d);
        cout << "Data = " << getData() << "\n";
    }
};
```

The derived class still cannot access `data` directly but can interact with it safely using these protected functions.
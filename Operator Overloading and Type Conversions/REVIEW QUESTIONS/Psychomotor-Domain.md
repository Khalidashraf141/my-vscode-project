A class `alpha` with a constructor `alpha(int a, double b)` can be used for type conversion in two ways:

1. **Implicit Conversion**:
```cpp
alpha obj = {5, 3.14}; // Implicitly converts (int, double) -> alpha object
```

2. **Explicit Conversion**:
```cpp
int x = 10;
double y = 2.5;
alpha obj(x, y); // Explicitly creates an alpha object
```

This constructor acts as a conversion function, allowing automatic conversion from the parameter types to an `alpha` object.


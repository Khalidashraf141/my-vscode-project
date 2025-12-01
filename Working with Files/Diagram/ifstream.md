# `ifstream` in C++

The `ifstream` class provides input operations for reading data from files. It includes the `open()` function with the default input mode (`ios::in`) and inherits several useful functions from the `istream` class.

---

## Purpose of `ifstream`

The `ifstream` (input file stream) is specifically designed to read data from files. It simplifies file input operations by providing a set of functions to handle text and binary data.

---

## Default Mode

When you create an `ifstream` object and open a file, the file is automatically opened in **input mode** (`ios::in`). This means you can only read from the file, not write to it.

### Example:
```cpp
#include <fstream>
using namespace std;

ifstream fin("data.txt"); // Opens the file in input mode (ios::in)
```

---

## Functions Inherited from `istream`

The `ifstream` class inherits several functions from the `istream` class, which allow you to perform various input operations:

### 1. `get()`
- **Purpose**: Reads a single character from the file.
- **Usage**:
    ```cpp
    char ch;
    fin.get(ch);
    ```

### 2. `getline()`
- **Purpose**: Reads an entire line from the file until a newline character (`\n`).
- **Usage**:
    ```cpp
    string line;
    getline(fin, line);
    ```

### 3. `read()`
- **Purpose**: Reads raw binary data (multiple bytes) from the file.
- **Usage**:
    ```cpp
    char buffer[100];
    fin.read(buffer, sizeof(buffer));
    ```

### 4. `seekg()`
- **Purpose**: Moves the input (get) pointer to a specified position in the file.
- **Usage**:
    ```cpp
    fin.seekg(10, ios::beg); // Moves to the 10th byte from the beginning
    ```

### 5. `tellg()`
- **Purpose**: Returns the current position of the input pointer.
- **Usage**:
    ```cpp
    streampos pos = fin.tellg();
    ```

---

## Key Features of `ifstream`

Using the above functions, `ifstream` allows you to:
- **Read text data**: Process files line by line or character by character.
- **Read binary data**: Handle raw data for advanced file operations.
- **Navigate within a file**: Jump to specific positions for efficient data access.

---

By leveraging the `ifstream` class, you can efficiently handle file input operations in C++.
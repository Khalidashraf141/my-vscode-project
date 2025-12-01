# Understanding `fstream` in C++

The `fstream` class in C++ provides support for simultaneous input and output operations. It inherits all the functions of `istream` and `ostream` through the `iostream` class.

## Purpose of `fstream`

The `fstream` class is used when a program needs to:
- **Read from a file** (like `ifstream`)
- **Write to the same file** (like `ofstream`)

It is the only file stream class that can perform both operations.

## How Does `fstream` Inherit Functions?

The inheritance structure of `fstream` is as follows:

- **`istream`**: Provides all input functions, such as:
    - `get()`
    - `getline()`
    - `read()`
    - `seekg()`
    - `tellg()`

- **`ostream`**: Provides all output functions, such as:
    - `put()`
    - `write()`
    - `seekp()`
    - `tellp()`

- **`iostream`**: Combines `istream` and `ostream`. The `fstream` class inherits from this combined class, which means it automatically gains access to all input and output functions.

## Why Is `fstream` Useful?

The `fstream` class allows you to:
- Open a file
- Read data
- Move the file pointer
- Write new data
- Update existing records
- Rewrite parts of a file

All of these operations can be performed using a single stream, making `fstream` a versatile and efficient choice for file handling in C++.

In summary, `fstream` is the file stream class that supports both reading and writing. It inherits all input functions from `istream` and all output functions from `ostream` via the `iostream` class.
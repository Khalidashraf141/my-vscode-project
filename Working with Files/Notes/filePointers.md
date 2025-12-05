# File Pointers in C++

## Overview
Every file in C++ has two internal pointers created when the file is opened:
1. **Input pointer (get pointer)** - Used for reading data.
2. **Output pointer (put pointer)** - Used for writing data.

---

## Input Pointer (get pointer)
- **Purpose**: Reads data from a file.
- **Behavior**: Moves forward as the program reads characters or lines.
- **Control Functions**:
    - `seekg(position)` - Moves the get pointer to a specific position.
    - `tellg()` - Returns the current position of the get pointer.

### Example:
```cpp
#include <iostream>
#include <fstream>
using namespace std;

int main() {
        ifstream fin("example.txt");
        char ch;

        // Read the first character
        fin.get(ch);
        cout << "Character read: " << ch << endl;

        // Move the get pointer to position 5
        fin.seekg(5);
        fin.get(ch);
        cout << "Character at position 5: " << ch << endl;

        // Get the current position of the get pointer
        cout << "Current position: " << fin.tellg() << endl;

        fin.close();
        return 0;
}
```

---

## Output Pointer (put pointer)
- **Purpose**: Writes data into a file.
- **Behavior**: Moves forward as the program writes data.
- **Control Functions**:
    - `seekp(position)` - Moves the put pointer to a specific position.
    - `tellp()` - Returns the current position of the put pointer.

### Example:
```cpp
#include <iostream>
#include <fstream>
using namespace std;

int main() {
        ofstream fout("example.txt");

        // Write data to the file
        fout << "ABCDEFG";

        // Move the put pointer to position 3
        fout.seekp(3);
        fout << "X";

        // Get the current position of the put pointer
        cout << "Current position: " << fout.tellp() << endl;

        fout.close();
        return 0;
}
```

---

## Purpose of File Pointers
- **Input pointer**: Determines where the next read operation will start.
- **Output pointer**: Determines where the next write operation will happen.
- Enable **random access** to any location inside a file.

---

## Visual Representation

### File on Disk:
| A | B | C | D | E | F | G |
|---|---|---|---|---|---|---|
| ↑                     ↑   |
| Get Pointer           Put Pointer |

- **Get Pointer**: Used for reading.
- **Put Pointer**: Used for writing.

---

## Key Notes
- File pointers move automatically during read/write operations.
- They can be manually moved using `seekg()` and `seekp()` for precise control.

### Example with Both Pointers:
```cpp
#include <iostream>
#include <fstream>
using namespace std;

int main() {
        fstream file("example.txt", ios::in | ios::out);

        // Write data using put pointer
        file.seekp(0);
        file << "HELLO";

        // Read data using get pointer
        file.seekg(0);
        string data;
        file >> data;
        cout << "Data read: " << data << endl;

        file.close();
        return 0;
}
```


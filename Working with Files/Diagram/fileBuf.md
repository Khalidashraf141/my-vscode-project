# 📘 FILEBUF

## 1. Purpose of `filebuf`

`filebuf` is the low-level class that manages the buffer used for file input and output operations. A buffer is a temporary memory area where data is stored while reading from or writing to a file.

### ✔️ Why is a buffer needed?
- It speeds up file operations.
- Reading/writing directly from disk is slow.
- C++ uses a buffer to read/write data in chunks rather than byte-by-byte.

### ✔️ What does `filebuf` do?
- Allocates the buffer.
- Controls the flow of data between **file ↔ buffer ↔ program**.
- Manages the state of the buffer (empty, full, end-of-file, etc.).

---

## 2. `openprot` — What it is

`openprot` is a constant inside `filebuf`. It stands for **open protection mode**.

### ✔️ What does `openprot` do?
`openprot` defines low-level file access permissions such as:
- Whether the file can be read.
- Whether the file can be written.
- Whether the file can be created.
- Whether an existing file can be overwritten.

It is not used directly by programmers. Instead, it is used internally by the `open()` function of:
- `ifstream`
- `ofstream`
- `fstream`

### ✔️ Why is it important?
When you write:
```cpp
ifstream fin("data.txt");
```
You don't see `openprot`, but inside the C++ library, `openprot` helps decide:
- Which system call to use.
- Which file permissions to apply.
- How the file should be opened.

Without `openprot`, the `open()` function wouldn't know how to manage file protection.

### ⭐ Types of File Protection `openprot` Represents
- `0` (default) - Normal access.
- `ios::in` - Open file for reading.
- `ios::out` - Open file for writing.
- `ios::app` - Append (prevent overwrite).
- `ios::binary` - Open in binary mode.
- `ios::trunc` - Truncate (delete existing content).
- `ios::nocreate` - Don't create a new file.
- `ios::noreplace` - Don't overwrite an existing file.

Some of these flags existed in older systems; modern C++ keeps only the useful ones.

#### Example:
Suppose `data.txt` is marked read-only in Windows/Linux:
```cpp
ifstream fin("data.txt", ios::in);
```
✔️ `openprot` tells the OS:
> "Open this file in read mode only."

⚠️ If you try to write:
```cpp
fin << "hello"; // Error
```
The OS will block it because `openprot` locked the file in read mode.

`openprot` is an internal constant in `filebuf` that specifies the protection level of a file when it is opened. It is used internally by the `open()` function of all file stream classes to ensure the file is opened safely with the correct permissions.

---

## 3. `open()` and `close()` Functions Inside `filebuf`

### `open()`
The `open()` function in `filebuf` performs the actual low-level file opening, which includes:
- Connecting the file to a buffer.
- Applying the mode (input, output, binary, append).
- Checking if the file exists or needs to be created.
- Setting the file pointer at the correct starting location.

It is called internally by:
```cpp
fin.open();
fout.open();
file.open();
```

### `close()`
The `close()` function in `filebuf`:
- Flushes the buffer (writes remaining data to disk).
- Releases the system file handle.
- Disconnects the buffer from the file.
- Resets the internal state.

Again, you don't call `filebuf.close()` directly. It is used internally by file stream classes.

All high-level file stream classes (`ifstream`, `ofstream`, `fstream`) use `filebuf` internally.

![alt text](<Details of file stream classes.jpg>)
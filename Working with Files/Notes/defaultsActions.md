### File Opening Modes in C++
•Input Pointer(get pointer) - use for reading the contents of given file
•Output Pointer(put pointer) - use for writing to given file location

#### 1. Reading Mode
When a file is opened in **read-only mode**, the input pointer is automatically set at the beginning of the file, allowing us to read its contents.

```
Open for reading only:
+---+---+---+---+---+---+---+---+---+---+---+
| H | E | L | L | O |   | W | O | R | L | D |
+---+---+---+---+---+---+---+---+---+---+---+
↑ input pointer
```

#### 2. Append Mode
If we want to add more data to an existing file, we open it in **append mode**. This moves the output pointer to the end of the file, after the existing contents.

```
Open in append mode:
+---+---+---+---+---+---+---+---+---+---+---+
| H | E | L | L | O |   | W | O | R | L | D |
+---+---+---+---+---+---+---+---+---+---+---+
                                            ↑ output pointer
```

#### 3. Write-Only Mode
When a file is opened in **write-only mode**, the existing contents are deleted, and the output pointer is set at the beginning of the file. This allows us to write new data from the start.

```
Open for writing only:
+---+---+---+---+---+---+---+---+---+---+---+
|   |   |   |   |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+---+---+---+
↑ output pointer
```

All the actions on the file pointers take place automatically by default. How do we then move a file pointer to any desired position inside the file?
This is possible only if we can take control of the movement of the file pointers ourselves.

    • seekg() Moves get pointer (input) to a specified location (reading)
    • seekp() Moves put pointer (output) to a specified location (writing)
    • tellg() Gives the current position of the get pointer
    • tellp() Gives the current position of the put pointer


1 seekp() does NOT work with ios::app
    • In append mode (ios::app), the put pointer is locked at the end of the file.
    • So you cannot move it using seekp().
    • All writes always go only to the end.

    !Important
        • seekp() is ignored when file is opened using ios::app.

2 seekp() works with ios::ate
    • iso::ate opens the file and places the pointer at the end initially.
      but you are allowed to move it anywhere.
    • So you can modify old data using seekp() or seekg()

    ✔️ Use ios::ate if you want to:
        • read entire file
        • Modify existing content
        • Write anywhere, not just at the end
    
3 ifstream and ofstream have default modes
    • ifstream - default mode = ios::in
    • ofstream - default mode = ios::out (includes iso::trunc)
    • so you do not need to pass mode parameters unless you want to special behavior

    example:
        ifstream fin("data.txt"); // input mode by default
        ofstream fout("data.txt"); // output + truncation by default

4 fstream does NOT have a default mode
    • you must specify the mode when using fstream
        fstream file("data.txt", ios::in | ios::out);
if you do not specify a mode, fstream will not know whether to read or write.

5 ios::out includes ios::trunc by default
• When a file is opened with ios::out, C++ automatically applies ios::trunc.
• ios::trunc clear the file before writing
✔️ This means
    • All old content is deleted
    • File size becomes 0 bytes
    • Writing starts from the beginning of any empty file


How fin.get() Moves the Get Pointer

1. fin.get() reads one character at a time
When you call:
    char c;
    fin.get(c);
it reads one character from the file into c.

2. After reading, the get pointer moves forward
Each call to fin.get() advances the get pointer by one position
Example file:
A B C D E F
0 1 2 3 4 5 (positions)

3. Pointer Movement 
Before reading
A B C D E F
^
get pointer = 0

After 1st fin.get()
Reads: A
A B C D E F
  ^
  get pointer = 1

After 2nd fin.get()
Reads: B
A B C D E F
    ^
    get pointer = 2

After 3nd fin.get()
Reads: C
A B C D E F
      ^
      get pointer = 3


code Example
fstream fin("data.txt",ios::in);
char ch;
fin.get(ch);    //reads first character
fin.get(ch);    // reads second character
fin.get(ch);    //reads third character

cout << fin.tellg(); // shows pointer position


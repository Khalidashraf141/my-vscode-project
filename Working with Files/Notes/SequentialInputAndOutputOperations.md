📌 Notes – Binary vs Character Format, put/get vs write/read

1.put() and get()
✔️ Designed for SINGLE character operations
    • put() → writes one character to the stream
    • get() → reads one character from the stream

✔️ Data handling
    • Works with character only
    • Ideal for reading/writing text files char-by-char.

2. write() and read()
✔️ Designed for BLOCK operations
    • write() → writes a block of bytes (binary data)
    • read()  → reads a block of bytes (binary data)

✔️ Data handling
    • Handles raw binary data, no conversion
    • The data is stored exactly as in memory

![alt text](<Binary and Character formats of an integer value.png>)

Example: integer value = 2594

A. Binary Format
    • An int takes 2 bytes in memory (on older system; modern systems use 4 bytes but concept is same)
    • So the file stores the two bytes exactly
    • Example representation (![alt text](<Binary and Character formats of an integer value.png>))

➡️ Fast, compact, and accurate
➡️ No conversion, stored exactly like RAM
➡️ Used with write() and read()


B. Character Format
    • Characters are stored as ASCII codes.
    • 2594 becomes → '2' '5' '9' '4'
    • Each character take 1 byte, so total = 4 bytes

➡️ Slower, takes more space
➡️ Conversion needed between text ↔ integer
➡️ Used with put() and get()

4. Why Binary Format is Better for Number
✔️ Exact internal representation
    • No loss of information
    • No text conversions
    • Faster read/write
    • Smaller file size

if int x = 2594;
using write()
    file.write((char*)&x, sizeof(x));
Using put() four times
    file.put('2')
    file.put('5')
    file.put('9')
    file.put('4')
stores 4 characters, i.e 4 bytes

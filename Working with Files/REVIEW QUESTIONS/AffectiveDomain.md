11.15 Defend the correctness of the following statements:

(a) A stream may be connected to more than one file at a time.

Defense of correctness:
    Although in basic C++ programming we usually attach one stream to one file, the concept of streams in general I/O theory shows that a single stream object can be reused or redirected to different files at different times.

    This means the stream mechanism itself is flexible - it is not permanently bound to only one file.

    For example:
        • If we use fstream file;
        first we can do:
        file.open("data1.txt", ios::out);

        after closing it, the same stream file can be connected again to another file:
        file.open("data2.txt", ios::out);

    This proves the statement is correct in principle:
    A stream is simply a channel for input/output. it can be reconnected to multiple files
    (not at the same moment, but over time), as long as previous connections are properly closed.

    Affective-domain justification (Valuing - Organizing)
    Accepting this idea helps us appreciate:
        • the flexibility of the I/O system
        • the programmer's responsibility to manage resource (open/close) properly
        • the importance of understanding how streams behave beyond simple examples
    So, defending the statement shows that we value good I/O practices and understand the design philosophy behind file streams.


(b) A file pointer always contains the address of the file.

This statement is incorrect because a file pointer does not store the address of the file on disk.

What does a file pointer actually contain?
A file pointer stores the current position (offset) inside the file from where the next read/write will happen

Example:
    if your file is 200 bytes and you have read 50 bytes,
    the file pointer will contain 50 - the position inside the file.
    Not the physical memory or disk address of the file

Why it does NOT store the address of the file?
    • files are stored on disk, which uses blocks/sectors.
    • The OS manages those physical locations - programmers never access them directly.
    • The C/C++ file pointer only tracks where you are in the file, not where the file is physically stored

Illustrative example:
    ifstream fin("data.txt");
    fin.seekg(10);  move to 10th byte

Now the file pointer = 10(the position)
NOT "address of data.txt" on the disk

(A file pointer does not contain the address of the file)
it contains the current location inside the file where the next read/write will occur.


(c) The statement
    outfile.write((char*)&obj,sizeof(obj));
    writes only data in obj to outfile

Yes this statement is correct and here is why:

write() in binary file handling writes raw bytes form memory to the file.

What exactly happens?
    • (char*)&obj
        Converts the address of the object into a byte pointer (character pointer).
        This tells write() to start copying bytes from this memory location.
    • sizeof(obj)
        Tells how many bytes must be copies (size of the entire object).
    
so the function writes:
    • only the bytes that belong to the object's data members
    • directly from memory
    • without writing anything extra (no formatting, no separators)

example:
    if obj contains:
        int id = 10;
        float salary = 5000.5;
in memory this might occupy 8 bytes (example).
write() will copy those 8 bytes into the file - nothing more



(d) The ios::ate mode allows us to write data anywhere in the file.

iso::ate does NOT allow writing anywhere in the file.

What iso::ate actually does:
    • it opens the file and moves the file pointer to the end immediately.
    • From there, you can move the pointer manually (using seekp()/seekg()) to any position.
    • Only after you reposition the pointer, you can write anywhere.

So the truth is:
    ❌ iso::ate does NOT itself provide random writing.
    ✔️ It only sets the initial pointer at the end
    ✔️ You must use seek functions to write somewhere else.


compare with iso::app
mode            Meaning                 Can move pointer?           Write anywhere?
iso::app        Always append at end    ❌No                        ❌Never
ios::ate        Start at end            ✔️Yes                       ✔️ only after using seekp


Example (correct use of ios::ate)
fstream file("data.txt", ios::in | ios::out | ios::ate);

// Pointer is at end right now
file.seekp(5);  //move pointer to position 5
file << "Hello"; // now writing at position 5

Here you are able to write anywhere,
but only because you used seekp(),
no because of ios::ate alone.

Final:-
iso::ate opens the file and positions the pointer at the end of the file.
it does NOT allows writing anywhere unless the programmer moves the pointer 
manually using seek functions.


(e) We can add data to an existing file by opening in write mode.

Opening a file in write mode (ios::out) does NOT add data.
it erases the existing file content first (truncates it).

so:
    • if the file already exists -> its previous data is deleted
    • Then new data is written from the beginning
This means you CANNOT use write mode to add data to an existing file.

To ADD data to an existing file you must use:
    ios::app -> append mode
Writes only at the end preserves old dat

    ios::in | ios::out -> read/write mode
(But you must use seek() to move pointer manually)

    ios::ate -> open and move pointer to end
(Then you can reposition anywhere)

We cannot add data to an existing file by opening it only in write mode because it deletes the previous contents. To add data, we must use ios::app or combined read/write modes.


(f) The parameter iso::app can be used only with the files capable of output

What iso::app means:
    iso::app = append mode,
    which means all writing will happen only at the end of the file.
Therefore:
    • it is only meaningful for output streams (ofstream, fstream with output).
    • You cannot use ios::app with pure input streams (ifstream), because:
        • Input streams do not write
        • Append mode is for writing only
        • The mode has no purpose with input-only streams

Examples
✔️ Correct use (output-capable)
    ofstream fout("data.txt", ios::app);    //ok

✔️ Correct use(read+write)
    fstream file("data.txt",ios::in | ios::out | ios::app); //ok

❌ Wrong use (input only)
    ifstream fin("data.txt", ios::app);    // ❌ ERROR-ifstream cannot write

Why this is true?
because:
    • iso::app is meant for writing
    • Writing is only allowed in:
        • ofstream
        • fstream opened with iso::out
    • ifstream cannot accept modes meant for output

ios::app specifies append mode, which is used only when the stream can perform output operations. Since input-only streams cannot write, ios::app is valid only for output-capable file streams like ofstream and fstream



(g) The data written to a file with write() function can be read with the get() function

The data written to a file with write() can be read with the get() function.

write() writes binary data - raw bytes
get() reads one character at a time - text mode

These two do not match

Why the statement is WRONG?

1. write() dumps raw memory bytes
example:
    outfile.write((char*)&obj, sizeof(obj));
This writes binary bytes such as:
    7B 00 00 00 9A 99 A5 40 …

2. get() reads only one character (1byte) at a time
example:
    file.get(ch);
This is meant for text files, not binary objects.

3. Binary bytes do NOT represent valid text characters
so reading binary object data using get() will give:
    • garbage characters
    • unreadable output
    • incomplete reconstruction
    • sometimes program errors

what should be used?
to read data written by write() use read()

infile.read((char*)&obj, sizeof(obj));
read() matches write() because:
    •both operator on binary
    •both transfer raw memory
    •both use byte size of object

Rule:
    Binary output -> must be read with binary input

    write() -> read()
    NOT
    write() -> get()


The statement is incorrect because write() stores raw binary bytes, whereas get() reads text characters one by one binary data must be read using the read() function, not with get().


(h) We can use the functions tellp() and tellg() interchangeably for any file.

tellp() and tellg() are NOT interchangeable because they are used for different purposes:

    tellg() -> get pointer (input position)
    used for reading streams (ifstream, fstream in input mode)

    tellp() -> put pointer (output position)
    used for writing streams (ofstream, fstream in output mode)

So:
    • A read-only file (ifstream)
        has no put pointer -> tellp() is invalid
    • A write-only file (ofstream):
        has not get pointer -> tellg() is invalid

    they only both exist in a read/write file (fstream),
    but they still do different jobs, so not interchangeable.


Example to prove they are not interchangeable

❌ Wrong (won't work)
ifstream fin("data.txt");
cout << fin.tellp();    // ERROR - no put pointer in input stream

❌ Wrong (won't work)
ofstream fout("data.txt");
cout << fout.tellg();   // ERROR - no get pointer in output stream

✔️ correct
ifstream fin("data.txt");
cout << fin.tellg();    // OK: reading position

ofstream fout("data.txt");
cout << fout.tellp();   // OK: writing position


tellg() and tellp() cannot be used interchangeably. tellg() returns the current input(get) position and works only with input-capable streams, while tellp() return the current output (put) position and works only with output-capable streams. They server different purposes and cannot replace each other.


(i) Binary files store floating point values more accurately and compactly than teh text files.

Binary files store floating-point values more accurately and compactly than text files.

1. Accuracy (Precision)
Binary storage keeps the exact bit pattern of the float or double.
example:
    A float in memory is stored in IEE-754 format (32 bits).
    When you write it in binary using:
        outfile.write((char*)&x, sizeof(x));
    you store all 32 bits exactly, with no rounding or conversion

Text storage converts the number to characters
example:
    3.1415926
This may store only 6 or 7 digits -> loss of precision.

so:
Format              Stores actual IEEE bits?                Loses precision?
Binary                  ✔️ Yes                                  ❌ NO
Text                    ❌ No                                   ✔️ Yes (conversion)


2. Compactness (file size)
✔️ Binary storage uses exact size of the data type:
    • float -> 4 bytes
    • double -> 8 bytes

Text storage uses more bytes
Example:
     123.456
This uses:
    • 7 characters -> 7bytes
    • maybe newline or space -> 1 more byte
    so text can take 2x to 10x more space than binary


Real Comparison

Binary write:
    float x = 123.456;
    outfile.write((char*)&x, sizeof(x));
file size = 4 bytes

Test write:
    outfile << x;
May Produce:
    123.456
file size = 7 bytes (or more)



Final Summary:
    Binary files store floating-point number in their original memory representation (IEEE-754), preserving full precision and using fixed, smaller size. Text files convert number into character sequences, which consume more space and may lost precision, Therefore, binary files store floating-point more accurately and compactly than text files.

(j) The fin.fail() call returns non-zero when an operation on the file has failed.

fail() is a status-checking function
fail() return true (non-zero) if any input/output operation fails on the stream

Example of failed operations:
    • opening a file that doesn't exist
    • Reading past the end of file
    • Trying to read invalid data (e.g, reading an int when text is present)
    • Trying to write on a read-only stream
    • Permission errors
    • Hardware I/O errors


Example:
    ifstream fin("data.txt")

    if(fin.fail())
    {
        cout << "File open failed";
    }
if the file does not open, fail() returns non-zero (true)

Another example - reading failure:
int x;
fin >> x;   // suppose file contains letters instead of numbers
if(fin.fail()){
    cout << "Read failed!";
}
Herr, fail() becomes true because extraction failed.

fin.fail() returns a non-zero value when a file operation fails. It indicates that the most recent input/output operation was unsuccessful due to format mismatch, open failure, or invalid read/write action.
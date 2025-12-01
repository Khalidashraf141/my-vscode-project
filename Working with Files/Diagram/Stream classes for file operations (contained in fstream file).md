⭐What fstreambase actually does (Core Functions)
    1️⃣ Provides open()
    fstreambase contains the low-level open() function.
    
    When you write:
        file.open("data.txt")
    This Function:
        - Attaches the file to a buffer
        - Selects the open mode (read, write, append, binary)
        - Prepares file for I/O operations
    
    2️⃣ Provides close()
    fstreambase also contains the close() function.
    This:
        - Closes the file
        - Flushes the buffer
        - Frees resources
    
    3️⃣ Manages File Buffer
    It works together with filebuf to handle file buffering
    fstreambase:
        - sets the buffer
        - manages read/write positions
        - handles error flags
    
    4️⃣ Stores the File Opening Mode
    Every file stream has modes like:
        - ios::in
        - ios::out
        - ios::app
        - ios::binary
    fstreambase keeps track of these modes.

    5️⃣ Provides Common Operations to All file streams
    so instead of having:
        - open() repeated in ifstream
        - open() repeated in ofstream
        - open() repeated in fstream
    C++ puts in one time in fstreambase.
    All file stream classes reuse it

📌In Simple Words
fstreambase = the engine behind file opening, closing, and basic file control.

It does NOT read or write itself — that's done by:
    - istream (input)
    - ostream (output)
But file streams cannot function without fstreambase.

📘One-line Definition
fstreambase provides the basic file-handling functions such as open() and close(), and serves as the base class for ifstream, ofstream, and fstream.


⭐ifstream → used for input from files
⭐ofstream → used for output to files
⭐fstream  → used for both input and output
These classes are not created directly from scratch.
They inherit (take features from two parent classes)


📌Means each class has Two parents:
• ifstream comes from:
    → istream (because it reads)
    → fstreambase (because it handles files)

• ofstream comes from:
    → ostream (because it writes)
    → fstreambase

• fstream comes from:
    → iostream (because it does both)
    → fstreambase

![alt text](<Stream classes for file operations (contained in fstream file).jpg>)
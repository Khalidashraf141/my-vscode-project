Find errors in the following statements:
    (a) ifstream.infile("DATA")

    Wrong Statement
    ifstream.infile("DATA");
    ❌What's wrong?
    1 ifstream is a class, not an object
    you cannot call .infile() or .open() on the class itself

    you must first create an object of ifstream

    2 .infile is NOT a valid function
    ifstream objects use the function:
    open()


    ✅Correct Statement
    ifstream infile("DATA");

    or
    ifstream infile;
    infile.open("DATA");

both are valid

    (b) fin1.getline(); //fin1 is input stream
    wrong statement
    getline() requires arguments
    The function getline() cannot be called with no parameters.

    The valid forms are
    fin1.getline(buffer,size);

    or
    getline(fin1,str);

    so calling it like this: fin1.getline(); is invalid

    Even though fin1 is an input stream, getline needs a place to store the input
    getline() must know:
        • Where to store the line (buffer or string)
        • How many characters to store (size)
    without these, it has no destination so it is an error

    correct version
    char buffer[80];
    fin1.getline(buffer,80);

    if using string:
    string line;
    getline(fin1,line);


    (c) if(fin1.eof()==0) exit(1)

    1. Missing semicolon
    every statement must end with ;
    exit(1);

    2. Wrong logic (conceptual error)

    eof() becomes 1(true) only when the program tries to read after the file has finished
    Not before.

    ABC

    Action              Success?            eof()
    Read A              yes                 0
    Read B              yes                 0
    Read C              yes                 0
    Try reading again   Fail                1 -eof becomes true here
    So eof() does not become 1 at the last character.
    it becomes 1 only after you try to read more than available.

    if(fin1.eof()==0)
        exit(1);
    when you open the file eof() is always 0.
    So your program exits immediately.
    This is why the statement is wrong

    you should exit when eof() == 1, not when it is 0

    eof means: file khatam hogaya.
    real meaning eof() is file end ke baad read knarne ki koshish ki ab khatam hua.

    correct statement:
        if(fin1.eof())exit(1);
    

    (d) close(f1)
    ❌ this is wrong in C++

    ✔️ Correct way to close a file in C++
    fstream f1;

    Then you close it using:
    f1.close();

    ❌ What is wrong in close(f1)?
    1. C++ does NOT have a function named close(f1)
    close is not a free function.
    it is a member function of the file stream object.
    that means it must be called using the object name, like:

    also semicolon is missing ;



    (e) infile.open(argc)

    ❌ This statement is WRONG in C++
    Reason 1: open() needs a File Name, not argc
    argc is just a number (count of command line arguments).

    example:
    if you run your program like this:
    a.exe file.txt

    then:
        argc = 2
        argc[1] = "file.txt" -> this is the filename
    But you wrote:
        infile.open(argc); //WRONG
    You are trying to open file using an integer, not a filename.

    ✔ Correct usage:
    if opening a normal file:
        infile.open("myfile.txt");
    
    if opening a file from command-line argument:
        infile.open(argv[1]);
    NOT argc


    (f) sfinout.open(file, ios::in | ios::out | ios::ate)

    condition 1 -> file is a char array or string containing filename
    example:
        char file[] = "data.txt";
    or
        string file = "data.txt"

    condition 2 -> sfinout is an object of fstream
    example:
        fstream sfinout;
    if both of these are true - your statement is valid C++ code.

    Note: ios::ate does not erase the file; it just moves the pointer to end.
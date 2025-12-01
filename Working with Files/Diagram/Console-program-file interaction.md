External Memory (Storage)->
    - These are files stored on disk (e.g., .txt, .dat, etc.)
    - You can read data from these files into your program
    - You can write data from the program to these files

Internal Memory (Program + Data)->
    - When you program runs, it stays in RAM
    - Data is processed here
    - This is where C++ code interacts with input/output streams

Console Unit (Screen + Keyboard)
    - cin -> input from keyboard to the program
    - cout -> output from program to the screen

What the diagram is showing
    . Two main interaction:
        1. Console ↔ Program
            - Keyboard → cin → Program
            - Program  → cout → Screen
        2. Program ↔ File
            - File → Read → Program
            - Program → Write → File
            
![alt text](<Console-program-file interaction.png>)
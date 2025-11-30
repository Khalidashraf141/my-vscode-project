/*
Write a program which reads a text from the keyboard and displays the following information on the screen in two columns:
(a) Number of lines
(b) Number of words
(c) Number of characters
Strings should be left-justified and numbers should be right-justified in a suitable field width.
*/
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

int main()
{
    string line;
    int lineCount = 0;
    int wordCount = 0;
    int charCount = 0;

    cout << "Enter text (press Ctrl+Z or Ctrl+D to end input):\n";

    // Read until EOF
    while(getline(cin,line))
    {
        lineCount++;

        // Count characters (including spaces, excluding newline)
        charCount +=line.length();

        // Count words
        bool inWord = false;
        for (char c: line)
        {
            if(!isspace(c) && !inWord)
            {
                inWord = true;
                wordCount++;
            }
            else if(isspace(c))
            {
                inWord = false;
            }
        }
    }
    cout << "\n";

    // Output left-justified label, right-justified number
    cout<< left << setw(20) << "Number of lines"
         << right << setw(10) << lineCount << endl;

    cout<< left << setw(20) << "Number of words"
         << right << setw(10) << wordCount << endl;
        
    cout<< left << setw(20) << "Number of characters"
         << right << setw(10) << charCount << endl;

    return 0;
}
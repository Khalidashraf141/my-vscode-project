/*
write() writes exactly n characters from the character array s to the output stream and returns the stream itself. it is used for raw block and binary output.

put() sirf 1 character likhta hai
write() ek fixed number of character likhta hai (even if the string has no'\0')
it is a low level raw byte output function

*/
#include <iostream>
using namespace std;

int main()
{
    const char* msg = "Hello World";
    cout.write(msg,6); //print first 5 character

    char arr[10] = {'A','B','C','\0','X','Y','Z'};
    cout.write(arr,7).write("Hello",5); //chaining is possible

    //write() does not stop at '\0'


    //if the size is greater than the length of line, then it displays beyond the bounds of line.
    /*
        if n is greater than the actual length of the string, write() will go beyond the valid memory of the string and print extra garbage characters.

        this happens because:
            write() does not stop at the null terminator('\0')
            it treats the pointer s as raw memory
            it simply outputs the next n bytes of from memory
            
    
    */
    return 0;
}
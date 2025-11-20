#include <iostream>
#include <fstream>
int main()
{
    std::ifstream in ("data.txt");
    char ch;

    while (in.get(ch))
    {
        std::cout << ch;
    }
    if(in.eof())
    {
        std::cout<<"\nReached EOF!";
    }
    return 0;
}

/*
in.get(ch) file se characters read karta hai
Jab file end hoti hai, next read fail hoti hai
Tab stream ka eofbit set ho jata hai
in.eof() -> tur ho jata hai
Yani input stream me eof() ka actual istemaal hota hai.


Output stream endpoint par likhta hai.
wo kabhi file ka end encounter nhi karta, kyunki read operation hota hi nhi

eof() tab tur hota hai jab stream ne read operation me end-of-file encounter kiya ho.
Output streams read hi nahi karti, isliye unme EOF kabhi set nhi hota.



ostream read operation ko directly support nahi karta, lekin uska stream buffer theoretically read operations kar sakta hai isi wajah se eofbit ka concept available rehta hai


ostream cannot perform read operation directly, but its internal stream buffer can perform read operations that's why EOF  flag exists in theory, but in practical programming, ostream never hits eof.

final conclusion-
Normally ostream does not read or set eofbit because output streams do not perfrom read operations.
eofbit belongs to teh base class ios, so it exists but in practice ostream never encounters EOF.
*/


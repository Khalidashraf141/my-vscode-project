/*
ostream& flush();
flush() output stream ka buffer turant empty wirte kar deta hai.
yahi jitna data buffer me sotre tha,
wo immdediatley output/file me behj diya jata hai
is process ko hi synchronizing the ouput buffer bolte hai.

why important is flush()?
cout/ofstream output ko phele buffer me store karta hai
phir kabhi kabhi automatically flush ho hai
like newline,program end,bufffer flull etc)
but aagar thum chaho ko abhi ke abhi data ouput ho, to flush use karte ho
*/

#include <iostream>
using namespace std;

int main()
{
    cout << "Processing" << flush;
    return 0;
}

//flush() synchronizes the output buffer by forcing all buffered output to be written immediately to the destination. It clears the buffer without adding any extra character.
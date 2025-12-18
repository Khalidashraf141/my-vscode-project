#include <iostream>
using namespace std;

template<class T, class T2>
T max (T t1, T2 t2)
{
    return t1 > t2 ? t1 : t2;
}
unsigned int m;
int main()
{
   cout << max<unsigned int>(m,100);
    return 0;
}
/*
Comparing signed and unsigned integers in C++ is dangerous and should be avoided because teh singed value is converted to unsigned, which can lead to incorrect results.

When you do:
unsigned int u = 1;
int s = -2;

if(u > s)
C++ converts s to unsigned
-2 -> 4294967294 (on 32-bit)

so the comparison becomes:
1 > 4294967294   // false ❌

logically wrong result

You should avoid comparing signed and unsigned integers unless you explicitly control the conversion
*/
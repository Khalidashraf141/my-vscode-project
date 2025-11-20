/*Ye function output stream me ek single character insert (write) karta hai
*Jo character tum put() ke andar doge
*Woh exactly wahi ek character output stream me likh diya jata hai
put() sirf ek character insert karta hai
*/




#include <iostream>
using namespace std;

int main()
{
    //Single charater output
    cout.put('A');
    cout <<'\n';

    //Multiple characters using chaining
    cout.put('H').put('e').put('l').put('l').put('o');
    cout << "\n";
    const char* msg = "WORLD";

    for(int i = 0; msg[i]!='\0';i++)
    {
        cout.put(msg[i]); //each character print by put()
    }
    return 0;
}

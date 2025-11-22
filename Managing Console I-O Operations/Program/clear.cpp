#include <iostream>
using namespace std;

int main()
{
    int x;
    cout <<"Enter a number: ";
    cin >> x;   // Suppose user enters: ABC

    if(cin.fail()){
        cout << "\nInput failed! failbit set ho gaya.";
    }

    // now clear all error flags
    /*
    POORE stream ke error flags ko REPLACE/RESET kar deta hai
    default parameter goodbit hota hai-> yani 0
    stream healthy ho jati hai

    */
    cin.clear(); // <-- THIS removes failbit / badbit / eofbit
    /*
    failbit = 0;
    badbit = 0;
    eofbit = 0; clear reset these
    */

    if(!cin.fail()){
        cout<<"\nfail clear ho gaya!";
    }


    return 0;
}
/*
User galat input de to stream fail ho jati hai -> failbit set hota hai clear() failbit ko remove karke stream ko wapas good state me la deta hai.

clear() set a new value to the stream's internal error-state flags.
*/



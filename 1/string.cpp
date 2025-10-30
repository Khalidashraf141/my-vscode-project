#include <iostream>
#include <string>
using namespace std;

int main(){
    string greeting = "Hello this is riko an simple BOT";
    cout<< greeting<<endl;

    //Concatenation
    string firstName = "Khalid";
    string lastName = "Ashraf";
    string fullName  = firstName+" "+lastName;
    cout<< fullName<<endl;

    string Newfullname = firstName.append(lastName);
    cout<< Newfullname<<endl;

    cout<< "The length of the greeting string is: "<<greeting.length()<<endl;
    cout<< "The length of the greeting string is: "<<greeting.size()<<endl;

    //Access Strings
    string myString = "Hello";
    cout << myString[0]<<endl;
    cout << myString[myString.length()-1]<<endl;
    myString[0] = 'J';
    cout << myString<<endl;
    cout << myString.at(2); //at function
    string txt = "We are the so-called \"Vikings\" from the north.";
    cout << txt;

    //User Input Strings
    string fullname;
    cout << "Type your full name: ";
    getline(cin,fullname);
    cout << "Your name is: "<<fullName;

    return 0;
}
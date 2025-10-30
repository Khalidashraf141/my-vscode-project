#include <iostream>
#include <cstring>
using namespace std;

class String
{
    char *str; //pointer to hold string
    int length; //length of string
    public:
        // (a) Default constructor - creates uninitialized string
        String()
        {
            length = 0;
            str = new char[length+1];
            str[0] = '\0';
        }

        // (b) Constructor with string constant
        String(const char *s)
        {
            length = strlen(s);
            str = new char[length+1];
            strcpy(str,s); //input this is given via *s copy it into str variable
        }

        // Copy constructor
        String(const String &s)
        {
            length = s.length;
            str = new char[length+1];
            strcpy(str,s.str);
        }

        //Destructor
        ~String()
        {
            delete[] str;
        }

        // (c) Add (concatenate) two strings
        String operator+(const String &s) const
        {
            String temp;
            temp.length = length + s.length;
            delete[] temp.str; //delete old memory
            temp.str = new char[temp.length+1];
            strcpy(temp.str, str);
            strcat(temp.str,s.str);
            return temp;
        }

        // (d) Copy assignmet operator
        String &operator=(const String &s)
        {
            if(this!=&s){
                delete[] str;
                length = s.length;
                str = new char[length+1];
                strcpy(str,s.str);
            }

            return *this;
        }

        // (e) Display function
        void display() const{
            cout << str;
        }
};


int main()
{
    // (a) Create uninitialized string
    String st;
    cout << "Uninitialized string: ";
    st.display();
    cout << "\n";

    // (b) Create string objects with constants
    String sa("Well ");
    String sb("done!");
    cout << "String sa: ";
    sa.display();
    cout << "\nString sb: ";
    sb.display();
    cout << "\n";


    // (c) Concatenate two strings
    String sc = sa + sb;
    cout << "After concatenation(sa + sb): ";
    sc.display();
    cout << "\n";


    // (d) Copy one string to another
    String sd;
    sd = sc; //copy assignment operator
    cout << "Copied string sd (from sc): ";
    sd.display();
    cout << "\n";


    return 0;
}

//TODO:Practice this code

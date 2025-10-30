#include <iostream>
#include <cstring>
using namespace std;

class Mystring
{
    char *p;
    int len;
public:
    Mystring()
    {
        len = 0; 
        p = new char[1];
        p[0]='\0';
    }

    Mystring (const char *s);
    Mystring (const Mystring &s);
    ~Mystring()
    {
        delete[] p; //destructor
    }
    friend Mystring operator+(const Mystring &s, const Mystring &t);
    friend int operator<=(const Mystring &s, const Mystring &t);

    //Assignment operator (deep copy)
    Mystring& operator=(const Mystring &s);

    friend void show(const Mystring s);
};
    Mystring& Mystring::operator = (const Mystring &s)
    {
        if(this!=&s)
        {
            delete[] p;
            len = s.len;
            p = new char[len+1];
            strcpy(p,s.p);
        }
        return *this;
    }
Mystring :: Mystring(const char *s)
{
    len = strlen(s);
    p = new char[len+1];
    strcpy(p,s);
}

Mystring :: Mystring(const Mystring &s)
{
    len = s.len;
    p = new char [len+1];
    strcpy(p,s.p);
}

//overloading + operator
Mystring operator+(const Mystring &s, const Mystring &t)
{
    Mystring temp;
    temp.len = s.len + t.len;
    delete[] temp.p; //used for deleting old memory that is fill with default constructor
    temp.p = new char[temp.len+1];
    strcpy(temp.p,s.p);
    strcat(temp.p,t.p);
    return temp;    
}


//overloading <=operator
int operator <=(const Mystring &s, const Mystring &t)
{
    int m = strlen(s.p);
    int n = strlen(t.p);
    if(m<=n) return 1;
    else return 0;
}

void show(const Mystring s)
{
    cout << s.p;
}

int main()
{
    Mystring s1 = "New ";
    Mystring s2 = "York";
    Mystring s3 = "Delhi";
    Mystring string1, string2, string3;
    string1 = s1;
    string2 = s2;
    string3 = s1 + s3;

    cout << "\nString 1 = ";show(string1);
    cout << "\nString 2 = ";show(string2);
    cout << "\n";
    cout << "\nString 3 = ";show(string3);
    cout << "\n\n";

    if(string1<=string3)
    {
        show(string1);
        cout <<" smaller than ";
        show(string3);
        cout << "\n";
    }else{
        show(string3);
        cout << " smaller than ";
        show (string1);
        cout << "\n";
    }

    return 0;
}
#include <iostream>
using namespace std;

class faculty
{
    // private:
    protected:
    int fid;
    char name[20];
    void getdata()
    {
        cout << "Enter faculty id :- \t";
        cin >> fid;
        cout << "Enter name :- \t";
        cin >> name;
    }
};

// class details : faculty  ❌ Error: No access specifier -> private inheritance by default
class details : public faculty
{
    public:
        int age, exp;
        void getdetails()
        {
            getdata();  // ❌ Not accessible because getdata() is private in base class
            cout << "Enter age :- \t";
            cin >> age;
            cout << "Enter year of exp :- \t";
            cin >> exp;
        }

        void display()
        {
            cout << "\n\n" << "faculty id \t " << fid << endl; // ❌ fid is private in base class
            cout << "Name of faculty \t" << name << endl; // ❌ name is private too
            cout << "Faculty age \t" << age << endl;
            cout << "faculty year of exp \t" << exp<<endl;
        }
};

int main()
{
    details m;
    m.getdetails();
    m.display();
    return 0;
}

/*
----------------------------------------------
🧩 Debugging Question:
Why does this code give an error?


 🧠 Explanation:
 -Because `details` inherits from `faculty` privately by default.
 -So base class members and methods become private.
 -Derived class can't access them.

 ✅ Fix:
 Use public inheritance and change private to protected in base class.

 class details : public faculty
 ------------------------------------------------
*/
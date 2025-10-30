#include <iostream>
using namespace std;

class four_seater
{
    public: void property()
    {
        cout << "It has space for four persons" << endl;
    }
};

class four_wheeler
{
    public: void property()
    {
        cout << "It runs on four tyres" << endl;
    }
};

class Car : public four_seater, public four_wheeler
{

};

int main()
{
    Car C1;
    // C1.four_seater;  ❌ Error: invalid use of 'four_seater'
    // C1.four_wheeler; ❌ Error: invalid use of 'four_wheeler'

    // ✅ Correct way to call base class method
    C1.four_seater::property();
    C1.four_wheeler::property();
    return 0;
}

/*
--------------------------------------------------
 🧩 Debugging Question:
 Why does this code produce an error?


 💥Problem:
 -In `main()`, `C1.four_seater;` and `C1.four_wheeler;` are incorrect.
 -You are trying to access the base class name directly.
 -Class names are not callable - only member functions or variables are.

 🧠 Concept:
 -The derived class `Car` inherits form two classes: `four_seater` and `four_wheeler`.
 -Both base classes contain a function named `property()`.
 -To call their functions, you must use the **scope resolution operator (::)** to tell which base class's function to use.

*/
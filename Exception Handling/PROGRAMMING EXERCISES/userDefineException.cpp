#include <iostream>
#include <exception>
using namespace std;

class NegativeNumberException : public exception
{
    public:
        //Override what() function
        const char* what() const noexcept override
        {
            return "Error: Negative number is not allowed!";
        }
};

void checkNumber(int n)
{
    if(n < 0)
    {
        throw NegativeNumberException();    //throw custom exception
    }
    cout << "Valid number: " << n << endl;
}

int main()
{
    int num;
    cout << "Enter a number: ";
    cin >> num;
    try{
        checkNumber(num);
    }
    catch(const NegativeNumberException &e)
    {
        cout << e.what() << endl;
    }
    catch(...)
    {
        cout << "Unknown exception caught" << endl;
    }

    cout << "Program continues normally." << endl;
    return 0;
}

//A user-defined exception is created by inheriting from std::exception and overriding the what() function to provide a meaningful error message.
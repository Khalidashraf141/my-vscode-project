#include <iostream>
using namespace std;
class temp
{
    double inputFahrenheit;
    double celsius;

public:
    void getdata(void);
    void displaydata(void);
};
void temp ::getdata(void)
{
    cout << "Enter the Fahrenheit value: ";
    cin >> inputFahrenheit;
}
void temp ::displaydata(void)
{
    celsius = (inputFahrenheit - 32) * 5 / 9;
    cout << "The Fahrenheit value in Celsius is: " << celsius;
}
int main()
{
    /*2.1 Write a program to display the follwing ouput using a single cout statement
        Maths = 90
        Physics = 77
        Chemistry = 69
    */
    int Maths = 90;
    int Physics = 77;
    int Chemistry = 69;
    cout << Maths << " " << Physics << " " << Chemistry << "\n";

    // //2.2 Write a program to read two numbers from the keyboard and display the larger value on the screen.
    int num_1, num_2;
    cout << "Enter your first number: ";
    cin >> num_1;
    cout << "Enter your second number: ";
    cin >> num_2;
    if (num_1 > num_2)
        cout << "Number first is larger value: " << num_1 << "\n";
    else if (num_2 > num_1)
        cout << "Number second is larger value: " << num_2 << "\n";
    else
        cout << "Both are equal " << num_1 << " " << num_2 << "\n";

    // //2.3 Wrie a program that inputs a character from keybaord and disply its corresponding ASCII value on the screen.
    char inputChar;
    cout << "Enter a character: ";
    cin >> inputChar;
    int converterAscii = inputChar;
    cout << "The ASCII value of given character is: " << converterAscii << "\n";

    // /*
    //2.4 Write a program to read the values of a, b and c and display the value of x, where
    //                                     x = a/b-c
    //             Test your program for the following values:
    //             (a) a = 250, b = 85, c = 25
    //             (b) a = 300, b = 70, c = 70
    // */

    int a, b, c;
    cout << "Enter value for a: ";
    cin >> a;
    cout << "Enter value for b: ";
    cin >> b;
    cout << "Enter value for c: ";
    cin >> c;
    int x = a / b - c;
    cout << "The final value of x is: " << x << "\n";

     //2.5Write a C++ program that will ask for a temperature in Fahrenheit and display it in Celsius.
    //     Formula is = (32°F − 32) × 5/9 = 0°C

    double inputeFahrenheit;
    cout << "Enter your temperature in Fahrenheit: ";
    cin >> inputeFahrenheit;
    double celsius = (inputeFahrenheit - 32) * 5 / 9;
    cout << "Temperature of Fahrenheit in Celsius is: " << celsius;
    ;

    // 2.6 Redo Exercise 2.5 using a class called temp and member functions.

    temp t;
    t.getdata();
    t.displaydata();
    return 0;
}

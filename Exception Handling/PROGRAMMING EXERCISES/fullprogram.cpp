#include <iostream>
using namespace std;

void readNumbers(double &x, double &y)
{
    cout <<"Enter two double numbers: ";
    cin >> x >> y;

    if(cin.fail())      //wrong type of data entered
        throw 'i';
}

double divide(double x, double y)
{
    if(y == 0.0)
        throw y;
    return x/y;
}

int main()
{
    double a, b, result;

    try{
        readNumbers(a,b);
        try{
            result = divide(a,b);
            cout << "Result = " << result << endl;
        }
        catch(double){
            cout << "Exception caught: Division by 0" << endl;
        }
    }
    catch(char)
    {
        cout << "Exception caught: Invalid input type" << endl;
    }
    cout << "End of program" << endl;
    return 0;
}
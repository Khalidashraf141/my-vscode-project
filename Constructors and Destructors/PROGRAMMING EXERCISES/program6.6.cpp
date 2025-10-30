//Write a program to find a prime number using constructor
#include <iostream>
#include <cmath>
using namespace std;

class PrimeChecker
{
    int num;
    public:
        //Constructor
        PrimeChecker(int n)
        {
            num = n;
            bool isPrime = true;

            if(num <= 1)
            {
                isPrime = false;
            }
            else
            {
                for(int i = 2; i <= sqrt(num); i++)
                {
                    if(num % i == 0)
                    {
                        isPrime = false;
                        break;
                    }
                }
            }
            if(isPrime)
            {
                cout << num << " is a Prime number." << "\n";
            }
            else
            {
                cout << num << " is NOT a Prime number." << "\n";
            }
        }
};

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    PrimeChecker obj(n);

    return 0;

}
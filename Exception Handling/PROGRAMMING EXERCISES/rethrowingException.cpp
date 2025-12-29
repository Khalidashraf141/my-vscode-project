/*Write a program to demonstrate the concept of rethrowing an exception*/
#include <iostream>
using namespace std;

void withdraw(int balance, int amount)
{
    try
    {
        if(amount > balance)
            throw balance;
    }
    catch(int bal)
    {
        cout << "ATM Error: Insufficient balance (" << bal <<")\n";
        throw;  //rethrow exception
    }
}

int main()
{
    int balance = 5000;
    int amount = 7000;
    try{
        withdraw(balance,amount);
    }
    catch(int)
    {
        cout << "Bank Server: Transaction declined\n";
    }
    cout << "End of program\n";
    return 0;
}
//Bank Account
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class BankAccount
{
    string name;
    int accountNumber;
    string accountType;
    double balance;

    public:
        //function to assign initial values
        void assignValues(string depositorName, int accNO, string accType, double initialBalance)
        {
            name = depositorName;
            accountNumber = accNO;
            accountType = accType;
            balance = initialBalance;
        }

        //Function to deposit money
        void deposit(double amount)
        {
            balance += amount;
            cout << "Amount deposited: " << amount << "\n";
        }

        //Function to withdraw money (with balance check)
        void withdraw(double amount)
        {
            if(amount <= balance)
            {
                balance -= amount;
                cout << "Amount withdrawn: " << amount << "\n";
            }else{
                cout << "Insufficient balance!" << "\n";
            }
        }

        //Function to display name and balance
        void display()
        {
            cout << "Depositor Name: " << name << "\n";
            cout << "Account Number: " << accountNumber << "\n";
            cout << "Account Type: " << accountType << "\n";
            cout << fixed << setprecision(2);
            cout << "Balance: " << balance << "\n";
        }
};

int main()
{
    // BankAccount account_1;

    // account_1.assignValues("Khalid Ashraf", 785493932, "Savings", 124384039);

    // account_1.withdraw(5000);
    // account_1.deposit(77000);
    // account_1.display();

    //For 10 customers
    BankAccount account[10];
    account[0].assignValues("Khalid Ashraf",1242323,"Saving",4322);
    account[1].assignValues("Khalid Ashraf",1242323,"Saving",4322);
    account[2].assignValues("Khalid Ashraf",1242323,"Saving",4322);
    account[3].assignValues("Khalid Ashraf",1242323,"Saving",4322);
    account[4].assignValues("Khalid Ashraf",1242323,"Saving",4322);
    account[5].assignValues("Khalid Ashraf",1242323,"Saving",4322);
    account[6].assignValues("Khalid Ashraf",1242323,"Saving",4322);

    for(int i = 0; i<7; i++)
    {
        account[i].display();
    }

    return 0;
}
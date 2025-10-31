/*
8.1 Question-> Assume that a bank maintains two kinds of accounts for customers, one called as savings account and the other as current account. The savings account provides compound interest and withdrawal facilities but no cheque book facility. The current account provides cheque book facility but no interest. Current account holders should also maintain a minimum balance and if the balance falls below this level, a service charge is imposed.

Create a class account that stores customer name, account number and type of account. From this, derive the class cur_acct and sav_acct to make them more specific to their requirements. Include necessary member functions in order to achieve the following tasks.

(a) Accept deposit from a customer and update the balance
(b) Display the balance
(c) Compute and deposit interest
(d) Permit withdrawal and update the balance
(e) Check for the minimum balance, impose penalty, necessary, and update the balance.
 Do not use any constructor. Use member functions to initialize the classs members.
*/
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

// Base class
class Account
{
protected:
    string customer_name;
    int account_number;
    string account_type;
    double balance;
public:
    void initialize(string name, int acc_no, string type, double bal)
    {
        customer_name = name;
        account_number = acc_no;
        account_type = type;
        balance = bal;
        // if(account_type == "Current")
        if(strcasecmp(account_type.c_str(),"Current")==0)
        {
            cout << "\nCurrent Account Created Cheque book alloted!";
        }
    }

    void display_balance()
    {
        cout << "Current balance: " << balance << endl;
    }

    void deposit(double amount)
    {
        balance += amount;
        cout << "Amount deposited: " << amount << endl;
        display_balance();
    }
    void display(void)
    {   cout <<"\n\n------ Account Details ------\n\n";
        cout << "Account holder Name: "<< customer_name <<endl
             << "Account Number     : "<<account_number <<endl
             << "Account type       : "<<account_type<<endl
             << "Account balance    : "<<balance<<endl;
    }
};

// Derived class for Saving Account
class Sav_Acct : public Account
{
    public:
        void compute_interest(double rate, int time)
        {
            double interest = balance * pow((1+rate/100),time)-balance;
            balance += interest;
            cout << "Compound interest added: " << interest << endl;
            display_balance();
        }

        void withdraw(double amount)
        {
            if(amount>balance)
            {
                cout <<"Insufficient balance!" << endl;
            }else{
                balance -= amount;
                cout <<"Amount withdraw: " << amount << endl;
                display_balance();
            }
        }
        void cheque()
        {
            cout << "Sorry! we don't provide cheque book for saving account!";
        }
};


//Derived class for Current Account
class Cur_Acct : public Account
{
    const double minimum_balance = 500.0;
    const double penalty =50.0;
    
public:
    void check_minimum_balance()
    {
        if(balance<minimum_balance)
        {
            cout << "Balance below minimum! Penalty of " << penalty <<" imposed. " << endl;
            balance-=penalty;
        }
    }
    void withdraw(double amount)
    {
        if(amount>balance)
        {
            cout << "Insufficient balance!" << endl;
        }else{
            balance -= amount;
            cout << "Amount withdrawn: " << amount << endl;
            check_minimum_balance();
            display_balance();
        }
    }
};

//Main Function
int main()
{
    Sav_Acct s;
    s.initialize("Khalid", 1000232, "Savings", 2000);
    cout << "\n--- Savings Account ---" << endl;
    s.deposit(1000);
    s.compute_interest(5,2);
    s.withdraw(500);
    s.cheque();
    s.display();


    Cur_Acct c;
    c.initialize("Zero",1232443,"current",100000);
    cout <<"\n--- Current Account ---" << endl;
    c.withdraw(99700);
    c.display();

    return 0;


}

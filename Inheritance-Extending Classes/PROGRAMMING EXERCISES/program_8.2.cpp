/*
 Question 8.2 -> Modify the program of Exercise 8.1 to include constructor for all the three classes.
*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <fstream>
using namespace std;

#define RED "\033[31m"
#define RESET   "\033[0m"
#define CYAN    "\033[36m"

// 🌟 Base Class
class Account
{
    protected:
    string customer_name;
    int account_number;
    string account_type;
    double balance;

public:
    // 🔹 Constructor for base class
    Account(string name, int acc_no, string type, double bal)
    {
        customer_name = name;
        account_number = acc_no;
        account_type = type;
        balance = bal;

        cout << "\nAccount created for " << customer_name
             << " (" << CYAN<< account_type << RESET<<" Account)\n";
        
        if(strcasecmp(account_type.c_str(),"Current")==0)
        {
            cout << "Cheque book facility allotted!\n";
        }
        else
            cout << "No cheque book facility available.\n";
    }

    // 📊 Display balance
    void display_balance(void)
    {
        cout << "Current Balance: " << balance << endl;
    }

    // 💰 Deposit
    void deposit(double amount)
    {
        balance += amount;
        cout << "Deposited: " << amount << endl;
        display_balance();
    }

void generateInvoice(string name, int acc_no, string type, double balance)
{
    // Step 1: Create an HTML file
    ofstream file("invoice.html");
    file << "<html><head><title>Account Invoice</title></head><body>";
    file << "<h1 style='text-align:center;'>Account Invoice</h1>";
    file << "<hr>";
    file << "<h3>Customer Name: " << name << "</h3>";
    file << "<p>Account Number: " << acc_no << "</p>";
    file << "<p>Account Type: " << type << "</p>";
    file << "<p><strong>Current Balance:</strong> ₹" << balance << "</p>";
    file << "<hr><p style='text-align:center;'>Thank you for banking with us!</p>";
    file << "</body></html>";
    file.close();

    // Step 2: Convert HTML → PDF
    system("wkhtmltopdf invoice.html invoice.pdf");

    cout << "✅ Invoice generated successfully: invoice.pdf\n";
}



    // 🗒️ Display details
    void display()
    {
        cout << "\n----- Account Details -----\n";
        cout << "Account Holder : " << customer_name << endl;
        cout << "Account Number : " << account_number << endl;
        cout << "Account Type   : " << account_type << endl;
        cout << "Account Balance: " << balance << endl;
    }
};





// 🏦 Derived Class - Savings Account
class Sav_Acct : public Account
{
    public:
        Sav_Acct(string name, int acc_no, double bal): Account(name,acc_no,"Savings",bal){}

    // 💵 Compute compound interest
    void compute_interest(double rate, int time)
    {
        double interest = balance * (pow((1 + rate / 100),time)-1);
        balance += interest;
        cout <<"Compound interest added: " << interest << endl;
        display_balance();
    }


    // 💸Withdraw
    void withdraw(double amount)
    {
        if(amount>balance)
        {
            cout << "Insufficient balance!\n";
        }else{
            balance -= amount;
            cout <<"Amount withdraw: " << amount << endl;
            display_balance();
        }
    }

    void cheque(){
        cout <<"Sorry! Savings accounts don't have cheque books.\n";
    }
};


// 🗒️Derived Class - Current Account
class Curr_Acct : public Account
{
    const double minimum_balance = 500.0;
    const double penalty = 50.0;


public:
    // Constructor (calls base constructor)
    Curr_Acct(string name, int acc_no, double bal):Account(name,acc_no,"Current",bal){}

    // ⚠️Check minimum balance
    void check_minimum_balance()
    {
        if(balance<minimum_balance)
        {
            cout << "Balance below minimum! Penalty of "<<penalty << "imposed.\n";
            balance-=penalty;
        }
    }

    // 💸 Withdraw
    void withdraw(double amount)
    {
        if(amount > balance)
        {
            cout << "Insufficient balance!\n";
        }else{
            balance -=amount;
            cout <<"Amount withdraw: " << amount << endl;
            check_minimum_balance();
            display_balance();
        }
    }

};


// Main function
int main()
{
    cout << fixed << setprecision(2);

    cout <<"\n--- Savings Account ---";
    Sav_Acct s("Khalid",1000233,2000);
    s.cheque();



    cout << "\n--- Current Account ---";
    Curr_Acct c("Zero", 122323,10000);
    c.display();
    s.generateInvoice("Khalid",324322,"Savings",20000);
    return 0;


}
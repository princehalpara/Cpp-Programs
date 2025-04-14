/* Programmer : Prince Halpara
   Aim : To create a secure OOP-based banking system for managing accounts
   Date : 07 February, 2025
   */


#include <iostream>
#include <string>
using namespace std;

class BankAccount
{
    string accountHolderName;
    long int accountNumber;
    long int balance;

public:

    void getAccountDetails()
    {
        cout << "Enter the name of account holder: ";
        getline(cin, accountHolderName);

        cout << "Enter the account number: ";
        cin >> accountNumber;

        cout << "Enter the current balance of this account: ";
        cin >> balance;
    }

    void deposit(long int amount)
    {
        balance += amount;
        cout << "Amount deposited: " << amount << endl;
    }

    void withdraw(long int amount)
    {
        if (balance >= amount)
        {
            balance -= amount;
            cout << "Amount withdrawn: " << amount << endl;
        }
        else
        {
            cout << "Insufficient balance." << endl;
        }
    }

    void displayBalance() const
    {
        cout << "Your current balance is: " << balance << endl;
    }
};

int main()
{
    BankAccount b1;
    long int amount;

    b1.getAccountDetails();

    // Deposit
    cout << "Enter the amount you want to deposit: ";
    cin >> amount;
    b1.deposit(amount);

    // Withdraw
    cout << "Enter the amount you want to withdraw: ";
    cin >> amount;
    b1.withdraw(amount);

    // Display the final balance
    b1.displayBalance();

    return 0;
}

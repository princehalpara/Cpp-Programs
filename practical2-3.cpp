/* Programmer : Prince Halpara
   Aim : To manage bank accounts
   Date : 14 February, 2025
*/

#include <iostream>
#include <string>

using namespace std;

class BankAccount
{
private:
    string holderName;
    int accountNumber;
    double balance;

public:
    // Default constructor
    BankAccount() : holderName("Holder name"), accountNumber(100), balance(0)
    {
        cout << "Saving default bank account details.." << endl;
    }

    // Parameterized constructor
    BankAccount(string n, int accNum, double bal) : holderName(n), accountNumber(accNum), balance(bal) {}

    // Deposit function
    void depositAmount()
    {
        double depAmt;
        cout << "Enter the amount you want to deposit: ";
        cin >> depAmt;
        if (depAmt > 0)
        {
            balance += depAmt;
            cout << "Your amount deposited successfully !!" << endl;
            cout << "Your updated balance is: " << balance << endl;
        }
        else
        {
            cout << "Invalid deposit amount.." << endl;
        }
    }

    // Withdraw function
    void withdrawAmount()
    {
        double withAmt;
        cout << "Enter the amount you want to withdraw: ";
        cin >> withAmt;

        if (withAmt > 0 && withAmt <= balance)
        {
            balance -= withAmt;
            cout << "Please take your money !!" << endl;
            cout << "Your updated balance is: " << balance << endl;
        }
        else
        {
            cout << "Invalid or insufficient balance for withdrawal.." << endl;
        }
    }

    // Display account details
    void displayDetails()
    {
        cout << "\nBank account details:" << endl;
        cout << "Account holder's name: " << holderName << endl;
        cout << "Bank account number: " << accountNumber << endl;
        cout << "Current balance: " << balance << endl;
    }
};

int main()
{
    BankAccount defaultBankAccount; // Default account
    BankAccount specificBankAccount("Varun Kalotra", 102, 1000); // Specific account

    int choice;
    do
    {
        cout << "\n--- Bank Account Management ---\n";
        cout << "1. Deposit Amount\n";
        cout << "2. Withdraw Amount\n";
        cout << "3. Display Bank Details\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            specificBankAccount.depositAmount();
            break;

        case 2:
            specificBankAccount.withdrawAmount();
            break;

        case 3:
            specificBankAccount.displayDetails();
            defaultBankAccount.displayDetails();
            break;

        case 4:
            cout << "Exiting the program...." << endl;
            break;

        default:
            cout << "Invalid input.. Please try again.." << endl;
            break;
        }
    } while (choice != 4);

    return 0;
}

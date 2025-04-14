/* Programmer : Prince Halpara
   Date : 11 April, 2025
   Aim : To simulate a banking system using OOP, supporting account types, transactions, and history management
*/

#include <iostream>
#include <stack>  // Used to maintain transaction history (for undo feature)
using namespace std;

// Base class representing a generic bank account
class BankAccount
{
protected:
    string accNum;   // Account number
    double balance;  // Current balance

public:
    BankAccount(string num, double bal) : accNum(num), balance(bal) {}

    virtual ~BankAccount() {}  // Virtual destructor for safe polymorphic use

    // Deposit amount into account
    void deposit(double amount)
    {
        balance += amount;
        cout << "Amount deposited: " << amount << endl;
        cout << "Balance: " << balance << endl;
    }

    // Virtual function to withdraw amount (overridden in derived class)
    virtual int withdraw(double amount)
    {
        if (balance >= amount)
        {
            balance -= amount;
            cout << "Amount withdrawn: " << amount << endl;
            cout << "Balance: " << balance << endl;
            return 1;
        }
        else
        {
            cout << "Insufficient balance.." << endl;
            return 0;
        }
    }

    double getBalance() const
    {
        return balance;
    }

    // Show current balance
    void showBalance() const
    {
        cout << "Current Balance: " << balance << endl;
    }

    // Show account details
    void showAccountDetails() const
    {
        cout << "Account Number: " << accNum << endl;
        showBalance();
    }
};

// Derived class representing a savings account
class Savings : public BankAccount
{
public:
    Savings(string num, double bal) : BankAccount(num, bal) {}
};

// Derived class representing a current account with overdraft facility
class Current : public BankAccount
{
    double overDraftLimit;

public:
    Current(string num, double bal, double limit) : BankAccount(num, bal), overDraftLimit(limit) {}

    double getOverDraftLimit() const
    {
        return overDraftLimit;
    }

    // Override withdraw to allow overdraft
    int withdraw(double amount) override
    {
        if (balance + overDraftLimit >= amount)
        {
            balance -= amount;
            cout << "Amount withdrawn: " << amount << endl;
            cout << "Balance: " << balance << endl;
            return 1;
        }
        else
        {
            cout << "Insufficient balance.." << endl;
            return 0;
        }
    }
};

// Class representing a transaction (for undo functionality)
class Transaction
{
public:
    string type;  // "deposit" or "withdraw"
    double amt;
};

// Display menu options to the user
void showMenu()
{
    cout << "\n1. Deposit amount" << endl;
    cout << "2. Withdraw amount" << endl;
    cout << "3. Undo last transaction" << endl;
    cout << "4. Show Account" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter choice: ";
}

int main()
{
    stack<Transaction> History;  // Stack to keep transaction history for undo
    int choice;
    double amt;
    string acc_type;

    cout << "Enter account type (savings/current): ";
    getline(cin, acc_type);  // Read full line to avoid newline issues

    // If user chooses savings account
    if (acc_type == "savings")
    {
        string accNum;
        double bal;

        cout << "Enter the account number: ";
        getline(cin, accNum);
        cout << "Enter the initial balance: ";
        cin >> bal;

        Savings save(accNum, bal);  // Create savings account object

        do
        {
            showMenu();
            cin >> choice;

            switch (choice)
            {
            case 1:
                cout << "Enter amount: ";
                cin >> amt;
                save.deposit(amt);
                History.push({"deposit", amt});  // Record transaction
                break;

            case 2:
                cout << "Enter amount: ";
                cin >> amt;
                if (save.withdraw(amt))
                {
                    History.push({"withdraw", amt});  // Record successful withdrawal
                }
                break;

            case 3:
                if (!History.empty())
                {
                    Transaction last = History.top();
                    History.pop();

                    // Undo last transaction
                    if (last.type == "deposit")
                    {
                        save.withdraw(last.amt);
                        cout << "Undid deposit of " << last.amt << endl;
                    }
                    else if (last.type == "withdraw")
                    {
                        save.deposit(last.amt);
                        cout << "Undid withdrawal of " << last.amt << endl;
                    }
                }
                else
                {
                    cout << "No transaction to undo." << endl;
                }
                break;

            case 4:
                save.showAccountDetails();
                break;

            case 5:
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid Input..." << endl;
                break;
            }
        } while (choice != 5);
    }

    // If user chooses current account
    else if (acc_type == "current")
    {
        string accNum;
        double bal, limit;

        cin.ignore();  // Ignore leftover newline
        cout << "Enter the account number: ";
        getline(cin, accNum);
        cout << "Enter the initial balance: ";
        cin >> bal;
        cout << "Enter the overdraft limit: ";
        cin >> limit;

        Current cur(accNum, bal, limit);  // Create current account object

        do
        {
            showMenu();
            cin >> choice;

            switch (choice)
            {
            case 1:
                cout << "Enter amount: ";
                cin >> amt;
                cur.deposit(amt);
                History.push({"deposit", amt});
                break;

            case 2:
                cout << "Enter amount: ";
                cin >> amt;
                if (cur.withdraw(amt))
                {
                    History.push({"withdraw", amt});
                }
                break;

            case 3:
                if (!History.empty())
                {
                    Transaction last = History.top();
                    History.pop();

                    if (last.type == "deposit")
                    {
                        cur.withdraw(last.amt);
                        cout << "Undid deposit of " << last.amt << endl;
                    }
                    else if (last.type == "withdraw")
                    {
                        cur.deposit(last.amt);
                        cout << "Undid withdrawal of " << last.amt << endl;
                    }
                }
                else
                {
                    cout << "No transaction to undo." << endl;
                }
                break;

            case 4:
                cur.showAccountDetails();
                break;

            case 5:
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid Input..." << endl;
                break;
            }
        } while (choice != 5);
    }

    // If input doesn't match any account type
    else
    {
        cout << "Invalid account type entered." << endl;
    }

    cout << "\nVarun Kalotra : 24CE048" << endl;
    return 0;
}
/* Programmer : Prince Halpara
   Date : 05 May, 2025
   Aim : To create a banking system that manages accounts, handles transactions, and logs errors
*/

#include <iostream>
#include <stdexcept> // For exception handling
using namespace std;

// Declaring BankAccount class
class BankAccount {
public:
    string HolderName;
    double Balance;

    BankAccount(string Name, double Amount) {
        HolderName = Name;
        Balance = Amount;
    }

    // Deposit money function
    void Deposit(double Amount) {
        if (Amount <= 0) {
            throw invalid_argument("Deposit amount must be greater than 0.");
        }
        Balance += Amount;
        cout << "Deposited " << Amount << " successfully." << endl;
    }

    // Withdraw money function
    void Withdraw(double Amount) {
        if (Amount <= 0) {
            throw invalid_argument("Withdrawal amount must be greater than 0.");
        }
        if (Amount > Balance) {
            throw runtime_error("Not enough balance to complete the withdrawal.");
        }
        Balance -= Amount;
        cout << "Withdrew " << Amount << " successfully." << endl;
    }

    // Display current bank balance
    void DisplayBalance() {
        cout << "Current Balance: " << Balance << endl;
    }
};

int main() {
    try {
        BankAccount B1("Vedant", 5000);

        // Trying to deposit money
        B1.Deposit(5000);
        B1.DisplayBalance();

        // Trying to withdraw money
        B1.Withdraw(1000);
        B1.DisplayBalance();


        B1.Withdraw(10000);  //  throw an exception
    }
    catch (invalid_argument& Error) {

        cout << "Error: " << Error.what() << endl;
    }
    catch (runtime_error& Error) {
        // Catch runtime errors (e.g., insufficient funds)
        cout << "Error: " << Error.what() << endl;
    }
    catch (...) {
        // Catch  other unexpected errors
        cout << "An unexpected error occurred." << endl;
    }
    cout<<endl<<"Prince Halpara :: 24CE038"<<endl;

    return 0;
}

/* Programmer : Prince Halpara
   Date : 26 February, 2025
   */
  
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

class Loan {
private:
    string loanID;
    string applicantName;
    double principal;
    double annualRate;
    int tenureMonths;
    double emi;

public:
    // Constructor
    Loan(string id, string name, double amount, double rate, int tenure) {
        loanID = id;
        applicantName = name;
        principal = amount;
        annualRate = rate;
        tenureMonths = tenure;
        emi = calculateEMI();
    }

    // Public EMI Calculation Method
    double calculateEMI() {
        double R = annualRate / (12 * 100); // Monthly interest rate
        int T = tenureMonths;

        double numerator = principal * R * pow(1 + R, T);
        double denominator = pow(1 + R, T) - 1;

        return numerator / denominator;
    }

    // Display Loan Summary
    void displaySummary() {
        cout << fixed << setprecision(2);
        cout << "\n--- Loan Summary ---" << endl;
        cout << "Loan ID: " << loanID << endl;
        cout << "Applicant Name: " << applicantName << endl;
        cout << "Loan Amount: Rs. " << principal << endl;
        cout << "Annual Interest Rate: " << annualRate << "%" << endl;
        cout << "Tenure: " << tenureMonths << " months" << endl;
        cout << "Monthly EMI: Rs. " << emi << endl;
    }
};

int main() {
    // Create a sample loan object with test data
    Loan testLoan("LN001", "Prince Halpara", 500000, 7.5, 60);
    testLoan.displaySummary();

    // Create a loan object with user input
    string id, name;
    double amount, rate;
    int months;

    cout << "\nEnter new loan details:\n";
    cout << "Loan ID: ";
    cin >> id;
    cin.ignore(); // Clear newline character from buffer
    cout << "Applicant Name: ";
    getline(cin, name);
    cout << "Loan Amount: ";
    cin >> amount;
    cout << "Annual Interest Rate (%): ";
    cin >> rate;
    cout << "Tenure (in months): ";
    cin >> months;

    Loan userLoan(id, name, amount, rate, months);
    userLoan.displaySummary();

    // Optional: Access EMI directly via public method
    cout << "\nAccessed directly from public method: EMI = Rs. "
         << fixed << setprecision(2)
         << userLoan.calculateEMI() << endl;

    return 0;
}

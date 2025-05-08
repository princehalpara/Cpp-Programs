/* Programmer : Prince Halpara
   Date : 05 May, 2025
   Aim : To calculate the loan-to-income ratio while handling invalid inputs and division by zero errors
*/

#include <iostream>
#include <stdexcept> // For exception handling

using namespace std;

// Function to get valid input from the user
double GetValidInput(string Prompt)
{
    double Value;
    cout << Prompt;
    cin >> Value;

    // If input is invalid, throw an exception
    if (cin.fail())
    {
        throw invalid_argument("Invalid input. Please enter a valid number.");
    }
    return Value;
}

int main()
{
    try
    {
        double LoanAmount = GetValidInput("Enter the loan amount: ");
        double AnnualIncome = GetValidInput("Enter your annual income: ");

        // Check if the annual income is zero
        if (AnnualIncome == 0)
        {
            throw runtime_error("Annual income cannot be zero.");
        }

        // Calculate and display the loan-to-income ratio
        double LoanToIncomeRatio = LoanAmount / AnnualIncome;
        cout << "Loan-to-income ratio: " << LoanToIncomeRatio << endl;
    }
    catch (exception& Error)
    {
        // Catch and display the error message
        cout << "Error: " << Error.what() << endl;
    }

    cout<<endl;
    cout<<"Prince Halpara :: 24CE038"<<endl;

    return 0;
}

/* Programmer : Prince Halpara
   Aim : To perform addition using function overloading for different input types in a calculator class
   Date : 14 April, 2025
*/

#include<iostream>
#include<vector>

using namespace std;

// Calculator class with overloaded add functions
class Calculator
{
public:
    // Function to add two integers
    int add(int a, int b)
    {
        return a + b;
    }

    // Function to add two doubles
    double add(double a, double b)
    {
        return a + b;
    }

    // Function to add one integer and one double
    double add(int a, double b)
    {
        return a + b;
    }
};

int main()
{
    Calculator calc; // Create an object of Calculator class

    // STL approach using vector to store results
    vector<double> stlResults;
    stlResults.push_back(calc.add(10, 20));     // Integer addition
    stlResults.push_back(calc.add(5.5, 6.5));   // Double addition
    stlResults.push_back(calc.add(10, 3.75));   // Integer and double addition

    // Display results using STL vector
    cout << "Resulting using STL vector: " << endl;
    for (size_t i = 0; i < stlResults.size(); i++)
        cout << "Result " << i + 1 << ": " << stlResults[i] << endl;

    cout << endl;

    // Non-STL approach using a simple array
    const int n = 3;
    double resultArr[n];
    resultArr[0] = calc.add(10, 20);      // Integer addition
    resultArr[1] = calc.add(5.5, 6.5);    // Double addition
    resultArr[2] = calc.add(10, 3.75);    // Integer and double addition

    // Display results using array
    cout << "Resulting using array: " << endl;
    for (int i = 0; i < 3; i++)
        cout << "Result " << i + 1 << ": " << resultArr[i] << endl;

    cout << endl;
    cout << "Prince Halpara : 24CE038" << endl;

    return 0;
}

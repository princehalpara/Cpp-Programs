/* Programmer : Prince Halpara
   Aim : To handle and perform operations on complex numbers using operator overloading
   Date : 14 April, 2025
*/

#include<iostream>
#include<vector>

using namespace std;

class Complex
{
private:
    float real;
    float imag;

public:
    // Overload addition operator
    Complex operator + (Complex c)
    {
        Complex result;
        result.real = real + c.real;
        result.imag = imag + c.imag;
        return result;
    }

    // Overload subtraction operator
    Complex operator - (Complex c)
    {
        Complex result;
        result.real = real - c.real;
        result.imag = imag - c.imag;
        return result;
    }

    // Overload input operator
    friend istream& operator >> (istream& in, Complex& c)
    {
        cout << "Enter real part: ";
        in >> c.real;
        cout << "Enter imaginary part: ";
        in >> c.imag;
        return in;
    }

    // Overload output operator
    friend ostream& operator << (ostream& out, Complex c)
    {
        if(c.imag >= 0)
            out << c.real << " + " << c.imag << "i";
        else
            out << c.real << " - " << -c.imag << "i";
        return out;
    }
};

int main()
{
    Complex c1, c2, sum, diff;

    // Taking input for two complex numbers
    cout << "Enter first complex number:" << endl;
    cin >> c1;

    cout << "\nEnter second complex number:" << endl;
    cin >> c2;

    // Performing arithmetic operations
    sum = c1 + c2;
    diff = c1 - c2;

    // Displaying results
    cout << "\nFirst Complex Number: " << c1 << endl;
    cout << "Second Complex Number: " << c2 << endl;
    cout << "Sum: " << sum << endl;
    cout << "Difference: " << diff << endl;

    // Optional: Handling a collection of complex numbers
    vector<Complex> complexList;
    int n;
    cout << "\nEnter number of complex numbers to store in a list: ";
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        Complex temp;
        cout << "\nEnter complex number " << i + 1 << ":" << endl;
        cin >> temp;
        complexList.push_back(temp);
    }

    cout << "\nList of complex numbers entered:" << endl;
    for(size_t i = 0; i < complexList.size(); i++)
    {
        cout << "Complex[" << i + 1 << "]: " << complexList[i] << endl;
    }

    cout << "\nPrince Halpara: 24CE038" << endl;

    return 0;
}

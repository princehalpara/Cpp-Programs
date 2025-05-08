/* Programmer : Prince Halpara
   Aim : To convert and compare temperatures using operator overloading
   Date : 18 April, 2025
*/

#include <iostream>
#include <queue>
using namespace std;

class Fahrenheit; // Forward declaration

class Celsius
{
    double temp;
public:
    Celsius(double t = 0.0) : temp(t) {}

    void input()
    {
        cout << "Enter Celsius: ";
        cin >> temp;
    }

    void display() const
    {
        cout << temp << " C" << endl;
    }

    operator Fahrenheit();
    bool operator==(const Fahrenheit& f);
    double getTemp() const { return temp; }
};

class Fahrenheit
{
    double temp;
public:
    Fahrenheit(double t = 0.0) : temp(t) {}

    void input()
    {
        cout << "Enter Fahrenheit: ";
        cin >> temp;
    }

    void display() const
    {
        cout << temp << " F" << endl;
    }

    operator Celsius();
    bool operator==(const Celsius& c);
    double getTemp() const { return temp; }
};

// Celsius to Fahrenheit
Celsius::operator Fahrenheit()
{
    return Fahrenheit((temp * 9.0 / 5.0) + 32);
}

// Fahrenheit to Celsius
Fahrenheit::operator Celsius()
{
    return Celsius((temp - 32) * 5.0 / 9.0);
}

// Compare Celsius with Fahrenheit
bool Celsius::operator==(const Fahrenheit& f)
{
    double f_in_celsius = (f.getTemp() - 32) * 5.0 / 9.0;
    return temp == f_in_celsius;
}

// Compare Fahrenheit with Celsius
bool Fahrenheit::operator==(const Celsius& c)
{
    double c_in_fahrenheit = (c.getTemp() * 9.0 / 5.0) + 32;
    return temp == c_in_fahrenheit;
}

int main()
{
    queue<Celsius> cQueue;
    queue<Fahrenheit> fQueue;

    Celsius c1;
    Fahrenheit f1;

    c1.input();
    f1.input();

    cQueue.push(c1);
    fQueue.push(f1);

    Fahrenheit f2 = c1;
    Celsius c2 = f1;

    f2.display();
    c2.display();

    fQueue.push(f2);
    cQueue.push(c2);

    if (c1 == f1)
        cout << "Temperatures are equal.\n";
    else
        cout << "Temperatures are different.\n";

    cout << "\nCelsius Queue:" << endl;
    while (!cQueue.empty())
    {
        cQueue.front().display();
        cQueue.pop();
    }

    cout << "\nFahrenheit Queue:" << endl;
    while (!fQueue.empty())
    {
        fQueue.front().display();
        fQueue.pop();
    }

    cout<<endl;
    cout << "\nPrince Halpara : 24CE038" << endl;

    return 0;
}

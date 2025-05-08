/* Programmer : Prince Halpara
   Date : 28 April, 2025
   Aim : Demonstrate the need for virtual destructor to avoid memory leaks
*/

#include<iostream>
using namespace std;

// Base class
class Base
{
public:
    // base class constructor
    Base()
    {
        cout << "Base class constructor called.." << endl;
    }

    // Virtual base class destructor
    virtual ~Base()
    {
        cout << "Base class virtual destructor called.." << endl;
    }
};

// Derived class
class Derived : public Base
{
    int* data;
public:
    // derived class constructor
    Derived()
    {
        data = new int[5];
        cout << "Derived class constructor called.." << endl;
    }

    // derived class destructor
    ~Derived()
    {
        cout << "Derived class destructor called.." << endl;
    }
};

int main()
{
    // Creating a base class pointer pointing to a derived class object
    Base *base_ptr = new Derived();

    // Deleting using base class pointer
    delete base_ptr;

    cout << endl;
    cout << "\nPrince Halpara: 24CE038" << endl;

    return 0;
}

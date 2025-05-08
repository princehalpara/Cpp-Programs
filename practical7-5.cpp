/* Programmer : Prince Halpara
   Date : 05 May, 2025
   Aim : To display student data from a file using formatted output in C++
*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

// Custom currency manipulator
ostream& currency(ostream& os)
{
    return os << "$";
}

int main()
{
    ifstream infile("students2.txt");

    if (!infile)
    {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    string fname, lname, name;
    double mark, fee;

    // Header
    cout << left << setw(20) << "Name"
         << setw(10) << "Marks"
         << "Tuition Fee" << endl;

    // Using string to print a line
    cout << string(45, '-') << endl;

    // Read and display data
    while (infile >> fname >> lname >> mark >> fee)
    {
        name = fname + " " + lname;

        cout << left << setw(20) << name
             << right << fixed << setprecision(2)
             << setw(10) << mark << "   "
             << currency << fixed << setprecision(2)
             << fee << endl;
    }

    infile.close();

    cout<<"Prince Halpara :: 24CE038"<<endl;
    cout<<endl;
    return 0;
}



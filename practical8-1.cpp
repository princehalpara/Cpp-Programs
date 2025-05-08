/* Programmer : Prince Halpara
   Date : 05 May, 2025
   Aim : To reverse an integer sequence using `std::reverse()` and iterators.

*/

#include <iostream>
#include <vector>
#include <algorithm> // for std::reverse

using namespace std;

int main()
{
    vector<int> Vector1;
    int Element;

    cout << "Enter numbers(# to stop):" << endl;

    while (cin >> Element)
    {
        Vector1.push_back(Element);
    }

    cout << "Original sequence:";
    for (int i = 0; i < Vector1.size(); i++)
    {
        cout << Vector1[i] << " ";
    }
    cout << endl;

    // Reversal using std::reverse
    vector<int> Reversed1 = Vector1;
    reverse(Reversed1.begin(), Reversed1.end());

    cout << endl
         << "Reversed using std::reverse():" << endl;
    for (int i = 0; i < Reversed1.size(); i++)
    {
        cout << Reversed1[i] << " ";
    }
    cout << endl;

    // Reversal manually
    // bija ek vector ma pehla vector ni value revers ma store karavi
    vector<int> Reversed2;
    for (int i = Vector1.size() - 1; i >= 0; i--)
    {
        Reversed2.push_back(Vector1[i]);
    }

    cout << endl
         << "Reversed using manual index-based method:" << endl;
    for (int i = 0; i < Reversed2.size(); i++)
    {
        cout << Reversed2[i] << " ";
    }
    cout << endl;

    cout << endl;
    cout<< "Prince Halpara:: 24CE038" << endl;
    return 0;
}

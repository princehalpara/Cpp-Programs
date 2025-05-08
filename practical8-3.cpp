/* Programmer : Prince Halpara
   Date : 05 May, 2025
   Aim : To filter and display unique transaction IDs using an associative container and iterators
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

int main()
{
    vector<int> Vector1;
    int Element;

    cout << "Enter numbers (# to stop):" << endl;
    while (cin >> Element)
    {
        Vector1.push_back(Element);
    }



    // Sort the vector
    sort(Vector1.begin(), Vector1.end());

    // Use unique to remove duplicates and resize the vector
    auto last = unique(Vector1.begin(), Vector1.end());

    //last number sudhima aavti garbage value erase karse
    Vector1.erase(last, Vector1.end());

    // Display the unique sorted transaction IDs
    cout << "Unique transaction IDs in sorted order: ";
    for (int id : Vector1)
    {
        cout << id << " ";
    }
    cout << endl;
    cout<<endl<<"Prince Halpara :: 24CE038"<<endl;

    return 0;
}

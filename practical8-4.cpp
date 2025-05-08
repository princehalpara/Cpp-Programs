/* Programmer : Prince Halpara
   Date : 05 May, 2025
   Aim : To store, sort, and display student rankings by score using iterators
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

bool CompareByScore(pair<string, int> a, pair<string, int> b)
{
    return a.second > b.second;
}

int main()
{
    vector<pair<string, int>> StudentList;
    string Name;
    int Score;

    cout << "Enter pairs of numbers (# to stop):" << endl;

    // input
    while (cin >> Name >> Score)
    {
        StudentList.push_back({Name, Score});
    }

    // Display
    cout << endl
         << "The entered matrix is:" << endl;
    for (int i = 0; i < StudentList.size(); ++i)
    {
        cout << StudentList[i].first << " " << StudentList[i].second << endl;
    }

    // Sort by score (descending)
    sort(StudentList.begin(), StudentList.end(), CompareByScore);

    // Output
    cout << "\nRanked List of Students (Highest Score First):" << endl;
    cout << "Rank | " << left << setw(12) << "Name" << " | Score" << endl;
    cout << "-------------------------------" << endl;

    for (size_t i = 0; i < StudentList.size(); ++i)
    {
        cout << setw(4) << (i + 1) << " | "
             << left << setw(12) << StudentList[i].first
             << " | " << StudentList[i].second << endl;
    }
    cout<<endl<<"Prince Halpara :: 24CE038"<<endl;
    return 0;
}

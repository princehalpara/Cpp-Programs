/* Programmer : Prince Halpara
   Date : 05 May, 2025
   Aim : To analyze word frequency in a sentence using an associative container and iterators

*/

#include <iostream>
#include <map>
#include <iomanip>

using namespace std;

int main()
{
    string Sentence, Word;
    map<string, int> Freq;

    getline(cin, Sentence);
    stringstream Ss(Sentence);

    while (Ss >> Word)
    {
        Freq[Word]++;
    }

    cout << endl
         << "----------------------------" << endl;
    cout << "| " << setw(12) << left << "Word"
         << " | " << setw(10) << right << "Count |" << endl;
    cout << "----------------------------" << endl;

    for (auto It : Freq)
    {
        cout << "| " << setw(12) << left << It.first
             << " | " << setw(10) << right << It.second << " |" << endl;
    }

    cout << "----------------------------" << endl;
    cout << endl
         << "Prince Halpara :: 24CE038" << endl;

    return 0;
}

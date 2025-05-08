/* Programmer : Prince Halpara
   Date : 05 May, 2025
   Aim : Analyze a text file to count lines, words, and characters using dynamic memory
*/

#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<sstream>

using namespace std;

int main()
{
    ifstream file("data.txt");  // Open the file for reading

    if(!file)  // Check if file opened successfully
    {
        cerr << "Error: Cannot open the file.." << endl;
        return 1;
    }

    string line;
    int lineCount = 0, charCount = 0, wordCount = 0;
    vector<string> lines;

    while (getline(file, line))  // Read each line from the file
    {
        lines.push_back(line);
        lineCount++;
        charCount += line.length();

        stringstream ss(line);  // Break line into words
        string word;
        while (ss >> word)
        {
            wordCount++;
        }
    }

    cout << "Lines     : " << lineCount << endl;
    cout << "Characters: " << charCount << endl;
    cout << "Words     : " << wordCount << endl;

    cout << "\nPrince Halpara :: 24CE038" << endl;
    cout << endl;

    return 0;
}

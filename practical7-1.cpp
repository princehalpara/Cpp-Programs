/* Programmer : Prince Halpara
   Date : 28 April, 2025
   Aim : Analyze word frequency with dynamic memory and manual arrays
*/

#include<iostream>
#include<cstring>    // for strcmp, strcpy, strlwr
#include<cctype>     // for tolower
using namespace std;

const int INITIAL_CAPACITY = 10;

// Function to convert a string to lowercase
void toLowerCase(char* str)
{
    for(int i = 0; str[i]; i++)
        str[i] = tolower(str[i]);
}

int main()
{
    char paragraph[1000];

    cout << "Enter a paragraph:\n";
    cin.getline(paragraph, 1000);  // Read entire line including spaces

    // Word storage using dynamic memory
    int capacity = INITIAL_CAPACITY;
    char** words = new char*[capacity];
    int* freq = new int[capacity];
    int wordCount = 0;

    char* token = strtok(paragraph, " ,.!?;:\n");

    while(token != NULL)
    {
        // Convert word to lowercase
        toLowerCase(token);

        // Check if word exists in array
        bool found = false;
        for(int i = 0; i < wordCount; i++)
        {
            if(strcmp(words[i], token) == 0)
            {
                freq[i]++;
                found = true;
                break;
            }
        }

        // If not found, add new word
        if(!found)
        {
            if(wordCount == capacity)
            {
                // Resize arrays
                int newCapacity = capacity * 2;
                char** newWords = new char*[newCapacity];
                int* newFreq = new int[newCapacity];

                for(int i = 0; i < wordCount; i++)
                {
                    newWords[i] = words[i];
                    newFreq[i] = freq[i];
                }

                delete[] words;
                delete[] freq;

                words = newWords;
                freq = newFreq;
                capacity = newCapacity;
            }

            words[wordCount] = new char[strlen(token) + 1];
            strcpy(words[wordCount], token);
            freq[wordCount] = 1;
            wordCount++;
        }

        token = strtok(NULL, " ,.!?;:\n");
    }

    // Display the results
    cout << "\nWord Frequencies:\n";
    for(int i = 0; i < wordCount; i++)
    {
        cout << words[i] << " : " << freq[i] << endl;
    }

    // Free allocated memory
    for(int i = 0; i < wordCount; i++)
    {
        delete[] words[i];
    }
    delete[] words;
    delete[] freq;

    cout << "\nPrince Halpara:: 24CE038" << endl;
    cout << endl;

    return 0;
}

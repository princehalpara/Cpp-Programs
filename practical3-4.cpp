/* Programmer : Prince Halpara
   Date : 24 February, 2025
   */
#include <iostream>
#include <vector>
using namespace std;

// Template to display elements
template <typename T>
void displayCollection(const vector<T>& collection)
{
    cout << "Collection: ";
    for (const auto& item : collection)
    {
        cout << item << " ";
    }
    cout << endl;
}

// Template to find maximum value
template <typename T>
T findMax(const vector<T>& collection)
{
    T maxVal = collection[0];
    for (const auto& item : collection)
    {
        if (item > maxVal)
            maxVal = item;
    }
    return maxVal;
}

// Template to reverse the collection (manual reverse using temp variable)
template <typename T>
void reverseCollection(vector<T>& collection)
{
    int n = collection.size();
    for (int i = 0; i < n / 2; ++i)
    {
        T temp = collection[i];
        collection[i] = collection[n - i - 1];
        collection[n - i - 1] = temp;
    }
}

int main()
{
    // Integer collection
    vector<int> intCollection = {10, 30, 5, 8, 20};
    displayCollection(intCollection);
    cout << "Max: " << findMax(intCollection) << endl;
    reverseCollection(intCollection);
    displayCollection(intCollection);

    // Float collection
    vector<float> floatCollection = {2.5f, 4.1f, 3.3f, 9.8f};
    displayCollection(floatCollection);
    cout << "Max: " << findMax(floatCollection) << endl;
    reverseCollection(floatCollection);
    displayCollection(floatCollection);

    // Character collection
    vector<char> charCollection = {'a', 'z', 'm', 'e'};
    displayCollection(charCollection);
    cout << "Max: " << findMax(charCollection) << endl;
    reverseCollection(charCollection);
    displayCollection(charCollection);

    return 0;
}


#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;

int recursiveSum(const vector<int>& arr, int index) {
    if (index == arr.size()) return 0;
    return arr[index] + recursiveSum(arr, index + 1);
}

int iterativeSum(const vector<int>& arr) {
    int sum = 0;
    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    auto startRec = high_resolution_clock::now();
    int sumRec = recursiveSum(arr, 0);
    auto endRec = high_resolution_clock::now();
    auto durationRec = duration_cast<nanoseconds>(endRec - startRec);

    auto startItr = high_resolution_clock::now();
    int sumItr = iterativeSum(arr);
    auto endItr = high_resolution_clock::now();
    auto durationItr = duration_cast<nanoseconds>(endItr - startItr);

    cout << "\nRecursive Sum: " << sumRec;
    cout << "\nTime taken by Recursion: " << durationRec.count() << " ns";

    cout << "\n\nIterative Sum: " << sumItr;
    cout << "\nTime taken by Iteration: " << durationItr.count() << " ns\n";

    return 0;
}
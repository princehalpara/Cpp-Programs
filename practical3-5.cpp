/* Programmer : Prince Halpara
   Date : 24 February, 2025
   */
#include <iostream>
#include <string>
using namespace std;

// ---------- Approach 1: Recursive Super Digit ----------
int recursiveSuperDigit(long long n)
{
    if (n < 10)
        return n;

    long long sum = 0;
    while (n > 0)
    {
        sum += n % 10;
        n /= 10;
    }
    return recursiveSuperDigit(sum);
}

int findSuperDigitRecursive(string n, int k)
{
    long long initialSum = 0;
    for (char digit : n)
        initialSum += digit - '0';

    return recursiveSuperDigit(initialSum * k);
}

// ---------- Approach 2: Digital Root (Math Trick) ----------
int digitalRoot(long long n)
{
    if (n == 0) return 0;
    return 1 + (n - 1) % 9;
}

int findSuperDigitMath(string n, int k)
{
    long long sum = 0;
    for (char digit : n)
        sum += digit - '0';

    return digitalRoot(sum * k);
}

// ---------- Main Function ----------
int main()
{
    string n;
    int k;

    cout << "Enter number n: ";
    cin >> n;
    cout << "Enter repetition count k: ";
    cin >> k;

    int result1 = findSuperDigitRecursive(n, k);
    int result2 = findSuperDigitMath(n, k);

    cout << "\n--- Super Digit Results ---" << endl;
    cout << "Recursive Super Digit: " << result1 << endl;
    cout << "Math Trick Super Digit: " << result2 << endl;

    return 0;
}


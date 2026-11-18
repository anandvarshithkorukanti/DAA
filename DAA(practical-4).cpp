
#include <iostream>
#include <chrono>

using namespace std;
using namespace chrono;

// Iterative Factorial: Calculates factorial using a loop
unsigned long long factIter(int x)
{
    unsigned long long ans = 1; // Initialize result

    while (x > 1)
    {
        ans *= x; // Multiply result by current number
        x--; // Decrease number
    }

    return ans; // Return factorial
}

// Recursive Factorial: Calculates factorial by calling itself
unsigned long long factRec(int x)
{
    return (x < 2) ? 1 : x * factRec(x - 1); // Base case and recursive call
}

int main()
{
    int x;

    cout << "Enter a non-negative integer (e.g., 20): ";

    // Check whether input is valid
    if (!(cin >> x) || x < 0)
    {
        cerr << "Invalid input! Please enter a non-negative integer." << endl;
        return 1; // Stop program for invalid input
    }

    // Measure iterative factorial execution time
    auto t1 = high_resolution_clock::now();
    auto iter = factIter(x);
    auto t2 = high_resolution_clock::now();

    // Measure recursive factorial execution time
    auto t3 = high_resolution_clock::now();
    auto rec = factRec(x);
    auto t4 = high_resolution_clock::now();

    // Display factorial results
    cout << "\n--- Results for " << x << "! ---" << endl;
    cout << "Iterative Result : " << iter << endl;

    // Display iterative execution time in nanoseconds
    cout << "Iterative Time   : "
         << duration<double, nano>(t2 - t1).count() << " ns" << endl;

    cout << "-------------------------------" << endl;

    cout << "Recursive Result : " << rec << endl;

    // Display recursive execution time in nanoseconds
    cout << "Recursive Time   : "
         << duration<double, nano>(t4 - t3).count() << " ns" << endl;

    return 0; // End program
}

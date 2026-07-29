#include <iostream>
#include <chrono>

using namespace std;
using namespace chrono;

unsigned long long factIter(int x)
{
    unsigned long long ans = 1;

    while (x > 1)
    {
        ans *= x;
        x--;
    }

    return ans;
}

unsigned long long factRec(int x)
{
    return (x < 2) ? 1 : x * factRec(x - 1);
}

int main()
{
    int x;

    cout << "Enter a non-negative integer (e.g., 20): ";

    if (!(cin >> x) || x < 0)
    {
        cerr << "Invalid input! Please enter a non-negative integer." << endl;
        return 1;
    }

    auto t1 = high_resolution_clock::now();
    auto iter = factIter(x);
    auto t2 = high_resolution_clock::now();

    auto t3 = high_resolution_clock::now();
    auto rec = factRec(x);
    auto t4 = high_resolution_clock::now();

    cout << "\n--- Results for " << x << "! ---" << endl;
    cout << "Iterative Result : " << iter << endl;
    cout << "Iterative Time   : "
         << duration<double, nano>(t2 - t1).count() << " ns" << endl;

    cout << "-------------------------------" << endl;

    cout << "Recursive Result : " << rec << endl;
    cout << "Recursive Time   : "
         << duration<double, nano>(t4 - t3).count() << " ns" << endl;

    return 0;
}
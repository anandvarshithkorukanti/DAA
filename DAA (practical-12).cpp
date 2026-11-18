#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of cities: ";
    cin >> n;

    int cost[10][10];

    // Read cost matrix
    cout << "Enter cost matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> cost[i][j];

    int city[10];

    // Initialize city numbers
    for (int i = 0; i < n; i++)
        city[i] = i + 1;

    int minCost = 999999;

    do
    {
        int total = 0;

        // Calculate cost between consecutive cities
        for (int i = 0; i < n - 1; i++)
            total += cost[city[i] - 1][city[i + 1] - 1];

        // Add cost to return to starting city
        total += cost[city[n - 1] - 1][city[0] - 1];

        // Update minimum travelling cost
        if (total < minCost)
            minCost = total;

    } while (next_permutation(city + 1, city + n)); // Generate next route

    cout << "\nMinimum travelling cost = " << minCost;

    return 0;
}

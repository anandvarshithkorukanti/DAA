
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of cities: ";
    cin >> n;

    int cost[10][10];

    cout << "Enter cost matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> cost[i][j];

    int city[10];
    for (int i = 0; i < n; i++)
        city[i] = i + 1;

    int minCost = 999999;

    do
    {
        int total = 0;

        for (int i = 0; i < n - 1; i++)
            total += cost[city[i] - 1][city[i + 1] - 1];

        total += cost[city[n - 1] - 1][city[0] - 1];

        if (total < minCost)
            minCost = total;

    } while (next_permutation(city + 1, city + n));

    cout << "\nMinimum travelling cost = " << minCost;

    return 0;
}

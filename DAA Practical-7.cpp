
#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
using namespace std;

// Coin Change: Finds minimum number of coins using DP
int coinChange(vector<int> coins, int amount)
{
    // Initialize DP array with maximum possible value
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0; // Zero coins needed for amount 0

    // Calculate minimum coins for each amount
    for (int i = 1; i <= amount; i++)
        for (int coin : coins)
            if (coin <= i)
                dp[i] = min(dp[i], dp[i - coin] + 1); // Update minimum coins

    // Return result or -1 if amount cannot be formed
    return dp[amount] > amount ? -1 : dp[amount];
}

int main()
{
    int n, amount;

    cout << "Enter number of coins: ";
    cin >> n; // Get number of coin types

    vector<int> coins(n);

    cout << "Enter coin values: ";
    for (int &coin : coins)
        cin >> coin; // Read coin denominations

    cout << "Enter amount: ";
    cin >> amount; // Get target amount

    // Start measuring execution time
    auto start = chrono::high_resolution_clock::now();

    // Calculate minimum number of coins
    int result = coinChange(coins, amount);

    // Stop measuring execution time
    auto end = chrono::high_resolution_clock::now();

    // Display minimum coins required
    cout << "\nMinimum coins = " << result << endl;

    // Display execution time in microseconds
    cout << "Execution time = "
         << chrono::duration_cast<chrono::microseconds>
            (end - start).count()
         << " microseconds\n";

    return 0; // End program
}


#include <iostream>
using namespace std;

int main() {
    int n, W;

    cout << "Enter number of items: ";
    cin >> n; // Get total number of items

    int weight[n], value[n]; // Store item weights and values

    cout << "Enter weights: ";
    for (int i = 0; i < n; i++)
        cin >> weight[i]; // Read item weights

    cout << "Enter values: ";
    for (int i = 0; i < n; i++)
        cin >> value[i]; // Read item values

    cout << "Enter capacity: ";
    cin >> W; // Get maximum bag capacity

    int dp[n + 1][W + 1]; // DP table to store maximum profit

    // Knapsack DP: Calculate maximum profit for each capacity
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {

            if (i == 0 || w == 0)
                dp[i][w] = 0; // Base case: No items or capacity

            else if (weight[i - 1] <= w)
                dp[i][w] = max(
                    value[i - 1] + dp[i - 1][w - weight[i - 1]], // Include item
                    dp[i - 1][w] // Exclude item
                );

            else
                dp[i][w] = dp[i - 1][w]; // Item cannot fit
        }
    }

    // Display maximum profit
    cout << "\nMaximum Profit = " << dp[n][W] << endl;

    // Find selected items using DP table
    cout << "Selected Items: ";

    int w = W;

    for (int i = n; i > 0; i--) {
        if (dp[i][w] != dp[i - 1][w]) {
            cout << "Item " << i << " "; // Display selected item
            w = w - weight[i - 1]; // Reduce remaining capacity
        }
    }

    // Display weights of selected items
    cout << "\nSelected Weights: ";

    w = W;

    for (int i = n; i > 0; i--) {
        if (dp[i][w] != dp[i - 1][w]) {
            cout << weight[i - 1] << " "; // Print selected weight
            w = w - weight[i - 1]; // Update remaining capacity
        }
    }

    cout << endl;

    return 0; // End program
}

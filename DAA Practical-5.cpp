#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace chrono;

// Solves the 0/1 Knapsack problem using Dynamic Programming
// Returns the completed dp table so we can later trace back which items were chosen
vector<vector<int>> knapSack(int capacity, vector<int>& weights, vector<int>& values, int n) {
    // dp[i][w] = best value achievable using the first i items with capacity w
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (weights[i - 1] <= w) {
                // Option A: skip this item      -> dp[i-1][w]
                // Option B: take this item      -> value + best value with remaining capacity
                dp[i][w] = max(dp[i - 1][w], values[i - 1] + dp[i - 1][w - weights[i - 1]]);
            } else {
                // Item too heavy to fit, so we must skip it
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp;
}

int main() {
    int n, capacity;

    // Ask user how many items there are
    cout << "Enter number of items: ";
    cin >> n;

    vector<int> values(n), weights(n);

    // Ask user for each item's value and weight
    for (int i = 0; i < n; i++) {
        cout << "Enter value and weight of item " << (i + 1) << ": ";
        cin >> values[i] >> weights[i];
    }

    // Ask user for the knapsack's max capacity
    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    // --- Start timing ---
    auto start = high_resolution_clock::now();

    vector<vector<int>> dp = knapSack(capacity, weights, values, n);
    int maxValue = dp[n][capacity];

    // --- Backtrack through dp table to find which items were actually used ---
    // Idea: if dp[i][w] differs from dp[i-1][w], item (i-1) must have been included.
    vector<int> usedWeights, usedValues;
    int w = capacity;
    for (int i = n; i > 0 && w >= 0; i--) {
        if (dp[i][w] != dp[i - 1][w]) {
            usedWeights.push_back(weights[i - 1]);
            usedValues.push_back(values[i - 1]);
            w -= weights[i - 1]; // remove this item's weight from remaining capacity
        }
    }

    // --- Stop timing ---
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "\nMaximum value in Knapsack = " << maxValue << endl;

    // Show the items that were selected and the total weight they use
    int totalWeight = 0;
    cout << "Items used (value, weight):" << endl;
    for (int i = usedWeights.size() - 1; i >= 0; i--) {
        cout << "  (" << usedValues[i] << ", " << usedWeights[i] << ")" << endl;
        totalWeight += usedWeights[i];
    }
    cout << "Total weight used = " << totalWeight << " / " << capacity << endl;

    cout << "Execution Time = " << duration.count() << " microseconds" << endl;

    return 0;
}
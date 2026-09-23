#include <iostream>
using namespace std;

int main() {
    int n, W;

    cout << "Enter number of items: ";
    cin >> n;

    int weight[n], value[n];

    cout << "Enter weights: ";
    for (int i = 0; i < n; i++)
        cin >> weight[i];

    cout << "Enter values: ";
    for (int i = 0; i < n; i++)
        cin >> value[i];

    cout << "Enter capacity: ";
    cin >> W;

    int dp[n + 1][W + 1];

    // Knapsack DP
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {

            if (i == 0 || w == 0)
                dp[i][w] = 0;

            else if (weight[i - 1] <= w)
                dp[i][w] = max(
                    value[i - 1] + dp[i - 1][w - weight[i - 1]],
                    dp[i - 1][w]
                );

            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    // Maximum profit
    cout << "\nMaximum Profit = " << dp[n][W] << endl;

    // Find selected items
    cout << "Selected Items: ";

    int w = W;

    for (int i = n; i > 0; i--) {
        if (dp[i][w] != dp[i - 1][w]) {
            cout << "Item " << i << " ";
            w = w - weight[i - 1];
        }
    }

    // Display selected weights/denominations
    cout << "\nSelected Weights: ";

    w = W;

    for (int i = n; i > 0; i--) {
        if (dp[i][w] != dp[i - 1][w]) {
            cout << weight[i - 1] << " ";
            w = w - weight[i - 1];
        }
    }

    cout << endl;

    return 0;
}

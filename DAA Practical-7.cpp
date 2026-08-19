#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
using namespace std;

int coinChange(vector<int> coins, int amount)
{
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;

    for (int i = 1; i <= amount; i++)
        for (int coin : coins)
            if (coin <= i)
                dp[i] = min(dp[i], dp[i - coin] + 1);

    return dp[amount] > amount ? -1 : dp[amount];
}

int main()
{
    int n, amount;
    cout << "Enter number of coins: ";
    cin >> n;

    vector<int> coins(n);
    cout << "Enter coin values: ";
    for (int &coin : coins)
        cin >> coin;

    cout << "Enter amount: ";
    cin >> amount;

    auto start = chrono::high_resolution_clock::now();

    int result = coinChange(coins, amount);

    auto end = chrono::high_resolution_clock::now();

    cout << "\nMinimum coins = " << result << endl;
    cout << "Execution time = "
         << chrono::duration_cast<chrono::microseconds>
            (end - start).count()
         << " microseconds\n";

    return 0;
}


#include <iostream>
#include <vector>
#include <climits>
#include <chrono>

using namespace std;
using namespace chrono;

// Function for Matrix Chain Multiplication using DP
int matrixChainMultiplication(vector<int> p, int n)
{
    // Store minimum multiplication cost
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // Check different chain lengths
    for (int length = 2; length < n; length++)
    {
        for (int i = 1; i < n - length + 1; i++)
        {
            int j = i + length - 1; // Calculate ending index

            dp[i][j] = INT_MAX; // Initialize minimum cost

            // Try all possible splitting points
            for (int k = i; k < j; k++)
            {
                // Calculate cost of left, right and final multiplication
                int cost = dp[i][k]
                         + dp[k + 1][j]
                         + p[i - 1] * p[k] * p[j];

                if (cost < dp[i][j])
                {
                    dp[i][j] = cost; // Update minimum cost
                }
            }
        }
    }

    return dp[1][n - 1]; // Return minimum multiplication cost
}

int main()
{
    int matrices;

    cout << "============================================\n";
    cout << "     CHAIN MATRIX MULTIPLICATION\n";
    cout << "       USING DYNAMIC PROGRAMMING\n";
    cout << "============================================\n";

    // Input number of matrices
    cout << "\nEnter number of matrices: ";
    cin >> matrices;

    // Check valid input
    if (matrices <= 0)
    {
        cout << "Number of matrices must be greater than 0.\n";
        return 0; // Stop program
    }

    // Number of dimensions = number of matrices + 1
    vector<int> dimensions(matrices + 1);

    cout << "\nEnter " << matrices + 1 << " dimensions:\n";
    cout << "Example for 3 matrices:\n";
    cout << "A1 = 10 x 20\n";
    cout << "A2 = 20 x 30\n";
    cout << "A3 = 30 x 40\n";
    cout << "Enter: 10 20 30 40\n\n";

    // Read matrix dimensions from user
    for (int i = 0; i <= matrices; i++)
    {
        cin >> dimensions[i];
    }

    // Display matrix dimensions
    cout << "\nMatrices are:\n";

    for (int i = 0; i < matrices; i++)
    {
        cout << "A" << i + 1 << " = "
             << dimensions[i] << " x "
             << dimensions[i + 1] << endl;
    }

    // Start measuring execution time
    auto start = high_resolution_clock::now();

    // Calculate minimum multiplication cost
    int result =
        matrixChainMultiplication(dimensions, matrices + 1);

    // Stop measuring execution time
    auto end = high_resolution_clock::now();

    // Calculate total execution time in microseconds
    auto executionTime =
        duration_cast<microseconds>(end - start);

    // Display final result
    cout << "\n============================================\n";
    cout << "                 RESULT\n";
    cout << "============================================\n";

    cout << "Minimum number of multiplications = "
         << result << endl;

    cout << "Execution Time = "
         << executionTime.count()
         << " microseconds" << endl;

    cout << "============================================\n";

    return 0; // End program
}

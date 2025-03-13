#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to find LCS length
int LCS(string X, string Y) {
    int m = X.length();
    int n = Y.length();

    // Create a 2D array to store lengths of longest common subsequence.
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Build the dp array from bottom-up
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            // If characters match, add 1 to the result of the previous subsequence
            if (X[i - 1] == Y[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                // Otherwise, take the maximum of previous row or previous column value
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // The length of the LCS is in dp[m][n]
    return dp[m][n];
}

int main() {
    string X, Y;
    cout << "Enter first string: ";
    cin >> X;
    cout << "Enter second string: ";
    cin >> Y;

    int length = LCS(X, Y);

    cout << "Length of Longest Common Subsequence: " << length << endl;

    return 0;
}

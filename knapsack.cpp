#include <iostream>
#include <vector>
using namespace std;

// Function to solve the 0/1 Knapsack problem
int knapsack(int W, const vector<int> &wt, const vector<int> &val, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            } else if (wt[i - 1] <= w) {
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    return dp[n][W];
}

int main() {
    int n, W;
    cout << "Enter the number of items: ";
    cin >> n;
    cout << "Enter the capacity of the knapsack: ";
    cin >> W;

    vector<int> val(n), wt(n);
    cout << "Enter the values of the items: ";
    for (int i = 0; i < n; i++) {
        cin >> val[i];
    }
    cout << "Enter the weights of the items: ";
    for (int i = 0; i < n; i++) {
        cin >> wt[i];
    }

    cout << "Maximum value in Knapsack = " << knapsack(W, wt, val, n) << endl;

    return 0;
}
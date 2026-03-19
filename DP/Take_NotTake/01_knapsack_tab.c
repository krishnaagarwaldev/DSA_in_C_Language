#include <stdio.h>

/*
Tabulation Approach:

- Build dp table iteratively
- dp[i][w] represents max value using first i items and capacity w

Steps:
1. Initialize dp table with 0
2. Fill table row by row
3. Use recurrence relation

Time Complexity: O(n * W)
Space Complexity: O(n * W)
*/

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapsack(int wt[], int val[], int n, int W) {
    int dp[100][100];

    // initialize base cases
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
        }
    }

    // fill dp table
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {

            if (wt[i - 1] <= w) {
                dp[i][w] = max(
                    val[i - 1] + dp[i - 1][w - wt[i - 1]], // take
                    dp[i - 1][w]                           // not take
                );
            } else {
                dp[i][w] = dp[i - 1][w]; // cannot take
            }
        }
    }

    return dp[n][W];
}

int main() {
    int wt[] = {1, 2, 4, 5};
    int val[] = {5, 4, 8, 6};
    int n = 4, W = 5;

    printf("Max Value: %d\n", knapsack(wt, val, n, W));

    return 0;
}
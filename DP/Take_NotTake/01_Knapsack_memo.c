#include <stdio.h>
#include <string.h>
#include <limits.h>

int dp[100][100];

/*
PROBLEM STATEMENT:
0/1 Knapsack:
Given n items with weights (wt[]) and values (val[]), and a knapsack of capacity W,
maximize the total value such that total weight ≤ W.
Each item can be taken at most once.

--------------------------------------------------

APPROACH (MATCHING YOUR IMAGE STYLE - i → i+1):

- We use index i (starting from 0)

- At every index i:
    1) Not take → move to next index
    2) Take → if wt[i] <= W, include value and reduce capacity

- Recurrence:
    not_take = solve(i+1, W)
    take = val[i] + solve(i+1, W - wt[i])   (only if wt[i] <= W)

- Final answer:
    max(take, not_take)

- Base case:
    if (i == n) → return 0

--------------------------------------------------
*/

/*
MEMOIZATION (Top-Down DP)

Time Complexity: O(n * W)
Space Complexity: O(n * W) + recursion stack
*/

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapsack(int wt[], int val[], int i, int n, int W) {
    // base case
    if (i == n)
        return 0;

    // already computed
    if (dp[i][W] != -1)
        return dp[i][W];

    // not take
    int not_take = knapsack(wt, val, i + 1, n, W);

    // take
    int take = INT_MIN;
    if (wt[i] <= W) {
        take = val[i] + knapsack(wt, val, i + 1, n, W - wt[i]);
    }

    // store result
    return dp[i][W] = max(take, not_take);
 }

int main() {
    int wt[] = {1, 2, 4, 5};
    int val[] = {5, 4, 8, 6};
    int n = 4, W = 5;

    memset(dp, -1, sizeof(dp));

    printf("Max Value (Memo): %d\n", knapsack(wt, val, 0, n, W));

    for (int i = 0; i < n; i++) {
        for (int w = 0; w <= W; w++) {
            printf("%d   ", dp[i][w]);
        }
        printf("\n");
    }
    return 0;
}
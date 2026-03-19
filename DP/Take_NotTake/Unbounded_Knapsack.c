#include <stdio.h>
#include <string.h>

/*
PROBLEM STATEMENT:
Unbounded Knapsack (Take / Not Take)

Given n items with weights wt[] and values val[], and a knapsack of capacity W.  
You can take each item unlimited times. Find the maximum value achievable.

--------------------------------------------------

APPROACH (INTUITION):

- At each item index i and remaining capacity w:
    1) Take the item → val[i] + solve(i, w - wt[i]) (since unlimited, index stays same)
    2) Not take the item → solve(i + 1, w) (move to next item)
- Base case:
    if i == n or w == 0 → return 0
- Memoize results for dp[i][w] to avoid recomputation
*/

int dp[100][1000];

int max(int a, int b) { return (a > b) ? a : b; }

//Only change is here from 0/1 knapsack, we do not move to next index since we can take unlimited times, also it will not cause infinite recursion as we have again chance to pick/not pick
int unboundedKnapsack(int i, int W, int n, int wt[], int val[]) {
    if (i == n || W == 0) return 0;

    if (dp[i][W] != -1) return dp[i][W];

    int take = 0;
    if (wt[i] <= W){
        take = val[i] + unboundedKnapsack(i, W - wt[i], n, wt, val); //Only change is here, index remains same for take
    }
    int notTake = unboundedKnapsack(i + 1, W, n, wt, val);

    return dp[i][W] = max(take, notTake);
}

int main() {
    // int n, W;
    // scanf("%d %d", &n, &W);
    int n = 4, W = 8; // Example input

    // int wt[100], val[100];
    // for (int i = 0; i < n; i++) scanf("%d", &wt[i]);
    // for (int i = 0; i < n; i++) scanf("%d", &val[i]);

    int wt[100] = {2, 3, 4, 5}; // Example weights
    int val[100] = {3, 4, 5, 6}; // Example values

    memset(dp, -1, sizeof(dp));

    printf("Maximum value in unbounded knapsack: %d\n", unboundedKnapsack(0, W, n, wt, val));

    return 0;
}
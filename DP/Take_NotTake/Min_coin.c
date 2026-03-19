#include <stdio.h>
#include <string.h>

/*
PROBLEM STATEMENT:
Minimum Coins to Make Amount

Given coins[] of size n and a total amount T.  
You can use each coin unlimited times. Find the **minimum number of coins** to make the amount T.

--------------------------------------------------

APPROACH (INTUITION):

- At each coin index i and remaining amount t:
    1) Take the coin → 1 + solve(i, t - coins[i]) (can take unlimited times)
    2) Not take the coin → solve(i + 1, t) (move to next coin)
- Base case:
    if t == 0 → return 0 (no more coins needed)
    if i == n or t < 0 → return a large number (invalid)
- Memoize results in dp[i][t] to avoid recomputation
*/

int dp[100][1000];

int min(int a, int b) { return (a < b) ? a : b; }

int minCoins(int i, int t, int n, int coins[]) {
    if (t == 0) return 0;       // amount formed
    if (i == n || t < 0) return 1000000; // invalid

    if (dp[i][t] != -1) return dp[i][t];

    int notTake = minCoins(i + 1, t, n, coins);         // skip current coin
    if (t - coins[i] < 0) return dp[i][t] = notTake; // if coin value exceeds remaining amount, skip it
     
    int take = 1 + minCoins(i, t - coins[i], n, coins); // take current coin

    return dp[i][t] = min(take, notTake);
}

int main() {
    // int n, T;
    // scanf("%d %d", &n, &T);
    int n = 3, T = 11; // eg. coins = {1, 2, 5} and T = 11

    // int coins[100];
    // for (int i = 0; i < n; i++) scanf("%d", &coins[i]);
    int coins[100] = {1, 2, 5}; // Example coins

    memset(dp, -1, sizeof(dp));

    int ans = minCoins(0, T, n, coins);
    if (ans >= 1000000) printf("Not possible\n");
    else printf("Minimum coins to make %d: %d\n", T, ans);

    return 0;
}
#include <stdio.h>
#include <string.h>

/*
PROBLEM STATEMENT:
Coin Change (Number of Ways)

Given coins[] of size n and a total amount T.  
You can use each coin unlimited times. Find the total number of ways to make the amount T.

--------------------------------------------------

APPROACH (INTUITION):

- At each coin index i and remaining amount t:
    1) Take the coin → solve(i, t - coins[i]) (can take unlimited times)
    2) Not take the coin → solve(i + 1, t) (move to next coin)
- Base case:
    if t == 0 → return 1 (exact amount formed)
    if i == n or t < 0 → return 0 (invalid)
- Memoize results in dp[i][t] to avoid recomputation
*/

int dp[100][1000];

int coinChange(int i, int t, int n, int coins[]) {
    if (t == 0) return 1;
    if (i == n || t < 0) return 0;

    if (dp[i][t] != -1) return dp[i][t];

    int take = coinChange(i, t - coins[i], n, coins);
    int notTake = coinChange(i + 1, t, n, coins);

    return dp[i][t] = take + notTake;
}

int main() {
    int n, T;
    //scanf("%d %d", &n, &T);
    n = 3; T = 4; // eg. coins = {1, 2, 3} and T = 4

    int coins[100];
    // for (int i = 0; i < n; i++){
    //     scanf("%d", &coins[i]);
    // }
    coins[0] = 1; coins[1] = 2; coins[2] = 3;

    memset(dp, -1, sizeof(dp));

    printf("Number of ways to make %d: %d\n", T, coinChange(0, T, n, coins)); // Output: 4 (combinations: {1,1,1,1}, {1,1,2}, {1,3}, {2,2})

    return 0;
}
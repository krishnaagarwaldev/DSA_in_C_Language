#include <stdio.h>
#include <string.h>

/*
PROBLEM STATEMENT:
Ways to Reach Nth Stair

Given n stairs, you can climb 1 or 2 steps at a time.
Find the total number of distinct ways to reach the nth stair.

--------------------------------------------------

APPROACH (INTUITION):

- At each stair i, we have two choices:
    1) Take 1 step → ways(i+1)
    2) Take 2 steps → ways(i+2)
- Total ways = ways(i+1) + ways(i+2)
- Use memoization to store already computed results.
- Base case:
    if i > n → return 0 (cannot go beyond)
    if i == n → return 1 (reached exactly nth stair)
*/

int dp[1000];

int waysToReachStair(int i, int n) {
    if (i > n) return 0;
    if (i == n) return 1;

    if (dp[i] != -1) return dp[i];

    dp[i] = waysToReachStair(i + 1, n) + waysToReachStair(i + 2, n);
    return dp[i];
}

int main() {
    int n;
    scanf("%d", &n);

    memset(dp, -1, sizeof(dp));

    printf("Ways to reach stair %d: %d\n", n, waysToReachStair(0, n));

    return 0;
}
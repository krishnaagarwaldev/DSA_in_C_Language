#include <stdio.h>
#include <string.h>

/*
PROBLEM STATEMENT:
Perfect Squares (LeetCode 279)

Given an integer n, return the minimum number of perfect square numbers
(1, 4, 9, 16, ...) that sum to n.

Example:
n = 12 → 4 + 4 + 4 → answer = 3

--------------------------------------------------

APPROACH (INTUITION):

- At number n, try all perfect squares ≤ n:
    → 1², 2², 3², ..., k²

- For each square:
    take → 1 + solve(n - (i*i))

- Take minimum over all choices

- Base case:
    if n == 0 → return 0

- Use memoization dp[n]
*/

int dp[10000];

int min(int a, int b) {
    return (a < b) ? a : b;
}

int perfectSquares(int n) {
    if (n == 0) return 0;

    if (dp[n] != -1) return dp[n];

    int ans = 1000000;

    for (int i = 1; i * i <= n; i++) {
        int val = 1 + perfectSquares(n - i * i);
        //if (val < ans) ans = val;
        ans = min(ans, val);
    }

    return dp[n] = ans;
}

int main() {
    int n;
    scanf("%d", &n);

    memset(dp, -1, sizeof(dp));

    printf("Minimum perfect squares: %d\n", perfectSquares(n));

    return 0;
}
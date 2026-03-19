#include <stdio.h>

/*
Tabulation Approach:

- Build solution from base cases
- No recursion used

Steps:
1. Define dp array
2. Initialize base cases
3. Fill dp iteratively

Time Complexity: O(n)
Space Complexity: O(n)
*/

int climbStairs(int n) {
    int dp[1000];

    // base cases
    dp[0] = 1;
    dp[1] = 1;

    // build solution
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int main() {
    int n = 5;

    printf("Ways: %d\n", climbStairs(n));

    return 0;
}
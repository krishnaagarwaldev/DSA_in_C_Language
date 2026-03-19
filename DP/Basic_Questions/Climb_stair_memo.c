#include <stdio.h>
#include <string.h>

int dp[1000];

/*
Memoization Approach:

- Use recursion
- Store already computed values in dp[]
- Avoid repeated calculations

Time Complexity: O(n)
Space Complexity: O(n) + recursion stack
*/

int climbStairs(int n) {
    // base cases
    if (n == 0 || n == 1)
        return 1;

    // if already computed
    if (dp[n] != -1)
        return dp[n];

    // store result
    dp[n] = climbStairs(n - 1) + climbStairs(n - 2);

    return dp[n];
}

int main() {
    int n = 5;

    // initialize dp with -1
    memset(dp, -1, sizeof(dp));

    printf("Ways: %d\n", climbStairs(n));

    return 0;
}

/*
PROBLEM STATEMENT:
You are climbing a staircase. It takes n steps to reach the top.
Each time you can either climb 1 step or 2 steps.

Find the number of distinct ways to reach the top.

Example:
n = 3
Ways:
1+1+1
1+2
2+1
Answer = 3

--------------------------------------------------

APPROACH (INTUITION):

- At step n, you can come from:
    1) step (n-1) → take 1 step
    2) step (n-2) → take 2 steps

So,
    ways(n) = ways(n-1) + ways(n-2)

This is exactly Fibonacci pattern.

Base cases:
    ways(0) = 1  (1 way: do nothing)
    ways(1) = 1

--------------------------------------------------
*/



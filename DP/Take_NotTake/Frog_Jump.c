#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int dp[1000];

/*
PROBLEM STATEMENT: 
Frog Jump (Classic DP) (LeetCode 746) :- eg. height = [10, 20, 30, 25, 15]
Now frog is at 10 and wants to reach 15. It can jump from 10 → 20 or 10 → 30.
Cost of jump = abs(height[i] - height[j])
Return the minimum total cost to reach last index.
eg. Here, the minimum cost path is 10 → 30 → 15 with cost = abs(10-30) + abs(30-15) = 20 + 15 = 35

Frog Jump (Classic DP)

A frog is at index 0 and wants to reach index n-1.
Given an array height[], where height[i] is the height of the ith stone.

The frog can jump:
    1) from i → i+1
    2) from i → i+2

Cost of jump from i → j = abs(height[i] - height[j])

Return the minimum total cost to reach last index.

--------------------------------------------------

APPROACH (INTUITION):

- At index i, we can:
    1) Jump to i+1
    2) Jump to i+2

- We choose the minimum cost path

- State:
    dp[i] = minimum cost to reach end from index i

- Recurrence:
    dp[i] = min(
        abs(h[i] - h[i+1]) + dp[i+1],
        abs(h[i] - h[i+2]) + dp[i+2]
    )

- Base case:
    if i == n-1 → return 0

--------------------------------------------------
*/

int min(int a, int b) {
    return (a < b) ? a : b;
}

int frogJump(int i, int height[], int n) {
    // base case
    if (i == n - 1)
        return 0;

    // already computed
    if (dp[i] != -1)
        return dp[i];

    // jump 1 step
    int jump1 = abs(height[i] - height[i + 1]) + frogJump(i + 1, height, n);

    // jump 2 steps (only if possible)
    int jump2 = 1e9;
    if (i + 2 < n) {
        jump2 = abs(height[i] - height[i + 2]) + frogJump(i + 2, height, n);
    }

    return dp[i] = min(jump1, jump2);
}

int main() {
    int height[] = {10, 20, 30, 10};
    int n = 4;
    memset(dp, -1, sizeof(dp));

    printf("Minimum Cost: %d\n", frogJump(0, height, n));

    return 0;
}
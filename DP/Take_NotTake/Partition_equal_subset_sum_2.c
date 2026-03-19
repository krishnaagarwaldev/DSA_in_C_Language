#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int dp[205][20005];

/*
PROBLEM STATEMENT:
LeetCode 416 - Partition Equal Subset Sum

Given an array nums, determine if it can be partitioned into two subsets
such that both subsets have equal sum.

--------------------------------------------------

APPROACH (YOUR STYLE: sum + nums[i]):

- Instead of reducing target, we build sum

- totalSum = sum of all elements
- We try to build subset such that sum = totalSum / 2

- State:
    dp[i][sum] = can we reach sum using elements from index i to n-1

- Choices:
    1) Not take → sum remains same
    2) Take → sum + nums[i]

- Base case:
    if i == n → check if sum == totalSum/2

--------------------------------------------------
*/

// Take or Not Take approach (Top-Down DP) -> sum + nums[i] or sum (not take)
bool solve2(int i, int sum, int totalsum, int nums[], int n) {
    // base cases
    if (i == n){
        return sum == totalsum/2;
    }
    // not take
    bool not_take = solve2(i + 1, sum, totalsum, nums, n);

    // take
    bool take = solve2(i + 1, sum + nums[i], totalsum, nums, n);

    return (take || not_take); 
}

bool solve(int i, int sum, int totalSum, int nums[], int n) {
    // base case
    if (i == n) {
        return (sum == totalSum / 2);
    }

    // already computed
    if (dp[i][sum] != -1)
        return dp[i][sum];

    // not take
    bool not_take = solve(i + 1, sum, totalSum, nums, n);

    // take
    bool take = false;
    if (sum + nums[i] <= totalSum / 2) { // optimization (avoid overflow)
        take = solve(i + 1, sum + nums[i], totalSum, nums, n);
    }

    return dp[i][sum] = (take || not_take);
}

bool canPartition(int nums[], int n) {
    int totalSum = 0;

    for (int i = 0; i < n; i++)
        totalSum += nums[i];

    // if odd → not possible
    if (totalSum % 2 != 0)
        return false;

    memset(dp, -1, sizeof(dp));

    return solve(0, 0, totalSum, nums, n);
}

int main() {
    int nums[] = {1, 5, 11, 5};
    int n = 4;

    if (canPartition(nums, n))
        printf("True\n");
    else
        printf("False\n");

    return 0;
}
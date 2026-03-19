#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int dp[205][20005];

/*
PROBLEM STATEMENT:
LeetCode 416 - Partition Equal Subset Sum

Given an integer array nums, return true if you can partition the array
into two subsets such that the sum of elements in both subsets is equal.
eg. nums = [1, 5, 11, 5] → true (subset1 = [1, 5, 5], subset2 = [11])
--------------------------------------------------

APPROACH (INTUITION):

- Let total sum = S
- If S is odd → cannot divide into two equal parts → return false

- Target becomes: find subset with sum = S/2

- This reduces to SUBSET SUM problem

- State:
    dp[i][sum] = can we achieve 'sum' using elements from index i to n-1

- Choices:
    1) Not take → move to next index
    2) Take → if nums[i] <= sum

- Base case:
    sum == 0 → true
    i == n → false

--------------------------------------------------
*/

/*
MEMOIZATION (Top-Down DP)

Time Complexity: O(n * target)
Space Complexity: O(n * target)
*/

bool solve(int nums[], int i, int n, int sum) {
    // base cases
    if (sum == 0)
        return true;
    if (i == n)
        return false;

    if (dp[i][sum] != -1)
        return dp[i][sum];

    // not take
    bool not_take = solve(nums, i + 1, n, sum);

    // take
    bool take = false;
    if (nums[i] <= sum) {
        take = solve(nums, i + 1, n, sum - nums[i]);
    }

    return dp[i][sum] = (take || not_take);
}
    

bool canPartition(int nums[], int n) {
    int total = 0;

    for (int i = 0; i < n; i++)
        total += nums[i];

    // if odd, not possible
    if (total % 2 != 0)
        return false;

    int target = total / 2;

    memset(dp, -1, sizeof(dp));

    return solve(nums, 0, n, target);
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
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int dp[205][20005];

/*
PROBLEM STATEMENT:
Subset Sum Problem

Given an array nums[] and an integer target,
determine if there exists a subset whose sum equals target.

Example:
nums = [2, 3, 7, 8, 10], target = 11
Output: true (3 + 8 = 11)

--------------------------------------------------

APPROACH (INTUITION):

- At each index i, we have two choices:
    1) Not take → move to next index
    2) Take → if nums[i] <= target

- State:
    dp[i][target] = can we achieve 'target' using elements from i to n-1

- Recurrence:
    not_take = solve(i+1, target)
    take = solve(i+1, target - nums[i])   (if nums[i] <= target)

- Final:
    return take OR not_take

- Base case:
    if target == 0 → return true
    if i == n → return false

--------------------------------------------------
*/

bool subsetSum(int i, int target, int nums[], int n) {
    // base cases
    if (target == 0)
        return true;

    if (i == n)
        return false;

    if (dp[i][target] != -1)
        return dp[i][target];

    // not take
    bool not_take = subsetSum(i + 1, target, nums, n);

    // take
    bool take = false;
    if (nums[i] <= target) {
        take = subsetSum(i + 1, target - nums[i], nums, n);
    }

    return dp[i][target] = (take || not_take);
}

int main() {
    int nums[] = {2, 3, 7, 8, 10};
    int n = 5;
    int target = 11;

    memset(dp, -1, sizeof(dp));

    if (subsetSum(0, target, nums, n))
        printf("True\n");
    else
        printf("False\n");

    return 0;
}
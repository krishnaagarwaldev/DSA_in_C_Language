#include <stdio.h>
#include <string.h>

int dp[205][20005];

/*
PROBLEM STATEMENT:
Count Subsets with Given Sum

Given an array nums[] and a target sum,
count the number of subsets whose sum equals target.

Example:
nums = [1,2,3,3], target = 6
Output: 3
Subsets:
[1,2,3]
[1,2,3] (different 3)
[3,3]

--------------------------------------------------

APPROACH (TAKE / NOT TAKE - MEMOIZATION):

- At each index i:
    1) Not take → move to i+1
    2) Take → if nums[i] <= target

- State:
    dp[i][target] = number of subsets from i → n-1

- Recurrence:
    not_take = solve(i+1, target)
    take = solve(i+1, target - nums[i])

    dp[i][target] = take + not_take

- Base cases:
    if target == 0 → return 1 (valid subset found)
    if i == n → return 0

--------------------------------------------------
*/

int countSubsets(int i, int target, int nums[], int n) {
    // base cases
    if (target == 0)
        return 1;

    if (i == n)
        return 0;

    if (dp[i][target] != -1)
        return dp[i][target];

    // not take
    int not_take = countSubsets(i + 1, target, nums, n);

    // take
    int take = 0;
    if (nums[i] <= target) {
        take = countSubsets(i + 1, target - nums[i], nums, n);
    }

    return dp[i][target] = take + not_take;
}

int main() {
    int nums[] = {1, 2, 3, 3};
    int n = 4;
    int target = 6;

    memset(dp, -1, sizeof(dp));

    printf("Count: %d\n", countSubsets(0, target, nums, n));

    return 0;
}
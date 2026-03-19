#include <stdio.h>
#include <string.h>

/*
PROBLEM STATEMENT:
House Robber I (LeetCode 198)

You are given an array nums where nums[i] represents money in house i.
You cannot rob two adjacent houses.

Return the maximum amount of money you can rob.

--------------------------------------------------

APPROACH (INTUITION):

- At each index i, we have two choices:
    1) Rob → nums[i] + solve(i+2)  (skip next house)
    2) Not rob → solve(i+1)

- State:
    dp[i] = max money from index i to end

- Base case:
    if i >= n → return 0

--------------------------------------------------
*/

int dp1[1000];

int max(int a, int b) {
    return (a > b) ? a : b;
}

int houseRobber1(int i, int nums[], int n) {
    if (i >= n)
        return 0;

    if (dp1[i] != -1)
        return dp1[i];

    int rob = nums[i] + houseRobber1(i + 2, nums, n); // rob current house and skip next
    int not_rob = houseRobber1(i + 1, nums, n); // skip current house and move to next

    return dp1[i] = max(rob, not_rob);
}


int main() {
    int nums1[] = {2, 7, 9, 3, 1};
    int n1 = 5;
    memset(dp1, -1, sizeof(dp1));

    printf("House Robber I: %d\n", houseRobber1(0, nums1, n1));

    return 0;
}
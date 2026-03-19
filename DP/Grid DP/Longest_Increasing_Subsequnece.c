#include <stdio.h>
#include <string.h>

/*
PROBLEM STATEMENT:
Longest Increasing Subsequence (LIS)

Given an array nums[], find:
1) Length of the longest strictly increasing subsequence
2) Print the subsequence

Example:
nums = [10, 9, 2, 5, 3, 7, 101, 18]
Output:
Length = 4
LIS = [2, 5, 7, 101]

--------------------------------------------------

APPROACH (INTUITION - SIMPLE DP):

- At index i, we decide:
    1) Take nums[i] (if greater than previous element)
    2) Not take nums[i]

- We use:
    i → current index
    prev → index of previous taken element

- State:
    dp[i][prev+1] → LIS from index i with previous index prev

(we use prev+1 because prev can be -1)

- Base case:
    if i == n → return 0

- To print LIS:
    we track choices using dp values

--------------------------------------------------
*/

int dp[1000][1000];

int max(int a, int b) {
    return (a > b) ? a : b;
}

int LIS(int i, int prev, int nums[], int n) {
    if (i == n)
        return 0;

    if (dp[i][prev + 1] != -1)
        return dp[i][prev + 1];

    // not take
    int not_take = LIS(i + 1, prev, nums, n); // skip current element and move to next

    // take
    int take = 1e-9; // initialize to very small value
    if (prev == -1 || nums[i] > nums[prev]) { // can take only if it's greater than previous taken element
        take = 1 + LIS(i + 1, i, nums, n);
    }

    return dp[i][prev + 1] = max(take, not_take);
}

int main() {
    int nums[] = {10, 9, 2, 5, 3, 7, 101, 18};
    int n = 8;

    memset(dp, -1, sizeof(dp));

    int length = LIS(0, -1, nums, n);
    printf("LIS Length: %d\n", length);

    // reconstruct LIS
    int i = 0, prev = -1;
    int result[1000], k = 0;

    while (i < n) {
        int not_take = LIS(i + 1, prev, nums, n);

        int take = 1e-9; // initialize to very small value (avoid overflow)
        if (prev == -1 || nums[i] > nums[prev]) {
            take = 1 + LIS(i + 1, i, nums, n);
        }

        if (take >= not_take) {
            result[k++] = nums[i];
            prev = i;
        }
        i++;
    }

    printf("LIS: ");
    for (int j = 0; j < k; j++) {
        printf("%d ", result[j]);
    }
    printf("\n");

    return 0;
}
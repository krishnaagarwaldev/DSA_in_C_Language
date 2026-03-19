#include <stdio.h>
#include <string.h>

/*
PROBLEM STATEMENT:
Target Sum (Subset Sum)

Given an array arr[] of size n and a target sum T,  
find the number of ways to select a subset of elements such that their sum equals T.

--------------------------------------------------

APPROACH (INTUITION):

- At each index i, we have two choices:
    1) Take arr[i] → solve(i+1, T - arr[i])
    2) Not take arr[i] → solve(i+1, T)
- Base cases:
    if T == 0 → 1 (subset sum formed)
    if i == n → 0 (reached end without forming sum)
- Memoize results in dp[i][T] to avoid recomputation
*/

int dp[100][1000];

int targetSum(int i, int T, int n, int arr[]) {
    if (T == 0) return 1;  // exact target reached
    if (i == n) return 0;  // no elements left

    if (dp[i][T] != -1) return dp[i][T];

    int take = 0;
    if (arr[i] <= T){
        take = targetSum(i + 1, T - arr[i], n, arr);  // take current element
    }
    int notTake = targetSum(i + 1, T, n, arr); // skip current element

    return dp[i][T] = take + notTake;
}

int main() {
    // int n, T;
    // scanf("%d %d", &n, &T);

    // int arr[100];
    // for (int i = 0; i < n; i++){
    //     scanf("%d", &arr[i]);
    // }

    int n = 4, T = 6;
    int arr[] = {1, 2, 3, 4};

    memset(dp, -1, sizeof(dp));

    printf("Number of ways to get sum %d: %d\n", T, targetSum(0, T, n, arr));

    return 0;
}
#include <stdio.h>
#include <string.h>
#include <limits.h>

int dp[100][100];

/*
PROBLEM STATEMENT:
Matrix Chain Multiplication (MCM)

Given an array arr[] of size n, where matrix i has dimension:
    arr[i-1] x arr[i]

Find the minimum number of scalar multiplications needed
to multiply the chain of matrices.

Example:
arr = [10, 20, 30, 40]
Matrices:
A1 = 10x20, A2 = 20x30, A3 = 30x40

--------------------------------------------------

APPROACH (INTUITION):

- We try all possible partitions (k) between i and j

- For each partition:
    cost =
        cost of left part  (i → k)
      + cost of right part (k+1 → j)
      + cost of multiplying both results

- Multiplication cost:
    arr[i-1] * arr[k] * arr[j]

- State:
    dp[i][j] = minimum cost to multiply matrices from i to j

- Base case:
    if i == j → single matrix → cost = 0

--------------------------------------------------
*/

int min(int a, int b) {
    return (a < b) ? a : b;
}

// eg. for arr = [10, 20, 30, 40]
//                    i,k      j
// cost = mcm(i, k) + mcm(k+1, j) + arr[i-1] * arr[k] * arr[j] 
int mcm(int i, int j, int arr[]) {
    // base case
    if (i == j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int ans = INT_MAX;
    // try all partitions
    for (int k = i; k < j; k++) {
        int cost =
            mcm(i, k, arr) +
            mcm(k + 1, j, arr) +
            arr[i - 1] * arr[k] * arr[j]; 

        ans = min(ans, cost);
    }
    return dp[i][j] = ans;
}

int main() {
    int arr[] = {10, 20, 30, 40};
    int n = 4;

    memset(dp, -1, sizeof(dp));

    printf("Minimum Multiplication Cost: %d\n", mcm(1, n - 1, arr));

    return 0;
}
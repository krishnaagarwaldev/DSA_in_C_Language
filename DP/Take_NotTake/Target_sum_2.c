#include <stdio.h>
#include <string.h>

int n, arr[20]; // small n for printing
int dp[20][1000];

/*
PROBLEM STATEMENT:
Target Sum (Print All Subsets)

Given an array arr[] of size n and a target sum T,  
print all subsets of arr[] whose sum equals T.

--------------------------------------------------

APPROACH (INTUITION):

- At each index i and remaining sum T:
    1) Take arr[i] → add arr[i] to current subset, solve(i+1, T - arr[i])
    2) Not take arr[i] → skip arr[i], solve(i+1, T)
- Base cases:
    if T == 0 → print current subset (exact target formed)
    if i == n → return (end of array)
- Use a simple array to store the current subset being built
*/

void printSubset(int subset[], int len) {
    printf("{ ");
    for (int i = 0; i < len; i++) printf("%d ", subset[i]);
    printf("}\n");
}

void targetSumPrint(int i, int T, int subset[], int len) {
    if (T == 0) {
        printSubset(subset, len);
        return;
    }
    if (i == n || T < 0) return;

    // Take arr[i]
    subset[len] = arr[i];
    targetSumPrint(i + 1, T - arr[i], subset, len + 1);

    // Not take arr[i]
    targetSumPrint(i + 1, T, subset, len);
}

int main() {
    int T;
    // scanf("%d %d", &n, &T);
    // for (int i = 0; i < n; i++){
    //     scanf("%d", &arr[i]);
    // }
    n = 4; T = 6;
    arr[0] = 1; arr[1] = 2; arr[2] = 3; arr[3] = 4;

    int subset[20]; // to store current subset
    printf("Subsets that sum to %d:\n", T);
    targetSumPrint(0, T, subset, 0);

    return 0;
}
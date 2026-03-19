// Fibonacci with memoization in C
// Time Complexity: O(n)
// Space Complexity: O(n) due to recursion stack and dp array i.e (O(n) for dp + O(n) for recursion stack = O(n))

#include <stdio.h>
#include <string.h>

int dp[100];

int fib(int n) {
    if (n <= 1)
        return n;

    if (dp[n] != -1)
        return dp[n];  // already computed

    dp[n] = fib(n - 1) + fib(n - 2);
    return dp[n];
}

int main() {
    int n = 6; // 0, 1, 1, 2, 3, 5, 8

    // initialize dp array
    // for (int i = 0; i < 100; i++)
    //     dp[i] = -1;

    memset(dp, -1, sizeof(dp));  // set all values to -1

    printf("Fibonacci: %d", fib(n));
    return 0;
}
#include <stdio.h>
#include <string.h>

/*
PROBLEM STATEMENT:
Target Sum (Assign + or - to each number)

Given an array nums[] of size n and a target sum T,  
count the number of ways to assign + or - signs to each element such that the total sum equals T.

--------------------------------------------------

APPROACH (INTUITION):

- At index i, we have two choices:
    1) Add nums[i] → solve(i+1, sum + nums[i])
    2) Subtract nums[i] → solve(i+1, sum - nums[i])
- Base case:
    if i == n:
        if sum == target → return 1
        else → return 0
- Memoize results in dp[i][sum + OFFSET] to handle negative sums
- OFFSET = 1000 (assuming sum of numbers ≤ 1000)

Example 1:

Input: nums = [1,1,1,1,1], target = 3
Output: 5
Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3
*/

int dp[21][2001]; // 20 numbers max, sum range [-1000, 1000]
int nums[20], n, target;
int OFFSET = 1000; // shift negative sums to positive index

int countWays(int i, int sum) {
    if (i == n) {
        return (sum == target) ? 1 : 0;
    }

    if (dp[i][sum + OFFSET] != -1) return dp[i][sum + OFFSET];

    int add = countWays(i + 1, sum + nums[i]);
    int sub = countWays(i + 1, sum - nums[i]);

    return dp[i][sum + OFFSET] = add + sub;
}

int main() {
    // scanf("%d %d", &n, &target);
    // for (int i = 0; i < n; i++){
    //     scanf("%d", &nums[i]);
    // }

    n = 4; target = 3;
    nums[0] = 1; nums[1] = 2; nums[2] = 1; nums[3] = 1; // {1, 2, 1, 1} -> O/p: {-1, 2, 1, 1}, {1, 2, -1, 1}, {1, 2, 1, -1} -> 3

    memset(dp, -1, sizeof(dp));

    printf("Number of ways: %d\n", countWays(0, 0));

    return 0;
}
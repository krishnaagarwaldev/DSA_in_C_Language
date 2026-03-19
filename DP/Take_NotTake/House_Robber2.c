#include <stdio.h>
#include <string.h>

/*
PROBLEM STATEMENT:
House Robber II (LeetCode 213)

Same as House Robber I, but houses are in a CIRCLE.
First and last houses are adjacent → cannot rob both.

--------------------------------------------------

APPROACH (INTUITION):

- Since first and last are adjacent:
    Case 1: Rob from index 0 to n-2
    Case 2: Rob from index 1 to n-1

- Answer = max(case1, case2)

- Use same logic as House Robber I

--------------------------------------------------
*/

int dp2[1000];

int max(int a, int b) {
    return (a > b) ? a : b;
}

int robRange(int i, int nums[], int end) {
    if (i > end)
        return 0;
        
    if (dp2[i] != -1)
        return dp2[i];

    int rob = nums[i] + robRange(i + 2, nums, end); // rob current house and skip next
    int not_rob = robRange(i + 1, nums, end); // skip current house and move to next

    return dp2[i] = max(rob, not_rob);
}

int houseRobber2(int nums[], int n) {
    if (n == 1)
    return nums[0];
    
    int case1 = robRange(0, nums, n - 2); // rob from index 0 to n-2, skip last house because it's adjacent to first
    int case2 = robRange(1, nums, n - 1); // rob from index 1 to n-1, skip first house because it's adjacent to last
    
    return max(case1, case2);
}

int main() {
    int nums2[] = {2, 3, 2};
    int n2 = 3;
    memset(dp2, -1, sizeof(dp2));

    printf("House Robber II: %d\n", houseRobber2(nums2, n2));

    return 0;
}
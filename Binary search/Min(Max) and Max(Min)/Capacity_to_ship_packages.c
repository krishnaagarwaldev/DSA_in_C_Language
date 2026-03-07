/*
Question:
A conveyor belt has packages that must be shipped from one port to another within days days.

The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship with packages on the conveyor belt (in the order given by weights). We may not load more weight than the maximum weight capacity of the ship.

Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.

Example:

Input: weights = [1,2,3,4,5,6,7,8,9,10], days = 5
Output: 15
Explanation: A ship capacity of 15 is the minimum to ship all the packages in 5 days like this:
1st day: 1, 2, 3, 4, 5
2nd day: 6, 7
3rd day: 8
4th day: 9
5th day: 10

Approach:
To find the least weight capacity of the ship, we can use binary search. We set the low and high as the minimum and maximum weight from the weights array, respectively. Then, we iterate through the weights and check if it can be accommodated within the current capacity. If it can, we subtract the weight from the capacity. If it cannot, we increment the required number of days and update the capacity with the current weight. We continue this process until we find the minimum capacity that satisfies the given number of days.

Code:
*/

#include <stdio.h>

/* Check if we can ship within given days using capacity */
int isPossible(int weights[], int n, int days, int capacity) {
    int requiredDays = 1;
    int currentLoad = 0;

    for (int i = 0; i < n; i++) {

        /* If single package exceeds capacity */
        if (weights[i] > capacity)
            return 0;

        if (currentLoad + weights[i] <= capacity) {
            currentLoad += weights[i];
        } else {
            requiredDays++;
            currentLoad = weights[i];

            if (requiredDays > days)
                return 0;
        }
    }

    return 1;
}

int shipWithinDays(int weights[], int n, int days) {

    int low = 0, high = 0;

    /* Define search space */
    for (int i = 0; i < n; i++) {
        if (weights[i] > low)
            low = weights[i];     // max single weight
        high += weights[i];       // sum of weights
    }

    int ans = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (isPossible(weights, n, days, mid)) {
            ans = mid;
            high = mid - 1;   // minimize capacity
        } else {
            low = mid + 1;
        }
    }

    return ans;
}

/* Driver Code */
int main() {
    int weights[] = {1,2,3,4,5,6,7,8,9,10};
    int n = sizeof(weights) / sizeof(weights[0]);
    int days = 5;

    int result = shipWithinDays(weights, n, days);

    printf("Minimum ship capacity: %d\n", result);

    return 0;
}

/*
- Time Complexity: O(N log M), where N is the size of the weights array and M is the sum of all the weights.
- Space Complexity: O(1) as we are using a constant amount of extra space.
*/


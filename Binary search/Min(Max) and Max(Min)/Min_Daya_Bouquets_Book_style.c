#include <stdio.h>
#include <limits.h>

/* 
   Check if we can make m bouquets
   if we wait 'maxDays' days
*/
int isPossible(int arr[], int n, int m, int k, int maxDays) {

    int count = 0;     // bouquets formed
    int flowers = 0;   // consecutive flowers

    for (int i = 0; i < n; i++) {

        if (arr[i] <= maxDays) {
            flowers++;
            if (flowers == k) {
                count++;
                flowers = 0;  // reset after forming bouquet

                if (count >= m)
                    return 1;
            }
        } 
        else {
            flowers = 0;  // adjacency breaks
        }
    }

    return 0;
}


/* Binary Search on Answer */
int minDaysToMakeBouquets(int arr[], int n, int m, int k) {
    if ((long)m * k > n)
        return -1;
    int low = INT_MAX;
    int high = INT_MIN;

    // Define search space
    for (int i = 0; i < n; i++) {
        if (arr[i] < low)
            low = arr[i];
        if (arr[i] > high)
            high = arr[i];
    }

    int ans = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (isPossible(arr, n, m, k, mid)) {
            ans = mid;
            high = mid - 1;   // minimize days
        }
        else {
            low = mid + 1;
        }
    }
    return ans;
}


/* Driver Code */
int main() {

    int bloomDay[] = {1, 10, 3, 10, 2};
    int n = sizeof(bloomDay) / sizeof(bloomDay[0]);

    int m = 3;
    int k = 1;

    int result = minDaysToMakeBouquets(bloomDay, n, m, k);

    printf("Minimum Days: %d\n", result);

    return 0;
}
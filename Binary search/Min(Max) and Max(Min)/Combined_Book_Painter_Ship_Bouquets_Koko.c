/*🧠 Why This Works for All 4

Because all 4 problems mean:

Split array into k contiguous parts
such that the maximum part sum is minimized

Only interpretation changes:

Problem	          k_means
Book Allocation	  students
PainterPartition  painters
Split Array       subarrays
ShipWithinDays    days
*/

/* 
   Generic Binary Search on Answer Template
   - arr[] → input array
   - n     → size
   - k     → number of partitions (students/painters/days)
*/
/*Time Complexity: O(N log M), where N is the size of the array and M is the maximum element in the array
Space Complexity: O(1)*/

/*
Type	            Meaning of mid           Time Complexity
Partition Problems	Maximum allowed load     O(N log(sum))
Koko	            Eating speed per hour    O(N log(maxPile))
*/


#include <stdio.h>

/*
mode meanings:
1 → Book Allocation / Painter / Split Array / Ship
2 → Koko Eating Bananas
*/

int isPossible(int arr[], int n, int k, int limit, int mode) {

    if (mode == 1) {
        // Partition-type problems
        int count = 1;
        int sum = 0;

        for (int i = 0; i < n; i++) {

            if (arr[i] > limit)
                return 0;

            if (sum + arr[i] <= limit) {
                sum += arr[i];
            } else {
                count++;
                sum = arr[i];
                if (count > k)
                    return 0;
            }
        }
        return 1;
    }

    else if (mode == 2) {
        // Koko Eating Bananas
        int hours = 0;

        for (int i = 0; i < n; i++) {
            hours += (arr[i] + limit - 1) / limit;  // ceil division

            if (hours > k)
                return 0;
        }
        return 1;
    }

    return 0;
}


int binarySearchAnswer(int arr[], int n, int k, int mode) {

    int low = 1, high = 0;

    if (mode == 1) {
        // Partition problems
        low = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] > low)
                low = arr[i];
            high += arr[i];
        }
    }

    else if (mode == 2) {
        // Koko
        for (int i = 0; i < n; i++) {
            if (arr[i] > high)
                high = arr[i];
        }
    }

    int ans = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (isPossible(arr, n, k, mid, mode)) {
            ans = mid;
            high = mid - 1;   // minimize
        } else {
            low = mid + 1;
        }
    }

    return ans;
}


/* ================= DRIVER ================= */

int main() {

    // Book Allocation
    int books[] = {12, 34, 67, 90};
    printf("Book Allocation: %d\n",
           binarySearchAnswer(books, 4, 2, 1));

    // Ship Within Days
    int weights[] = {1,2,3,4,5,6,7,8,9,10};
    printf("Ship Within Days: %d\n",
           binarySearchAnswer(weights, 10, 5, 1));

    // Split Array
    int nums[] = {7,2,5,10,8};
    printf("Split Array Largest Sum: %d\n",
           binarySearchAnswer(nums, 5, 2, 1));

    // Koko Eating Bananas
    int piles[] = {3,6,7,11};
    printf("Koko Min Speed: %d\n",
           binarySearchAnswer(piles, 4, 8, 2));

    return 0;
}
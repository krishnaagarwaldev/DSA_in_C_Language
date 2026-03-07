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

#include <stdio.h>

/* 
   Generic isPossible:
   - arr[] → input array
   - n     → size
   - k     → number of partitions (students/painters/days)
   - limit → maximum allowed load per partition
*/
int isPossible(int arr[], int n, int k, int limit) {
    int count = 1;   // at least one partition
    int sum = 0;

    for (int i = 0; i < n; i++) {

        if (arr[i] > limit)
            return 0;   // impossible

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


/*
   Generic Binary Search on Answer
*/
int binarySearchAnswer(int arr[], int n, int k) {

    int low = 0, high = 0;

    // Define search space
    for (int i = 0; i < n; i++) {
        if (arr[i] > low)
            low = arr[i];   // maximum single element
        high += arr[i];     // total sum
    }

    int ans = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (isPossible(arr, n, k, mid)) {
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

    /* Example 1: Book Allocation */
    int books[] = {12, 34, 67, 90};
    int n1 = 4;
    int students = 2;
    printf("Book Allocation: %d\n",
           binarySearchAnswer(books, n1, students));


    /* Example 2: Painter Partition (same input) */
    int painters = 2;
    printf("Painter Partition: %d\n",
           binarySearchAnswer(books, n1, painters));


    /* Example 3: Split Array Largest Sum */
    int nums[] = {7, 2, 5, 10, 8};
    int n2 = 5;
    int k = 2;
    printf("Split Array Largest Sum: %d\n",
           binarySearchAnswer(nums, n2, k));


    /* Example 4: Ship Within Days */
    int weights[] = {1,2,3,4,5,6,7,8,9,10};
    int n3 = 10;
    int days = 5;
    printf("Ship Within Days: %d\n",
           binarySearchAnswer(weights, n3, days));

    return 0;
}
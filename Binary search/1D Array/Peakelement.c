/*
QUESTION:-
A peak element is an element that is strictly greater than its neighbors.

Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.

You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is always considered to be strictly greater than a neighbor that is outside the array.

You must write an algorithm that runs in O(log n) time.

Example 1:
Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.

Example 2:
Input: nums = [1,2,1,3,5,6,4]
Output: 5
Explanation: Your function can return either index number 1 where the peak element is 2, or index number 5 where the peak element is 6.
*/

/*
APPROACH:-
We can use the binary search approach to find the peak element.
1. Initialize low = 0 and high = n-1, where n is the size of the array.
2. While low < high, calculate mid = low + (high - low) / 2.
3. If nums[mid] < nums[mid+1], it means a peak element exists on the right side of mid, so update low = mid+1.
4. Otherwise, a peak element exists on the left side of mid or mid itself is a peak, so update high = mid.
5. After the loop ends, low will be pointing to the peak element index.
6. Return low as the result.

CODE:-
*/

//dry run eg. arr = {10, 20, 15, 2, 23, 90, 67}
// low = 0, high = 6, mid = 3, arr[mid] = 2, arr[mid+1] = 23, therefore low = mid + 1 = 4
// low = 4, high = 6, mid = 5, arr[mid] = 90, arr[mid+1] = 67, therefore high = mid = 5
// low = 4, high = 5, mid = 4, arr[mid] = 23, arr[mid+1] = 90, therefore low = mid + 1 = 5
// low = 5, high = 5, loop terminates, return low = 5

#include <stdio.h>
int findPeak(int arr[], int n) {
    int low = 0, high = n - 1;

    while (low < high) {
        int mid = (low + high) / 2;

        if (arr[mid] < arr[mid + 1])
            low = mid + 1;
        else
            high = mid;
    }
    return low;
}

int findPeak_ans(int arr[], int n)
{
    int low = 0, high = n - 1;
    int ans = -1;

    while(low <= high)
    {
        int mid = low + (high - low) / 2;

        // Check if mid is peak
        int left  = (mid == 0) ? -1000000000 : arr[mid - 1];
        int right = (mid == n - 1) ? -1000000000 : arr[mid + 1];

        if(arr[mid] > left && arr[mid] > right)
        {
            ans = mid;
            return ans;   // peak found
        }
        else if(arr[mid] < right)
        {
            low = mid + 1;   // peak on right
        }
        else
        {
            high = mid - 1;  // peak on left
        }
    }

    return ans;
}


int main() {
    //eg. arr with multiple peaks
    int arr[] = {10, 20, 15, 2, 23, 90, 67}; // local peaks are 20 and 90, global peak is 90
    int n = sizeof(arr) / sizeof(arr[0]);
    int peakIndex = findPeak(arr, n);
    printf("Peak element index: %d\n", peakIndex);

    return 0;
}

// TIME COMPLEXITY: O(log n)
// SPACE COMPLEXITY: O(1)

/*
Question: Given a sorted array arr of positive integers and an integer k, find the kth positive integer that is missing from the array.

Example:
Input: arr = [2,3,4,7,11], k = 5
Output: 9
Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. The 5th missing positive integer is 9.

Approach:
- We can solve this problem by finding the position in the array where the count of missing positive integers becomes greater than or equal to k.
- Initialize a variable `low` to 0 to represent the start of the array.
- Initialize a variable `high` to the size of the array minus 1 to represent the end of the array.
- Initialize a variable `pos` to -1 to store the position of the missing integer.
- Perform a binary search on the array:
  - Calculate the middle index `mid` using the formula `low + (high - low) / 2`.
  - If the count of missing positive integers in the subarray from the start to `mid` is less than k, update `low` to `mid + 1`.
  - Otherwise, update `pos` to `mid` and update `high` to `mid - 1`.
- After the binary search, check if a missing integer was found:
  - If `pos` is still -1, it means that the missing integer should be after the last element in the array. Return the sum of the size of the array and k.
  - Otherwise, return `pos + k` as the kth missing positive integer.

Time Complexity: O(log n), where n is the size of the array.
Space Complexity: O(1)

*/

#include <stdio.h>

//Dry run 
// arr = [2,3,4,7,11], k = 5
// arr_missing = [2->1, 3->1, 4->1, 7->3, 11->6] i.e misssing = arr[i] - (i + 1)
// missing_Arr = [1,5,6,8,9,10,12,13,...]

//arr_missing = [1,1,1,3,6]
// low = 0, high = 4, pos = -1, mid = 2, missing = arr[2] - (2 + 1) = 4 - 3 = 1 < k, low = mid + 1 = 3
// low = 3, high = 4, pos = -1, mid = 3, missing = arr[3] - (3 + 1) = 7 - 4 = 3 < k, low = mid + 1 = 4
// low = 4, high = 4, pos = -1, mid = 4, missing = arr[4] - (4 + 1) = 11 - 5 = 6 >= k, pos = mid = 4, high = mid - 1 = 3
// low = 4, high = 3, pos = 4, return pos + k = 4 + 5 = 9

int findKthPositive(int arr[], int n, int k){
    int low = 0, high = n - 1;
    int pos = -1;

    while(low <= high){
        int mid = low + (high - low) / 2;
        // Number of missing numbers before arr[mid]
        int missing = arr[mid] - (mid + 1);

        if(missing < k){
            low = mid + 1;
        }
        else{
            pos = mid;
            high = mid - 1;
        }
    }
    // If no such position found
    if(pos == -1)
        return n + k; // Missing number is after the last element in the array

    return pos + k; // Missing number is before or at the position found
}

int main()
{
    int arr[] = {2,3,4,7,11};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 5;

    int result = findKthPositive(arr, n, k);

    printf("Kth missing positive number: %d\n", result);

    return 0;
}
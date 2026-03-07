/*
QUESTION:
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

Example:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

APPROACH:
1. Use binary search to find the first occurrence of the target value in the array.
2. Use binary search again to find the last occurrence of the target value in the array.
3. How? If the middle element is equal to the target, update the result and continue searching in the left half for the first occurrence and in the right half for the last occurrence.

CODE:
*/

// TIME COMPLEXITY: O(log n)
// SPACE COMPLEXITY: O(1)


#include <stdio.h>
#include <stdlib.h>

int firstOccurrence(int arr[], int n, int key) {
    int low = 0, high = n - 1, result = -1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == key) {
            result = mid;
            high = mid - 1;
        }
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return result;
}

int lastOccurrence(int arr[], int n, int key) {
    int low = 0, high = n - 1, result = -1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == key) {
            result = mid;
            low = mid + 1;
        }
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return result;
}

int countOccurrences(int arr[], int n, int key) {
    int first = firstOccurrence(arr, n, key);
    if (first == -1)
        return 0;
    int last = lastOccurrence(arr, n, key);
    return last - first + 1;
}

int main() {
    int arr[] = {1, 2, 2, 3, 4, 4, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 4;

    int first = firstOccurrence(arr, n, key);
    int last = lastOccurrence(arr, n, key);
    printf("First occurrence of %d is at index: %d\n", key, first);
    printf("Last occurrence of %d is at index: %d\n", key, last);

    int count = countOccurrences(arr, n, key);
    printf("Element %d occurs %d times in the array.\n", key, count);

    return 0;
}
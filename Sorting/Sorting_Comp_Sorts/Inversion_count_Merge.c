/*Inversion count logic measures the number of pairs in an array where a larger element appears before a smaller one (i.e., i < j but arr[i] > arr[j]).  This count reflects how far an array is from being sorted. 

Brute Force Approach
Logic: Compare every pair (i, j) where i < j. 
Condition: If arr[i] > arr[j], increment inversion count. 

Time Complexity: O(n²) due to nested loops. 
Space Complexity: O(1) — no extra space used.

Optimal Approach Using Merge Sort
Core Idea: Leverage the merge step in Merge Sort to count inversions efficiently.

Why It Works: During merging, when an element from the right half is smaller than an element from the left half, it means all remaining elements in the left half are also greater than the current right element (since both halves are sorted).  Thus, each such comparison contributes (mid - i + 1) inversions.

Key Step in Merge:
if left[i] > right[j]:
    inversion_count += (mid - i + 1)
    temp[k] = right[j]
    j += 1

Time Complexity: O(n log n) — same as merge sort. 
Space Complexity: O(n) — due to temporary array used in merging.*/

#include <stdio.h>

long long merge(int arr[], int temp[], int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = left;
    long long inv_count = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            inv_count += (mid - i + 1);
        }
    }

    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    for (i = left; i <= right; i++)
        arr[i] = temp[i];

    return inv_count;
}

long long mergeSort(int arr[], int temp[], int left, int right) {
    long long inv_count = 0;

    if (left < right) {
        int mid = (left + right) / 2;

        inv_count += mergeSort(arr, temp, left, mid);
        inv_count += mergeSort(arr, temp, mid + 1, right);
        inv_count += merge(arr, temp, left, mid, right);
    }

    return inv_count;
}

int main() {
    int arr[] = {8, 4, 2, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    int temp[n];

    long long result = mergeSort(arr, temp, 0, n-1);

    printf("Inversion Count = %lld\n", result);

    return 0;
}
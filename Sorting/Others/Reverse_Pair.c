/*✅ Optimal Approach: Modified Merge Sort
💡 Idea
Just like:
Count Inversions problem
Merge Sort modification

While merging two sorted halves:

Left half: nums[left...mid]
Right half: nums[mid+1...right]

Since both halves are sorted:
For each element in left half:
Move pointer in right half to count elements where
nums[i] > 2 * nums[j]

Because both halves are sorted, we can count efficiently in O(n) per merge.

⚙️ Algorithm Steps

Divide array using merge sort
Before merging:
Count reverse pairs
Merge normally*/

#include <stdio.h>

#include <stdio.h>

int mergeAndCount(int arr[], int left, int mid, int right) {
    int count = 0;

    // Count reverse pairs using simple loops
    for (int i = left; i <= mid; i++) {
        for (int j = mid + 1; j <= right; j++) {
            if (arr[i] > 2 * arr[j])
                count++;
        }
    }

    // Merge two sorted halves
    int n = right - left + 1;
    int temp[n];
    int i = left, j = mid + 1, k = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }
    while (i <= mid) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];

    for (i = left, k = 0; i <= right; i++, k++)
        arr[i] = temp[k];

    return count;
}

int mergeSortAndCount(int arr[], int left, int right) {
    if (left >= right) return 0;

    int mid = left + (right - left) / 2;
    int count = mergeSortAndCount(arr, left, mid);
    count += mergeSortAndCount(arr, mid + 1, right);
    count += mergeAndCount(arr, left, mid, right);

    return count;
}

int main() {
    int arr[] = {1, 3, 2, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = mergeSortAndCount(arr, 0, n - 1);
    printf("Reverse pairs = %d\n", result);
    return 0;
}

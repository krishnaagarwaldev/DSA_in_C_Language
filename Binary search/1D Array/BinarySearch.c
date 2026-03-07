#include <stdio.h>
#include <stdlib.h>
int binarySearchiterative(int arr[], int n, int key) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int binarySearchrecursive(int arr[], int low, int high, int key) {
    if (low > high)
        return -1;

    int mid = (low + high) / 2;

    if (arr[mid] == key)
        return mid;
    else if (arr[mid] < key)
        return binarySearchrecursive(arr, mid + 1, high, key);
    else
        return binarySearchrecursive(arr, low, mid - 1, key);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 5;

    int iterativeResult = binarySearchiterative(arr, n, key);
    if (iterativeResult != -1)
        printf("Iterative: Element found at index %d\n", iterativeResult);
    else
        printf("Iterative: Element not found\n");

    int recursiveResult = binarySearchrecursive(arr, 0, n - 1, key);
    if (recursiveResult != -1)
        printf("Recursive: Element found at index %d\n", recursiveResult);
    else
        printf("Recursive: Element not found\n");

    return 0;
}   
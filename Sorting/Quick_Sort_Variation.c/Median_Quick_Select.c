#include <stdio.h>

// Standard Lomuto Partition
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    int temp;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

int quickSelect(int arr[], int low, int high, int k) {
    if (low <= high) {
        int pi = partition(arr, low, high);

        if (pi == k)
            return arr[pi];
        else if (pi > k)
            return quickSelect(arr, low, pi - 1, k);
        else
            return quickSelect(arr, pi + 1, high, k);
    }
    return -1;
}

float findMedian(int arr[], int n) {
    if (n % 2 == 1)
        return quickSelect(arr, 0, n - 1, n / 2);
    else {
        int m1 = quickSelect(arr, 0, n - 1, n / 2 - 1);
        int m2 = quickSelect(arr, 0, n - 1, n / 2);
        return (m1 + m2) / 2.0;
    }
}

int main() {
    int arr[] = {7, 10, 4, 3, 20, 15};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Median: %.2f\n", findMedian(arr, n));
    return 0;
}
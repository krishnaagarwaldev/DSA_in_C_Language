#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition_first(int arr[], int lb, int ub) {
    int pivot = arr[lb];
    int start = lb;
    int end = ub;

    while (start < end) {

        while (start <= ub && arr[start] <= pivot)
            start++;

        while (arr[end] > pivot)
            end--;

        if (start < end)
            swap(&arr[start], &arr[end]);
    }

    swap(&arr[lb], &arr[end]);
    return end;
}

void quickSort_first(int arr[], int lb, int ub) {
    if (lb < ub) {
        int loc = partition_first(arr, lb, ub);
        quickSort_first(arr, lb, loc - 1);
        quickSort_first(arr, loc + 1, ub);
    }
}

int main() {
    int arr[] = {7,6,10,5,9,2,1,15,7};
    int n = sizeof(arr)/sizeof(arr[0]);

    quickSort_first(arr, 0, n-1);

    printf("Sorted Array:\n");
    for(int i=0;i<n;i++)
        printf("%d ", arr[i]);

    return 0;
}
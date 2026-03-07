#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition_last(int arr[], int lb, int ub) {
    int pivot = arr[ub];
    int i = lb - 1;

    for(int j = lb; j < ub; j++) {
        if(arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i+1], &arr[ub]);
    return i+1;
}

void quickSort_last(int arr[], int lb, int ub) {
    if(lb < ub) {
        int pi = partition_last(arr, lb, ub);
        quickSort_last(arr, lb, pi-1);
        quickSort_last(arr, pi+1, ub);
    }
}

int main() {
    int arr[] = {4,3,8,4,2,9,1};
    int n = sizeof(arr)/sizeof(arr[0]);

    quickSort_last(arr, 0, n-1);

    for(int i=0;i<n;i++)
        printf("%d ", arr[i]);

    return 0;
}
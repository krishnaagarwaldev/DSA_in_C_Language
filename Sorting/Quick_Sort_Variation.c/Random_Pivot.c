#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
    int t = *a; *a = *b; *b = t;
}

int partition(int arr[], int lb, int ub) {
    int pivot = arr[ub];
    int i = lb - 1;

    for(int j=lb;j<ub;j++) {
        if(arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i+1], &arr[ub]);
    return i+1;
}

int partition_random(int arr[], int lb, int ub) {
    int random = lb + rand() % (ub - lb + 1);
    swap(&arr[random], &arr[ub]);
    return partition(arr, lb, ub);
}

void quickSort_random(int arr[], int lb, int ub) {
    if(lb < ub) {
        int pi = partition_random(arr, lb, ub);
        quickSort_random(arr, lb, pi-1);
        quickSort_random(arr, pi+1, ub);
    }
}

int main() {
    srand(time(NULL));

    int arr[] = {10,7,8,9,1,5};
    int n = sizeof(arr)/sizeof(arr[0]);

    quickSort_random(arr, 0, n-1);

    for(int i=0;i<n;i++)
        printf("%d ", arr[i]);

    return 0;
}
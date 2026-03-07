#include <stdio.h>

void swap(int *a, int *b){
    int t=*a; *a=*b; *b=t;
}

int partition(int arr[], int lb, int ub){
    int pivot = arr[ub];
    int i = lb-1;

    for(int j=lb;j<ub;j++){
        if(arr[j] <= pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[ub]);
    return i+1;
}

int quickSelect(int arr[], int lb, int ub, int k){
    if(lb <= ub){
        int pi = partition(arr, lb, ub);

        if(pi == k)
            return arr[pi];
        else if(pi > k)
            return quickSelect(arr, lb, pi-1, k);
        else
            return quickSelect(arr, pi+1, ub, k);
    }
    return -1;
}

int main(){
    int arr[] = {7,10,4,3,20,15};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 2; // 3rd smallest (0-based index)

    printf("Kth Smallest: %d", quickSelect(arr,0,n-1,k));

    //Kth largest can be found by using k = n-k (0-based index)
    int k_largest = n - k - 1; // 3rd largest (0-based index)
    printf("\nKth Largest: %d", quickSelect(arr,0,n-1,k_largest));
    return 0;
}
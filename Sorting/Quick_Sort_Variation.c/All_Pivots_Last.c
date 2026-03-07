#include<stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* Last Pivot --> Lomuto Partition */
int partition_last(int A[], int lb, int ub){
    int pivot = A[ub];
    int i = lb - 1;

    for(int j = lb; j < ub; j++){
        if(A[j] <= pivot){
            i++;
            swap(&A[i], &A[j]);
        }
    }
    swap(&A[i+1], &A[ub]);
    return i+1;
}

void quickSort_last(int A[], int lb, int ub){
    if(lb < ub){
        int loc = partition_last(A, lb, ub);
        quickSort_last(A, lb, loc-1);
        quickSort_last(A, loc+1, ub);
    }
}


/* First Pivot --> Hoare Partition */
int partition_first(int A[], int lb, int ub){
    int pivot = A[lb];
    int start = lb;
    int end = ub;

    while(start < end){
        while(start <= ub && A[start] <= pivot)
            start++;

        while(A[end] > pivot)
            end--;

        if(start < end)
            swap(&A[start], &A[end]);
    }
    swap(&A[lb], &A[end]);
    return end;
}

void quickSort_first(int A[], int lb, int ub){
    if(lb < ub){
        int loc = partition_first(A, lb, ub);
        quickSort_first(A, lb, loc-1);
        quickSort_first(A, loc+1, ub);
    }
}



/* Pivot ---> Middle Pivot */
int partition_middle(int A[], int lb, int ub){
    int mid = (lb + ub) / 2;
    swap(&A[mid], &A[ub]);   // Move middle to last
    return partition_last(A, lb, ub);
}

void quickSort_middle(int A[], int lb, int ub){
    if(lb < ub){
        int loc = partition_middle(A, lb, ub);
        quickSort_middle(A, lb, loc-1);
        quickSort_middle(A, loc+1, ub);
    }
}



/* Pivot ---> Random Pivot */
#include <stdlib.h>
#include <time.h>

int partition_random(int A[], int lb, int ub){
    int randomIndex = lb + rand() % (ub - lb + 1);
    swap(&A[randomIndex], &A[ub]);
    return partition_last(A, lb, ub);
}

void quickSort_random(int A[], int lb, int ub){
    if(lb < ub){
        int loc = partition_random(A, lb, ub);
        quickSort_random(A, lb, loc-1);
        quickSort_random(A, loc+1, ub);
    }
}



/* Pivot ---> Median of Three */
int median_of_three(int A[], int lb, int ub){
    int mid = (lb + ub) / 2;

    if(A[lb] > A[mid])
        swap(&A[lb], &A[mid]);

    if(A[lb] > A[ub])
        swap(&A[lb], &A[ub]);

    if(A[mid] > A[ub])
        swap(&A[mid], &A[ub]);

    return mid;
}

int partition_median3(int A[], int lb, int ub){
    int medianIndex = median_of_three(A, lb, ub);
    swap(&A[medianIndex], &A[ub]);
    return partition_last(A, lb, ub);
}

void quickSort_median3(int A[], int lb, int ub){
    if(lb < ub){
        int loc = partition_median3(A, lb, ub);
        quickSort_median3(A, lb, loc-1);
        quickSort_median3(A, loc+1, ub);
    }
}



/**/
int findMedian(int A[], int n){
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
            if(A[i] > A[j])
                swap(&A[i], &A[j]);
    return A[n/2];
}

int medianOfMedians(int A[], int lb, int ub){
    int n = ub - lb + 1;
    if(n <= 5)
        return findMedian(A + lb, n);

    int medians[(n+4)/5];
    int i;
    for(i=0;i<n/5;i++)
        medians[i] = findMedian(A + lb + i*5, 5);

    if(n % 5){
        medians[i] = findMedian(A + lb + i*5, n%5);
        i++;
    }
    return medianOfMedians(medians, 0, i-1);
}

int partition_medianOfMedians(int A[], int lb, int ub){
    int pivotValue = medianOfMedians(A, lb, ub);

    int pivotIndex;
    for(pivotIndex = lb; pivotIndex <= ub; pivotIndex++)
        if(A[pivotIndex] == pivotValue)
            break;

    swap(&A[pivotIndex], &A[ub]);
    return partition_last(A, lb, ub);
}

void quickSort_medianOfMedians(int A[], int lb, int ub){
    if(lb < ub){
        int loc = partition_medianOfMedians(A, lb, ub);
        quickSort_medianOfMedians(A, lb, loc-1);
        quickSort_medianOfMedians(A, loc+1, ub);
    }
}



int main(){
    int A[] = {7,6,10,5,9,2,1,15,7};
    int n = sizeof(A)/sizeof(A[0]);

    quickSort_last(A, 0, n-1);  
    quickSort_first(A, 0, n-1);
    quickSort_middle(A, 0, n-1);
    quickSort_random(A, 0, n-1);
    quickSort_median3(A, 0, n-1);
    quickSort_medianOfMedians(A, 0, n-1);

    for(int i=0;i<n;i++)
        printf("%d ", A[i]);

    return 0;
}
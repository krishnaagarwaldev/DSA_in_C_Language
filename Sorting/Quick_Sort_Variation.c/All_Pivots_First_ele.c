/*
int pivotChoice = 1; // first
int pivotChoice = 2; // last
int pivotChoice = 3; // middle
int pivotChoice = 4; // random
int pivotChoice = 5; // median of three
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* ---------------- PIVOT SELECTION FUNCTION ---------------- */

int choosePivot(int A[], int lb, int ub, int type)
{
    if(type == 1)        // First element
        return lb;

    if(type == 2)        // Last element
        return ub;

    if(type == 3)        // Middle element
        return lb + (ub - lb) / 2;

    if(type == 4)        // Random element
        return lb + rand() % (ub - lb + 1);

    if(type == 5)        // Median of Three
    {
        int mid = lb + (ub - lb) / 2;

        if(A[lb] > A[mid]) swap(&A[lb], &A[mid]);
        if(A[lb] > A[ub])  swap(&A[lb], &A[ub]);
        if(A[mid] > A[ub]) swap(&A[mid], &A[ub]);

        return mid;  // Now A[mid] contains median
    }

    return lb; // default
}

/* ---------------- PARTITION FUNCTION ---------------- */

int partition(int A[], int lb, int ub, int pivotType)
{
    int pivotIndex = choosePivot(A, lb, ub, pivotType);

    // Move pivot to first position
    swap(&A[lb], &A[pivotIndex]);

    int pivot = A[lb];
    int start = lb;
    int end = ub;

    while(start < end)
    {
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

/* ---------------- QUICK SORT ---------------- */

void quickSort(int A[], int lb, int ub, int pivotType)
{
    if(lb < ub)
    {
        int loc = partition(A, lb, ub, pivotType);
        quickSort(A, lb, loc-1, pivotType);
        quickSort(A, loc+1, ub, pivotType);
    }
}

/* ---------------- MAIN ---------------- */

int main()
{
    srand(time(NULL));

    int A[] = {7, 6, 10, 5, 9, 2, 1, 15};
    int n = sizeof(A)/sizeof(A[0]);

    int pivotChoice = 5;  // Change this (1-5)

    quickSort(A, 0, n-1, pivotChoice);

    printf("Sorted Array:\n");
    for(int i=0; i<n; i++)
        printf("%d ", A[i]);

    return 0;
}
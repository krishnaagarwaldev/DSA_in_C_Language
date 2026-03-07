#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* =======================
   1. Compare Function for qsort
   ======================= */

int compare(const void *a, const void *b)
{
    int x = *(int *)a;
    int y = *(int *)b;

    return x - y;   // ascending order
}


/* =======================
   2. Find Maximum in Array
   ======================= */

int findMax(int arr[], int n)
{
    int max = arr[0];

    for(int i = 1; i < n; i++)
    {
        if(arr[i] > max)
            max = arr[i];
    }

    return max;
}


/* =======================
   3. Find Minimum in Array
   ======================= */

int findMin(int arr[], int n)
{
    int min = arr[0];

    for(int i = 1; i < n; i++)
    {
        if(arr[i] < min)
            min = arr[i];
    }

    return min;
}


/* =======================
   4. Sum of Array
   ======================= */

int findSum(int arr[], int n)
{
    int sum = 0;

    for(int i = 0; i < n; i++)
        sum += arr[i];

    return sum;
}


/* =======================
   5. Binary Search Template
   ======================= */

int binarySearch(int arr[], int n, int key)
{
    int low = 0, high = n - 1;

    while(low <= high)
    {
        int mid = low + (high - low) / 2;

        if(arr[mid] == key)
            return mid;

        else if(arr[mid] < key)
            low = mid + 1;

        else
            high = mid - 1;
    }

    return -1;  // not found
}


/* =======================
   6. Lower Bound (First >= key)
   ======================= */

int lowerBound(int arr[], int n, int key)
{
    int low = 0, high = n - 1;
    int ans = n;

    while(low <= high)
    {
        int mid = low + (high - low) / 2;

        if(arr[mid] >= key)
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }

    return ans;
}


/* =======================
   7. Upper Bound (First > key)
   ======================= */

int upperBound(int arr[], int n, int key)
{
    int low = 0, high = n - 1;
    int ans = n;

    while(low <= high)
    {
        int mid = low + (high - low) / 2;

        if(arr[mid] > key)
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }

    return ans;
}


/* =======================
   8. Main Function
   ======================= */

int main()
{
    int arr[] = {5, 2, 9, 1, 7};
    int n = 5;

    /* Sorting using qsort */
    qsort(arr, n, sizeof(int), compare);

    printf("Sorted array: ");
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n");

    /* Max and Min */
    printf("Max = %d\n", findMax(arr, n));
    printf("Min = %d\n", findMin(arr, n));

    /* Sum */
    printf("Sum = %d\n", findSum(arr, n));

    /* pow example */
    printf("2^5 = %.0lf\n", pow(2, 5));

    /* abs example */
    printf("Absolute value of -10 = %d\n", abs(-10));

    /* Binary Search */
    int key = 7;
    int index = binarySearch(arr, n, key);

    if(index != -1)
        printf("Found %d at index %d\n", key, index);
    else
        printf("Not Found\n");

    /* Lower and Upper Bound */
    printf("Lower Bound of 7 = %d\n", lowerBound(arr, n, 7));
    printf("Upper Bound of 7 = %d\n", upperBound(arr, n, 7));

    return 0;
}
/*Given an array of time intervals where arr[i] = [starti, endi], our task is to merge all the overlapping intervals into one and output the result which should have only mutually exclusive intervals.

Examples:

Input: arr[] = [[1, 3], [2, 4], [6, 8], [9, 10]]
Output: [[1, 4], [6, 8], [9, 10]]
Explanation: In the given intervals, we have only two overlapping intervals [1, 3] and [2, 4]. Therefore, we will merge these two and return [[1, 4]], [6, 8], [9, 10]].

Input: arr[] = [[7, 8], [1, 5], [2, 4], [4, 6]]
Output: [[1, 6], [7, 8]]
Explanation: We will merge the overlapping intervals [[1, 5], [2, 4], [4, 6]] into a single interval [1, 6].


#include <stdio.h>
#include <stdlib.h>

// Structure for interval
struct Interval {
    int start;
    int end;
};

// Comparator function for sorting by start time
int compare(const void *a, const void *b)
{
    struct Interval *i1 = (struct Interval *)a;
    struct Interval *i2 = (struct Interval *)b;
    return i1->start - i2->start;
}

void mergeIntervals(struct Interval arr[], int n)
{
    if(n <= 0) return;

    // Step 1: Sort intervals by start
    qsort(arr, n, sizeof(struct Interval), compare);

    // Step 2: Merge
    int index = 0;  // Points to last merged interval

    for(int i = 1; i < n; i++)
    {
        // If overlapping
        if(arr[index].end >= arr[i].start)
        {
            // Merge
            if(arr[i].end > arr[index].end)
                arr[index].end = arr[i].end;
        }
        else
        {
            // Move to next interval
            index++;
            arr[index] = arr[i];
        }
    }

    // Print merged intervals
    printf("Merged Intervals:\n");
    for(int i = 0; i <= index; i++)
        printf("[%d, %d] ", arr[i].start, arr[i].end);
}

int main()
{
    struct Interval arr[] = {{1,3}, {2,4}, {6,8}, {9,10}};
    int n = sizeof(arr)/sizeof(arr[0]);

    mergeIntervals(arr, n);

    return 0;
}*/

#include <stdio.h>

// Structure
struct Interval {
    int start;
    int end;
};

// Swap function
void swap(struct Interval *a, struct Interval *b)
{
    struct Interval temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function (Quick Sort)
int partition(struct Interval arr[], int low, int high)
{
    int pivot = arr[high].start;
    int i = low - 1;

    for(int j = low; j < high; j++)
    {
        if(arr[j].start < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i+1], &arr[high]);
    return i + 1;
}

// Quick Sort
void quickSort(struct Interval arr[], int low, int high)
{
    if(low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Merge Overlapping Intervals
void mergeIntervals(struct Interval arr[], int n)
{
    quickSort(arr, 0, n - 1);

    int index = 0;

    for(int i = 1; i < n; i++)
    {
        if(arr[index].end >= arr[i].start)
        {
            if(arr[i].end > arr[index].end)
                arr[index].end = arr[i].end;
        }
        else
        {
            index++;
            arr[index] = arr[i];
        }
    }

    printf("Merged Intervals:\n");
    for(int i = 0; i <= index; i++)
        printf("[%d,%d] ", arr[i].start, arr[i].end);
}

int main()
{
    struct Interval arr[] = {{1,3}, {2,4}, {6,8}, {9,10}};
    int n = sizeof(arr)/sizeof(arr[0]);

    mergeIntervals(arr, n);

    return 0;
}
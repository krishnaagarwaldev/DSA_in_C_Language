#include <stdio.h>

// Swap two integers
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition based on frequency (descending)
int partition(int values[], int freq[], int low, int high)
{
    int pivot = freq[high];
    int i = low;

    for(int j = low; j < high; j++)
    {
        if(freq[j] > pivot)   // Higher frequency first
        {
            swap(&freq[i], &freq[j]);
            swap(&values[i], &values[j]);
            i++;
        }
    }

    swap(&freq[i], &freq[high]);
    swap(&values[i], &values[high]);

    return i;
}

// Quick Select
void quickSelect(int values[], int freq[], int low, int high, int k)
{
    if(low < high)
    {
        int pi = partition(values, freq, low, high);

        if(pi == k)
            return;
        else if(pi > k)
            quickSelect(values, freq, low, pi - 1, k);
        else
            quickSelect(values, freq, pi + 1, high, k);
    }
}

int main()
{
    int nums[] = {1,1,1,2,2,3};
    int n = sizeof(nums)/sizeof(nums[0]);
    int k = 2;

    int values[n];  // unique values
    int freq[n];    // frequency
    int unique = 0;

    // Count frequencies (no struct, simple method)
    for(int i = 0; i < n; i++)
    {
        int found = -1;

        for(int j = 0; j < unique; j++)
        {
            if(values[j] == nums[i])
            {
                found = j;
                break;
            }
        }

        if(found == -1)
        {
            values[unique] = nums[i];
            freq[unique] = 1;
            unique++;
        }
        else
        {
            freq[found]++;
        }
    }

    // Apply Quick Select to get top k
    quickSelect(values, freq, 0, unique - 1, k);

    printf("Top %d frequent elements:\n", k);
    for(int i = 0; i < k; i++)
        printf("%d ", values[i]);

    return 0;
}
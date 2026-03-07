#include <stdio.h>
#include <stdlib.h>

struct Element {
    int value;
    int freq;
};

// Comparator for qsort
int compare(const void *a, const void *b)
{
    struct Element *e1 = (struct Element *)a;
    struct Element *e2 = (struct Element *)b;

    // Sort by frequency (descending)
    if (e1->freq != e2->freq)
        return e2->freq - e1->freq;

    // If frequencies are equal, sort by value (ascending)
    return e1->value - e2->value;
}

int main()
{
    int arr[] = {5, 5, 4, 6, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    struct Element temp[n];
    int uniqueCount = 0;

    // Count frequencies
    for (int i = 0; i < n; i++)
    {
        int found = 0;

        // Check if already counted
        for (int j = 0; j < uniqueCount; j++)
        {
            if (temp[j].value == arr[i])
            {
                temp[j].freq++;
                found = 1;
                break;
            }
        }

        // If new element
        if (!found)
        {
            temp[uniqueCount].value = arr[i];
            temp[uniqueCount].freq = 1;
            uniqueCount++;
        }
    }

    // Sort by frequency and value
    qsort(temp, uniqueCount, sizeof(struct Element), compare);

    // Print sorted result
    printf("Sorted by frequency:\n");
    for (int i = 0; i < uniqueCount; i++)
    {
        for (int j = 0; j < temp[i].freq; j++)
        {
            printf("%d ", temp[i].value);
        }
    }

    return 0;
}
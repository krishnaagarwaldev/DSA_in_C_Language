// qsort(base_address, number_of_elements, size_of_each_element, comparator_function);
// Comparator function should return a negative value if the first argument is less than the second, zero if they are equal, and a positive value if the first argument is greater than the second.
/*
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);   // ascending
}
*/ 
/*
✅ Approach

Create struct with start & finish
Sort by finish time (ascending)
Pick first activity
Pick next activity if start ≥ last finish
*/

#include <stdio.h>
#include <stdlib.h>

struct Activity {
    int start;
    int finish;
};

// Sort by finish time ascending
int compare(const void *a, const void *b) {
    struct Activity *a1 = (struct Activity *)a;
    struct Activity *a2 = (struct Activity *)b;

    return a1->finish - a2->finish;
}

int main() {
    int n = 6;

    struct Activity act[] = {
        {1,2}, {3,4}, {0,6},
        {5,7}, {8,9}, {5,9}
    };

    // Step 1: Sort by finish time
    qsort(act, n, sizeof(struct Activity), compare);

    printf("Selected Activities:\n");

    // Step 2: Select first activity
    int i = 0;
    printf("(%d, %d)\n", act[i].start, act[i].finish);

    // Step 3: Select compatible activities
    for(int j = 1; j < n; j++) {
        if(act[j].start >= act[i].finish) {
            printf("(%d, %d)\n", act[j].start, act[j].finish);
            i = j;
        }
    }

    return 0;
}